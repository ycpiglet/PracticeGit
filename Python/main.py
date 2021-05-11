import numpy as np
import cv2

image = cv2.imread("E:\samples\image/sample8.jpg", cv2.IMREAD_UNCHANGED)
cv2.imshow("banana", image)
cv2.waitKey(0)
cv2.destroyAllWindows()
