# -*- coding: utf-8 -*-
"""
OBJETIVO: 
    - Extraer el precio, titulo y descripcion de productos en Mercado Libre.
    - Aprender a realizar extracciones verticales y horizontales con Selenium.
    - Demostrar que Selenium no es optimo para realizar extracciones que requieren traversar mucho a traves de varias pagina de una web
    - Aprender a manejar el "retroceso" del navegador
    - Aprender a definir user_agents en Selenium
CREADO POR: LEONARDO KUFFO
ULTIMA VEZ EDITADO: 09 ENERO 2023
"""
from time import sleep
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager

# Definimos el User Agent en Selenium utilizando la clase Options
opts = Options()
opts.add_argument("user-agent=Chrome/119.0.6045.124 Chromium/119.0.6045.124 Safari/537.36' Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Ubuntu")
driver = webdriver.Chrome(
    service=Service(ChromeDriverManager().install()),
    options=opts
)

#URL SEMILLA
driver.get('https://listado.mercadolibre.com.ec/herramientas-vehiculos/')


# LOGICA DE MAXIMA PAGINACION CON LAZO WHILE
# VECES VOY A PAGINAR HASTA UN MAXIMO DE 10 
PAGINACION_MAX = 5
PAGINACION_ACTUAL = 1

sleep(3)  # Esperar a que todo cargue correctamente

# Debemos darle click al boton de disclaimer para que no interrumpa nuestras acciones
# Encerramos todo en un try catch para que si no aparece el discilamer, no se caiga el codigo
try:
    disclaimer = driver.find_element(By.XPATH, '//button[@data-testid="action:understood-button"]')
    disclaimer.click()  # lo obtenemos y le damos click
except Exception as e:
    print(e)


# Mientras la pagina en la que me encuentre, sea menor que la maxima pagina que voy a sacar... sigo ejecutando...
while PAGINACION_MAX > PAGINACION_ACTUAL:
    links_productos = driver.find_elements(By.XPATH, '//a[@class="ui-search-item__group__element ui-search-link"]')
    links_de_la_pagina = []
    for a_link in links_productos:
        links_de_la_pagina.append(a_link.get_attribute("href"))

    print(links_de_la_pagina)

    for link in links_de_la_pagina:
        sleep(2)  # Prevenir baneos de IP

        try:
            # Voy a cada uno de los links de los detalles de los productos
            driver.get(link)

            # Rara vez da error si no utilizamos una espera por eventos:
            # precio_element = WebDriverWait(driver, 10).until(
            #   EC.presence_of_element_located((By.XPATH, '//span[contains(@class,"price-tag")]'))
            # )
            titulo = driver.find_element(By.XPATH, '//h1').text
            precio = driver.find_element(By.XPATH, '//div[contains(@class, "ui-pdp-price")]//span[@class="andes-money-amount__fraction"]').text
            print(titulo)
            print(precio.replace('\n', '').replace('\t', ''))

            # Aplasto el boton de retroceso
            driver.back()

        except Exception as e:
            print(e)
            # Si sucede algun error dentro del detalle, no me complico. Regreso a la lista y sigo con otro producto.
            driver.back()

    # Logica de deteccion de fin de paginacion
    try:
        # Intento obtener el boton de SIGUIENTE y le intento dar click
        puedo_seguir_horizontal = driver.find_element(By.XPATH, '//span[text()="Siguiente"]')
        puedo_seguir_horizontal.click()
    except:
        # Si obtengo un error al intentar darle click al boton, quiere decir que no existe
        # Lo cual me indica que ya no puedo seguir paginando, por ende rompo el While
        break

    PAGINACION_ACTUAL += 1
