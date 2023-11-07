from scrapy.item import Field, Item
from scrapy.spiders import CrawlSpider, Rule
from scrapy.selector import Selector
from scrapy.loader.processors import MapCompose
from scrapy.linkextractors import LinkExtractor
from scrapy.loader import ItemLoader


class Opinion(Item):
    titulo = Field()
    calificacion = Field()
    contenido = Field()
    autor = Field()

class TripAdvisor(CrawlSpider):
    name = "OpinionesTripAdvisor"

    custom_settings = {
        'USER_AGENT': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 \
        (KHTML, like Gecko) Ubuntu Chromium/71.0.3578.80 Chrome/71.0.3578.80 Safari/537.36',
        'CLOSESPIDER_PAGECOUNT': 100
    }

    allowed_domains = ['tripadvisor.com.pe']

    start_urls = ['https://www.tripadvisor.com.pe/Hotels-g294316-Lima_Lima_Region-Hotels.html']

    download_delay = 1

    rules = (
        # Paginación de Hoteles (Horizontalidad)
        Rule(
            LinkExtractor(
                allow=r'-oa\d+-'
            ), follow=True
        ),
        # Detalle de Hoteles (Verticalidad)
        Rule(
            LinkExtractor(
                allow=r'/Hotel_Review-',
                restrict_xpaths=['//div[@id="taplc_hsx_hotel_list_lite_dusty_hotels_combined_sponsored_0"]//a[@data-clicksource="HotelName"]']
            ), follow=True
        ),
        # Paginación de Opionioes dentro de un hotel (Horizontalidad)
        Rule(
            LinkExtractor(
                allow=r'-or\d+-'
            ), follow=True
        ),
        # Detalle de Perfil de usuario (Verticalidad)
        Rule(
            LinkExtractor(
                allow=r'/Profile/',
                restrict_xpaths=['//div[@data-test-target = "reviews-tab"]//a[contains(@class, "ui_header")]']
            ), follow=True, callback='parse_opinion'
        ),
    )

    def obtenerCalificacion(self, texto):
        calificacion = texto.split("_")[-1]
        return calificacion

    def parse_opinion(self, response):
        sel = Selector(response)
        opiniones = sel.xpath('//div[@id="content"]/div/div]')
        autor = sel.xpath('//h1/span/text()').get() # get() para obtener el valor

        for opinion in opiniones:
            item = ItemLoader(Opinion(), opinion)
            item.add_xpath('titulo', './/div[@class="AzIrY b _a VrCoN"]/text()') # No existe :c
            item.add_xpath('contenido', './/q/text()')
            item.add_xpath('calificacion',
                           './/div[contains(@class, "social-section-review")]/span/@class',
                           MapCompose(self.obtenerCalificacion))
            item.add_value('autor', autor)

            yield item.load_item()
