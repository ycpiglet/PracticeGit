from tkinter import *
window = Tk()

def change_img():
    path = inputBox.get() #엔트리에서 문자열을 읽어서 path 변수에 넣는다.
    img = PhotoImage(file=path) #새로운 PhotoImage 객체 생성(img 변수에 넣는다)
    imageLabel.configure(image = img)
    imageLabel.image = img

photo = PhotoImage(file='우주소녀.gif')

imageLabel = Label(window, image=photo)
imageLabel.pack() # Label 위젯을 만들 때 text와 image를 지정할 수 있다.
# Entry(window).pack()
inputBox = Entry(window)
inputBox.pack()
Button(window, text='클릭', command=change_img).pack()

window.mainloop()