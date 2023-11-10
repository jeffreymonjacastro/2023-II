from time import sleep
from selenium import webdriver  # Instanciar el navegador
from selenium.webdriver.common.by import By  # Búsquedas por xpath
from selenium.webdriver.chrome.options import Options  # Opciones de Chrome
from selenium.webdriver.chrome.service import Service  # Servicio de Chrome

from webdriver_manager.chrome import ChromeDriverManager


opts = Options()
opts.add_argument("user-agent=Chrome/119.0.6045.124 Chromium/119.0.6045.124 Safari/537.36' Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Ubuntu")
opts.add_argument("--headless")  # Para que no se abra el navegador

# Ruta al controlador de Chrome (Instanciación)
driver = webdriver.Chrome(
    service=Service(ChromeDriverManager().install()),  # Descarga automáticamente el driver para cualquier versión
    options=opts
)

driver.get("https://www.airbnb.com/")

sleep(3)

# Lista de elementos
titulos_anuncios = driver.find_elements(By.XPATH, '//div[@data-testid="listing-card-title"]')

print(titulos_anuncios)

for titulo in titulos_anuncios:
    print(titulo.text)
