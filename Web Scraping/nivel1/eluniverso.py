from scrapy.item import Field, Item
from scrapy.spiders import Spider
from scrapy.selector import Selector
from scrapy.loader.processors import MapCompose
from scrapy.loader import ItemLoader
from scrapy.crawler import CrawlerProcess
from bs4 import BeautifulSoup

class Noticia(Item):
    titular = Field()
    descripcion = Field()

class ElUniversoSpider(Spider):
    name = "MiSegundoSpider"
    custom_settings = {
        'USER_AGENT': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Ubuntu Chromium/71.0.3578.80 Chrome/71.0.3578.80 Safari/537.36'
    }

    start_urls = ['https://www.eluniverso.com/deportes']

    def parse(self, response):
        #Scrapy
        sel = Selector(response)
        noticias = sel.xpath('//div[@class="content-feed"]//div[@class="card-content"]')

        for noticia in noticias:
            item = ItemLoader(Noticia(), noticia)
            item.add_xpath('titular', './/h2/a/text()')
            item.add_xpath('descripcion', './/p/text()')

            yield item.load_item()

        #BeautifulSoup
        # soup = BeautifulSoup(response.body)
        # contenedor_noticias = soup.find_all('div', class_='content-feed')
        #
        # for contenedor in contenedor_noticias:
        #     noticias = contenedor.find_all('div', class_='card-content', recursive=False)
        #     for noticia in noticias:
        #         item = ItemLoader(Noticia(), response.body)
        #
        #         titular = noticia.find('h2').text
        #         descripcion = noticia.find('p')
        #
        #         if (descripcion != None):
        #             descripcion = descripcion.text
        #         else:
        #             descripcion = 'N/A'
        #
        #         item.add_value('titular', titular)
        #         item.add_value('descripcion', descripcion)
        #
        #         yield item.load_item()

# Correr el script de scrapy en terminal
# scrapy runspider stackoverflow_scrapy.py -o datos.csv -t csv

# Correr sin terminal
process = CrawlerProcess({
    'FEED_FORMAT': 'json',  # formato del archivo
    'FEED_URI': 'datos.json'  # nombre del archivo
})

process.crawl(ElUniversoSpider)
process.start()

