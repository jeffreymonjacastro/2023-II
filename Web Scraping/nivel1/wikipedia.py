import requests
from lxml import html

# User Agent para protegernos de baneos
encabezados = {
    "user-agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Ubuntu Chromium/71.0.3578.80 Chrome/71.0.3578.80 Safari/537.36"
}

url = "https://www.wikipedia.org/"

response = requests.get(url, headers=encabezados)

# print(response.text)

parser = html.fromstring(response.text)

# Usando las funciones de lxml
# ingles = parser.get_element_by_id("js-link-box-en")
# print(ingles.text_content())

# usando xpath para extraer ingles
# ingles = parser.xpath("//a[@id='js-link-box-en']/strong/text()")
# print(ingles)

# usando xpath para extraer todos los idiomas
idiomas = parser.xpath("//div[contains(@class, 'central-featured-lang')]//strong/text()")

for idioma in idiomas:
    print(idioma)

# usando funciones de lxml
idiomas = parser.find_class("central-featured-lang")

for idioma in idiomas:
    print(idioma.text_content())