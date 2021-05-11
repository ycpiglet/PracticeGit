import cv2
import numpy as np
import time


def make_coordinates(img, line_parameters):
    slope, intercept = line_parameters

    y1 = img.shape[0]
    y2 = int(y1 * (1/2))

    x1 = int((y1 - intercept)/slope)
    x2 = int((y2 - intercept)/slope)

    return np.array([x1, y1, x2, y2])


def average_slope_intercept(img, lines):

    left_fit = []
    right_fit = []

    for line in lines:
        x1, y1, x2, y2 = line.reshape(4)

        x = np.array([x1, x2])
        y = np.array([y1, y2])
        A = np.vstack([x, np.ones(len(x))]).T

        slope, intercept = np.linalg.lstsq(A, y, rcond=None)[0]

        x_coord = -((intercept-640) / slope)

        if x_coord < 400:
            left_fit.append((slope, intercept))

        elif x_coord > 400:
            right_fit.append((slope, intercept))

    left_fit_average = np.mean(left_fit, 0)
    right_fit_average = np.mean(right_fit, 0)

    try:
        left_line = make_coordinates(img, left_fit_average)
        right_line = make_coordinates(img, right_fit_average)

    except:
        left_line = 0
        right_line = 0
        pass

    return [left_line], [right_line]


def display_lines(img, lines):
    line_image = np.zeros_like(img)

    if lines is not None:
        for line in lines:
            x1, y1, x2, y2 = line.reshape(4)
            cv2.line(line_image, (x1, y1), (x2, y2), (255, 0, 0), 20)

    return line_image


def make_canny(img):
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    _, binary = cv2.threshold(gray, 190, 255, cv2.THRESH_BINARY)
    binary_gaussian = cv2.adaptiveThreshold(binary, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY_INV, 11, 5)
    blur = cv2.GaussianBlur(binary_gaussian, (5, 5), 0)
    blur = cv2.bilateralFilter(blur, 9, 75, 75)

    canny_image = cv2.Canny(blur, 80, 120)

    return canny_image


## 메인 프로그램 시작

## 비디오화일 열기 ##
cap = cv2.VideoCapture(0)
last_time = time.time()

## 차선의 평면화 작업
h = 640
w = 800
pts1 = np.float32([[300, 650], [580, 460], [720, 460], [1100, 650]])
pts2 = np.float32([[200, 640], [200, 0], [600, 0], [600, 640]])
M = cv2.getPerspectiveTransform(pts1, pts2)

## 그림자에 대한 차선인식 실패에 대한 임시 저장
l1 = 0
l2 = 0
l1_copy = None
l2_copy = None

x2_coord_average = 400

while True:
    ret, frame = cap.read()
    #cv2.imshow("asdf", frame)
    img2 = cv2.warpPerspective(frame, M, (w, h))

    try:
        canny = make_canny(img2)
        lines = cv2.HoughLinesP(canny, 3, np.pi/180, 100, np.array([]), 100, 400)
        print(len(lines))

        if l1 == 0 and l2 == 0:
            l1, l2 = average_slope_intercept(canny, lines)
        else:
            l1_copy, l2_copy = average_slope_intercept(canny, lines)

        if l1_copy is not None:
            try:
                if l1_copy[0][0] > l1[0][0] + 20 or l1_copy[0][0] < l1[0][0] - 20:
                    l1 = l1
                else:
                    l1 = l1_copy

                if l2_copy is not None:
                    if l2_copy[0][0] > l2[0][0] + 20 or l2_copy[0][0] < l2[0][0] - 20:
                        l2 = l2
                    else:
                        l2 = l2_copy

            except:
                pass

        elif l1_copy is None:
            try:
                if l2_copy is not None:
                    if l2_copy[0][0] > l2[0][0] + 20 or l2_copy[0][0] < l2[0][0] - 20:
                        l2 = l2
                    else:
                        l2 = l2_copy

            except:
                pass

        x2_coord_average = (l2[0][2] + l1[0][2]) / 2

        turning_rate = x2_coord_average - 400

        if turning_rate < -10:
            print("left")
        elif turning_rate > 10:
            print("right")
        else:
            print("straight")

        left_line_image = display_lines(img2, np.array(l1))
        right_line_image = display_lines(img2, np.array(l2))

        line_image = cv2.addWeighted(left_line_image, 1, right_line_image, 1, 1)

        combo_image = cv2.addWeighted(img2, 1, line_image, 0.6, 1)

        print('Frame took{}'.format(time.time() - last_time))
        last_time = time.time()

        cv2.imshow('result', combo_image)
        cv2.imshow('Original', frame)

    except:
        pass

    if cv2.waitKey(60) & 0xFF == 27:
        break


cap.release()
cv2.destroyAllWondows()