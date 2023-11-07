from scrapy.item import Field, Item
from scrapy.spiders import CrawlSpider, Rule
from scrapy.selector import Selector
from scrapy.loader.processors import MapCompose
from scrapy.linkextractors import LinkExtractor
from scrapy.loader import ItemLoader


class Articulo(Item):
    titulo = Field()
    descripcion = Field()
    precio = Field()


class MercadoLibre(CrawlSpider):
    name = "Articulos"
    custom_settings = {
        'USER_AGENT': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 \
        (KHTML, like Gecko) Ubuntu Chromium/71.0.3578.80 Chrome/71.0.3578.80 Safari/537.36',
        'CLOSESPIDER_PAGECOUNT': 30  # Cantidad de páginas que va a recorrer
    }

    download_delay = 2

    allowed_domains = ['listado.mercadolibre.com.pe', 'articulo.mercadolibre.com.pe']  # Dominios permitidos

    start_urls = ['https://listado.mercadolibre.com.pe/animales-mascotas/perros/']

    rules = (
        #Paginación
        Rule(
            LinkExtractor(
                allow=r'/_Desde_'
            ), follow=True  # No tiene callback porque no se va a extraer información de la página
        ),

        # Detalle de los productos
        Rule(
            LinkExtractor(
                allow=r'/MPE-'
            ), follow=True, callback="parse_items"
        ),
    )

    def limpiarTexto(self, texto):
        nuevoTexto = texto.replace('\n', '').replace('\r', '').replace('\t', '').strip()
        return nuevoTexto


    def parse_items(self, response):
        item = ItemLoader(Articulo(), response)

        item.add_xpath('titulo',
                       '//h1[@class="ui-pdp-title"]/text()',
                       MapCompose(self.limpiarTexto))
        item.add_xpath('descripcion',
                       '//div[@class="ui-pdp-description"]/p/text()',
                       MapCompose(self.limpiarTexto))
        item.add_xpath('precio',
                       '//div[@class="ui-pdp-price__second-line"]//span[@class="andes-money-amount__fraction"]/text()')

        yield item.load_item()

