import PySimpleGUI as sg
from urllib.request import urlopen
from bs4 import BeautifulSoup


def search_naver(word):
    try:
        url = "https://en.dict.naver.com/search.nhn?sLn=kr&dicQuery=" + word + "&query=" + word + "&target=endic&ie=utf8&query_utf=&isOnlyViewEE=N"
        result = urlopen(url)
        html = result.read()
        soup = BeautifulSoup(html, 'html.parser')
        text = soup.find_all('div', attrs={"class": "align_right"})
        text = text[0].find_all('p')[0].text

        search_result = text.replace("\n", " ")

    except Exception as e:
        search_result = e

    return search_result


def search_wiki(word):
    try:
        url = "https://ko.wikipedia.org/wiki/" + word
        result = urlopen(url)
        html = result.read()
        soup = BeautifulSoup(html, 'html.parser')

        search_result = soup.find_all('p')[1].text

    except Exception as e:
        search_result = e

    return search_result


layout = [[sg.Text('안녕하세요. 만능사전입니다. 검색을 원하는 단어를 입력해주세요.', font=('Helvetica', 14))],
          [sg.Text('검색어 입력', font=('Helvetica', 14)), sg.InputText(font=('Helvetica', 14))],
          [sg.Text('네이버 사전', font=('Helvetica', 14))],
          [sg.Multiline(size=(20, 10), font=('Helvetica', 14))],
          [sg.Text('위키피디아', font=('Helvetica', 14))],
          [sg.Text(text='', key='_WIKI_', size=(20, 10), font=('Helvetica', 10))],
          [sg.Multiline( size=(20, 10), font=('Helvetica', 14))],
          [sg.Ok(font=('Helvetica', 14)), sg.Cancel(font=('Helvetica', 14))]]

# 화면 만들기
window = sg.Window('만능사전', layout)

# 이벤트 루프
while True:
    event, values = window.Read()

    if event in (None, 'Cancel'):
        break
    elif event == 'OK':
        result_naver = search_naver(values[0])
        result_wiki = search_wiki(values[0])

        window.Element('_NAVER_').Update(result_naver)
        window.Element('_WIKI_').Update(result_wiki)

window.Close()
