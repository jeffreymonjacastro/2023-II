import requests
from bs4 import BeautifulSoup

headers = {
    "user-agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Ubuntu Chromium/71.0.3578.80 Chrome/71.0.3578.80 Safari/537.36"
}

url = "https://stackoverflow.com/questions"

response = requests.get(url, headers=headers)

soup = BeautifulSoup(response.text, features="lxml")

# print(soup)

# Encuentra el contenedor de las preguntas
questions = soup.find(id="questions")

# Encuentra cada una de las preguntas, a través de la clase "s-post-summary"
question_list = questions.find_all('div', class_="s-post-summary")

## Usando las clases
# Recorre cada una de las preguntas de la lista
for question in question_list:
    # Encuentra el título de la pregunta
    question_text = question.find('h3').text
    # Encuentra la descripción de la pregunta
    question_description = question.find(class_='s-post-summary--content-excerpt').text
    # Limpia la descripción de la pregunta
    question_description = question_description.replace('\n', '').replace('\r', '').strip()

    print(question_text, end='')
    print(question_description)

    print()

## Usando next siblings

# for question in question_list:
#     elem_question_text = question.find('h3')
#     question_text = elem_question_text.text
#
#     # Encuentra la descripción de la pregunta con next_sibling
#     question_description = elem_question_text.find_next_sibling('div').text
#     question_description = question_description.replace('\n', '').replace('\r', '').strip()
#
#     print(question_text, end='')
#     print(question_description)
#
#     print()


