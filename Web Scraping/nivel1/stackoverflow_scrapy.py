from scrapy.item import Field, Item
from scrapy.spiders import Spider
from scrapy.selector import Selector
from scrapy.loader import ItemLoader


# Definimos la clase Pregunta que hereda de Item
class Pregunta(Item):
    id = Field()
    pregunta = Field()
    description = Field()


# Definimos la clase StackOverflowSpider que hereda de Spider
class StackOverflowSpider(Spider):
    name = "MiPrimerSpider"  # Nombre del Spider
    custom_settings = {
        "USER_AGENT": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Ubuntu Chromium/71.0.3578.80 Chrome/71.0.3578.80 Safari/537.36"
    }

    # Definimos la URL inicial para comenzar a hacer el scraping
    start_urls = ['https://stackoverflow.com/questions']

    # Parsea la respuesta para extraer los datos (Scrapy)
    def parse(self, response):
        sel = Selector(response)  # Selector
        preguntas = sel.xpath('//div[@id="questions"]//div[@class="s-post-summary"]')  # preguntas
        i = 0
        for pregunta in preguntas:
            item = ItemLoader(Pregunta(), pregunta)  # Cargador de Items
            item.add_xpath('pregunta', './/h3/a/text()')
            item.add_xpath('description', './/div[@class="s-post-summary--content-excerpt"]/text()')
            item.add_value('id', i)
            i += 1
            yield item.load_item()

# Correr el script de scrapy
# scrapy runspider stackoverflow_scrapy.py -o datos.csv -t csv
