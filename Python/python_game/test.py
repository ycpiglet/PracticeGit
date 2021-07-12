import tkinter

root = tkinter.Tk()
root.title("background")
root.geometry("600x400")
canvas = tkinter.Canvas(width=300, height=100, bg='white')
canvas.pack()
frame = tkinter.Frame(root)
frame.pack()
l1 = tkinter.Label(frame, text='달러', font='helvetica 16 italic')
l1.pack()
b2 = tkinter.Button(frame, text='원->달러')
b2.pack()

root.mainloop()