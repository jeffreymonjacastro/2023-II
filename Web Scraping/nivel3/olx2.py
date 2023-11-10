from time import sleep
from selenium import webdriver  # pip install selenium
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.chrome.options import Options
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.support.ui import WebDriverWait  # Para esperar a que cargue un elemento
from selenium.webdriver.support import expected_conditions as EC  # Para esperar a que cargue un elemento

# Asi podemos setear el user-agent en selenium
opts = Options()
opts.add_argument("user-agent=Chrome/119.0.6045.124 Chromium/119.0.6045.124 Safari/537.36' Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Ubuntu")
# opts.add_argument("--headless")

# Instancio el driver de selenium que va a controlar el navegador
# A partir de este objeto voy a realizar el web scraping e interacciones
driver = webdriver.Chrome(service = Service(ChromeDriverManager().install()), options=opts)

# Voy a la pagina que quiero
driver.get('https://www.olx.in/')
sleep(2)
driver.refresh()  # Solucion de un bug extraño en Windows en donde los anuncios solo cargan al hacerle refresh a la página
sleep(2)  # Esperamos que cargue el boton

for i in range(3):  # Voy a darle click en cargar mas 3 veces
    try:
        # Busco el boton para cargar más información
        boton = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.XPATH, '//button[@data-aut-id="btnLoadMore"]'))
        )

        boton.click()  # le doy click

        # espero que cargue la información dinámica
        WebDriverWait(driver, 10).until(
            EC.presence_of_all_elements_located((By.XPATH, '//li[@data-aut-id="itemBox"]//span[@data-aut-id="itemPrice"]'))
        )
    except Exception as e:
        # si hay algún error, rompo el lazo. No me complico.
        print("error", e.args)
        break

# Encuentro cual es el XPATH de cada elemento donde esta la informacion que quiero extraer
# Esto es una LISTA. Por eso el metodo esta en plural
anuncios = driver.find_elements(By.XPATH, '//li[@data-aut-id="itemBox"]')


# Recorro cada uno de los anuncios que he encontrado
for anuncio in anuncios:
    try:
        # Por cada anuncio hallo el precio
        precio = anuncio.find_element(By.XPATH, './/span[@data-aut-id="itemPrice"]').text
        print(precio)

        # Por cada anuncio hallo la descripcion
        descripcion = anuncio.find_element(By.XPATH, './/span[@data-aut-id="itemTitle"]').text
        print(descripcion)

    except Exception as e:
        print('Anuncio carece de precio o descripcion')
