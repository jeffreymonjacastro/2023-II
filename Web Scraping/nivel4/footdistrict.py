"""
Objetivo: 
   - Extraer datos de un tag script
CREADO POR: LEONARDO KUFFO
ULTIMA VEZ EDITADO: 16 JUNIO 2023
"""
import requests
import json
from bs4 import BeautifulSoup 

headers = {
    "user-agent": "Chrome/119.0.6045.124 Chromium/119.0.6045.124 Safari/537.36' Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Ubuntu"
}


url = "https://footdistrict.com/air-jordan-1-mid-ss-ps-dx4378-400.html"

resp = requests.get(url, headers=headers)
soup = BeautifulSoup(resp.text, features="lxml")

# Las tallas cargan dinamicamente, e inicialmente se encuentran
# dentro de un JSON en el tag script
scripts = soup.find_all('script')
for script in scripts:
    contenido = script.contents
    if len(contenido) > 0:
        script = contenido[0]
        if "Talla" in script:
            texto_script = script

# Obtengo la posicion de mi cadena donde se encuentra el parentesis abierto
ini = texto_script.find('(') + 1

# Obtengo la posicion de mi cadena donde se encuentra el parentesis cerrado
fin = texto_script.find(')')

# Con las posiciones, puedo cortar la cadena. A esto se le llama slicing, o obtener un substring.
objeto = texto_script[ini:fin]

# Cargo el json a un diccionario
objeto = json.loads(objeto)

# Sabiendo la estructura del diccionario lo recorro para obtener la informacion que quiero
tallas = objeto["[data-role=swatch-options]"]["Magento_Swatches/js/swatch-renderer"]["jsonConfig"]["attributes"]["134"]["options"]

for talla in tallas:
    if "No disponible" not in talla["label"]:  # filtro las tallas que no estan disponibles
        print(talla["label"])  # Imprimo por pantalla
