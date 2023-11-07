from scrapy.item import Field, Item
from scrapy.spiders import CrawlSpider, Rule
from scrapy.selector import Selector
from scrapy.loader.processors import MapCompose
from scrapy.linkextractors import LinkExtractor
from scrapy.loader import ItemLoader


class Articulo(Item):
    titulo = Field()
    contenido = Field()

class Review(Item):
    titulo = Field()
    calificacion = Field()

class Video(Item):
    titulo = Field()
    fecha_publicacion = Field()


class IGNCrawler(CrawlSpider):
    name = 'ign'

    custom_settings = {
        'USER_AGENT': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 \
        (KHTML, like Gecko) Ubuntu Chromium/71.0.3578.80 Chrome/71.0.3578.80 Safari/537.36',
        'CLOSESPIDER_PAGECOUNT': 50
    }

    allowed_domains = ['latam.ign.com']

    download_delay = 1

    start_urls = ['https://latam.ign.com/se/?type=news&q=ps5&order_by=-date']

    rules = (
        # Horizontalidad por tipo de inforamción
        Rule(
            LinkExtractor(
                allow=r'type='
            ), follow=True
        ),
        # Horizontalidad por paginación
        Rule(
            LinkExtractor(
                allow=r'&page=\d+'
            ), follow=True
        ),
        # Una regla por cada tipo de contenido donde ire verticalmente
        # Reviews
        Rule(
            LinkExtractor(
                allow=r'/review/'
            ), follow=True, callback='parse_review'  # Como ya debe extraerse, debe tener un callback
        ),
        # Videos
        Rule(
            LinkExtractor(
                allow=r'/video/'
            ), follow=True, callback='parse_video'  # Como ya debe extraerse, debe tener un callback
        ),
        # Articulos
        Rule(
            LinkExtractor(
                allow=r'/news/'
            ), follow=True, callback='parse_news'  # Como ya debe extraerse, debe tener un callback
        ),
    )

    def parse_review(self, response):
        item = ItemLoader(Review(), response)

        item.add_xpath(
            'titulo',
            '//h1/text()'
        )
        item.add_xpath(
            'calificacion',
            '//div[@class="review"]//span[@class="side-wrapper side-wrapper hexagon-content"]/div/text()'
        )

        yield item.load_item()

    def parse_video(self, response):
        item = ItemLoader(Video(), response)

        item.add_xpath(
            'titulo',
            '//h1[@id="id_title"]/text()'
        )
        item.add_xpath(
            'fecha_publicacion',
            '//span[@class="publish-date"]/text()'
        )

        yield item.load_item()

    def parse_news(self, response):
        item = ItemLoader(Articulo(), response)

        item.add_xpath(
            'titulo',
            '//h1[@id="id_title"]/text()'
        )
        item.add_xpath(
            'contenido',
            '//div[@id="id_text"]//*/text()'
        )

        yield item.load_item()