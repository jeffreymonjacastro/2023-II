"""
OBJETIVO:  
    - Inicio de sesion a partir de formulario con scrapy
CREADO POR: LEONARDO KUFFO
ULTIMA VEZ EDITADO: 09 ENERO 2023
"""
import scrapy
from scrapy.item import Field, Item
from scrapy.spiders import Spider
from scrapy.selector import Selector
from scrapy.loader.processors import MapCompose
from scrapy.loader import ItemLoader
from scrapy.crawler import CrawlerProcess
from bs4 import BeautifulSoup


class LoginSpider(Spider):
    name = 'GitHubLogin'

    start_urls = ['https://github.com/login']

    def parse(self, response):
        return scrapy.FormRequest.from_response(
            response,
            formdata={
              'login': 'jeffreymonjacastro',
              'password': 'TheWillyrex7'
            },
            callback=self.after_login
        )

    def after_login(self, response):
        request = scrapy.Request(
            'https://github.com/jeffreymonjacastro?tab=repositories',
            callback=self.parse_repositorios
        )

        yield request

    def parse_repositorios(self, response):
        sel = Selector(response)

        repositorios = sel.xpath('//h3[@class="wb-break-all"]/a/text()')

        for repositorio in repositorios:
            print(repositorio.get())

# Correr Scrapy sin terminal
process = CrawlerProcess({
    'FEED_FORMAT': 'json',
    'FEED_URI': 'datos_de_salida.json'
})
process.crawl(LoginSpider)
process.start()
