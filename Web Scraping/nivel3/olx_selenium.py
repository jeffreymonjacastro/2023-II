import random
from time import sleep
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By

# Ruta al controlador de Chrome
chrome_driver_path = "./chromedriver.exe"

# Configurar las opciones de Chrome
chrome_options = webdriver.ChromeOptions()
chrome_options.add_argument("--start-maximized")

# Crear el controlador de Chrome con las opciones
driver = webdriver.Chrome(service=Service(chrome_driver_path), options=chrome_options)

driver.get('https://www.olx.com.pe/autos_c378')

boton = driver.find_element_by_xpath('//button[@data-aut-id="btnLoadMore"]')

for i in range(3):
    try:
        boton.click()
        sleep(random.uniform(8.0, 10.0))
        boton = driver.find_element_by_xpath('//button[@data-aut-id="btnLoadMore"]')
    except:
        break


# Todos los anuncios en una lista
autos = driver.find_elements_by_xpath('//li[@data-aut-id="itemBox"]')

for auto in autos:
    # Obtener el precio de cada anuncio
    precio = auto.find_element_by_xpath('.//span[@data-aut-id="itemPrice"]').text
    print(precio)

    description = auto.find_element_by_xpath('.//span[@data-aut-id="itemTitle"]').text
    print(description)