"""
CREADO POR: LEONARDO KUFFO
ULTIMA VEZ EDITADO: 09 ENERO 2023
"""
import requests  # pip install requests
from lxml import html  # pip install lxml
import json

# USER AGENT PARA PROTEGERNOS DE BANEOS
headers = {
    "user-agent": "Chrome/119.0.6045.124 Chromium/119.0.6045.124 Safari/537.36' Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Ubuntu",
}

# URL SEMILLA

for i in range(1, 5):
    url = "https://www.gob.pe/busquedas?reason=sheet&sheet=" + str(i)

    # REQUERIMIENTO AL SERVIDOR
    respuesta = requests.get(url, headers=headers)
    respuesta.encoding = 'UTF-8'


    # PARSEO DEL ARBOL HTML QUE RECIBO COMO RESPUESTA CON LXML
    parser = html.fromstring(respuesta.text)

    # EXTRACCION SOLO DEL TEXTO QUE DICE INGLES
    datos = parser.xpath("//script[contains(text(), 'window.initialData')]")
    datos = datos[0].text_content()
    indice_ini = datos.find('{')

    datos = datos[indice_ini:]
    objeto = json.loads(datos)

    resultados = objeto['data']['attributes']['results']

    for resultado in resultados:
        print(resultado["content"])