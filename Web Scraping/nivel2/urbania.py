from scrapy.item import Field, Item
from scrapy.spiders import CrawlSpider, Rule
from scrapy.selector import Selector
from scrapy.loader.processors import MapCompose
from scrapy.linkextractors import LinkExtractor
from scrapy.loader import ItemLoader


class Departamento(Item):
    nombre = Field()
    direccion = Field()


class Urbaniape(CrawlSpider):
    name = "Departamentos"

    custom_settings = {
        'USER_AGENT': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 13_1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/108.0.0.0 Safari/537.36',
        'CLOSESPIDER_ITEMCOUNT': 10,
        'DOWNLOADER_MIDDLEWARES': {'scrapy_crawlera.CrawleraMiddleware': 610},
        'CRAWLERA_ENABLED': True,
        'CRAWLERA_APIKEY': '5db1c863a0cd4c9f873f3646dab649c2'
    }

    # Como no es posible acceder horizontalmente, se debe hacer un listado de las páginas
    start_urls = [
        'https://urbania.pe/buscar/proyectos-departamentos?page=1',
        'https://urbania.pe/buscar/proyectos-departamentos?page=2',
        'https://urbania.pe/buscar/proyectos-departamentos?page=3',
        'https://urbania.pe/buscar/proyectos-departamentos?page=4',
        'https://urbania.pe/buscar/proyectos-departamentos?page=5'
    ]

    allowed_domains = ['urbania.pe']

    # download_delay = 1

    rules = (
        Rule(
            LinkExtractor(
                allow=r'/proyecto-'
            ), follow=True, callback='parse_depa'
        ),
    )

    def parse_depa(self, response):
        sel = Selector(response)
        item = ItemLoader(Departamento(), sel)

        item.add_xpath('nombre', '//h1[@class="title"]/text()')
        item.add_xpath('direccion', '//p[@class="subtitle"]/text()')

        yield item.load_item()