from urllib.request import urlopen # 대상 url과 소켓 통신을 할 수 있도록 자동 연결
from urllib.parse import quote # 한글 텍트스를 그대로 입력하면 오류가 발생
from bs4 import BeautifulSoup as bs
import urllib

keyword = "개" # 검색한 문자. 문자는 그대로 입력이 안 됨
url = "https://search.naver.com/search.naver?where=image&sm=tab_jum&query=" + quote(keyword) # quote는 퍼센트인코딩함수

result = urlopen(url)
result_html = result.read()
result_soup = bs(result_html, 'html.parser')

img_tag = result_soup.find_all("img")
image_url = img_tag[4]["data-source"]



# url = 'https://search.pstatic.net/common/?src=http%3A%2F%2Fblogfiles.naver.net%2FMjAyMTAzMTlfMjk3%2FMDAxNjE2MDg1MjU1MTcy.6MHQONibf2X4H7Egd335cPc-3_1hXbO99IxMeK5qIKcg.op8o0P_cfd3i2QUttqaArb_Vwrhp5Sfy5Op2mhsSN6Ug.JPEG.simmotto%2F20210126%25A3%25DF172934.jpg&type=ofullfill340_600'
# urllib.request.urlretrieve(url, 'downloads/dog.jpg')

for i in range(4, 54):
    try:
        image_url = img_tag[i]["data-source"]
        urllib.request.urlretrieve(image_url, 'downloads/dog_{}.jpg'.format(i))
    except Exception as e:
        print(i, end=", ")
        print(e)

print("Image Crawling is done")