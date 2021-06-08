# import openpyxl
from openpyxl import Workbook

wb = Workbook()
ws = wb.active

ws['A1'] = 'Data'

wb.save('result.xlsx')