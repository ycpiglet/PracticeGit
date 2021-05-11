import PySimpleGUI as sg

layout = [ [sg.Text('Hi, it is a Dictionary')], [sg.Text('Search'), sg.InputText()], [sg.Ok(), sg.Cancel()]]

window = sg.Window('Dic', layout)


while True:
    event, values = window.Read()
    if event in (None, 'Cancel'):
        break

window.Close()