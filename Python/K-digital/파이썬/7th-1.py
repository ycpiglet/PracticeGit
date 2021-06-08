emp = []

emp.append({'name':'taewha', 'age':30, 'position':'manager'})
emp.append({'name':'yongseong', 'age':28, 'position':'intern'})
emp.append({'name':'jungen', 'age':32, 'position':'ceo'})

print(emp)

count = 0

for person in emp:
    if person['position'] == 'ceo':
        continue

    if person['age'] >= 30:
        count += 1

print(count)