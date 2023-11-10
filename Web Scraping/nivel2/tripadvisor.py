from scrapy.item import Field, Item
from scrapy.spiders import CrawlSpider, Rule
from scrapy.selector import Selector
from scrapy.loader.processors import MapCompose
from scrapy.linkextractors import LinkExtractor
from scrapy.loader import ItemLoader
from scrapy.crawler import CrawlerProcess


# Web Scraping vertical: Se ingresa a una página y se extrae información de ella
# Web Scraping horizontal: Se ingresa a cada paginación 1,2,3,4


class Hotel(Item):
    nombre = Field()
    precio = Field()
    descripcion = Field()
    amenities = Field()


class TripAdvisor(CrawlSpider):
    name = "Hoteles"
    custom_settings = {
        'USER_AGENT': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 \
        (KHTML, like Gecko) Ubuntu Chromium/71.0.3578.80 Chrome/71.0.3578.80 Safari/537.36',
        'FEED_EXPORT_FIELDS': ['nombre', 'precio', 'descripcion', 'amenities'], # Para que se exporten los campos en el orden que se desea
        'CONCURRENT_REQUESTS': 1 # Para que se haga un requerimiento a la vez
    }

    start_urls = ['https://www.tripadvisor.com.pe/Hotels-g303845-Guayaquil_Guayas_Province-Hotels.html']

    # Va a ser un rango de 0.5 * download_delay y 1.5 * download_delay para no tener un patrón robotizado
    download_delay = 2  # Tiempo de espera entre cada requerimiento

    # Reglas de extracción
    # Las reglas van a ser escritas mediante expresiones regulares (patrones)
    rules = (
        Rule(
            LinkExtractor(
                allow=r'/Hotel_Review-'  # Patrón para ir a la página de cada hotel
            ), follow=True, callback="parse_hotel" # True para que siga buscando en las páginas siguientes
        ),
    )

    # SE aplica para las n urls semillas que se ingresan en start_urls
    def parse_start_url(self, response):
        sel = Selector(response)
        hoteles = sel.xpath('//div[@data-test-target="hotel-name"]')
        print("Numero de Resultados: ", len(hoteles))

    # MapCompose: Sirve para aplicar una función a cada uno de los elementos que se extraen
    def quitarSimboloDolar(self, texto):
        nuevoTexto = texto.replace('$', '')
        nuevoTexto = nuevoTexto.replace('\n', '').replace('\r', '').replace('\t', '').strip()
        return nuevoTexto

    # Callback: Esta función se llamará cada vez que se haga un requerimiento a una página que cumpla con la regla
    def parse_hotel(self, response):
        sel = Selector(response)
        item = ItemLoader(Hotel(), sel)

        # Las clases están encriptadas :C
        item.add_xpath('nombre',
                       '//h1[@id="HEADING"]/text()')
        item.add_xpath('precio',
                       '//div[@class="price __resizeWatch"]/text()',
                       MapCompose(self.quitarSimboloDolar))
        item.add_xpath('descripcion',
                       '//div[@class="cPQsENeY"]/text()')
        item.add_xpath('amenities',
                       '//div[@class="_2rdvbNSg"]/text()')

        yield item.load_item()

# Correr sin terminal
process = CrawlerProcess({
    'FEED_FORMAT': 'csv',  # formato del archivo
    'FEED_URI': 'datos.csv'  # nombre del archivo
})

process.crawl(TripAdvisor)
process.start()
