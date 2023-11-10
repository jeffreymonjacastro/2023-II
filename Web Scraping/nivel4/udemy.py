"""
OBJETIVO: 
    - Extraer nombre, reviews y rating de los cursos de Python.
    - Aprender a extraer datos de APIs.
    - Aprender a investigar y decifrar la forma en que una pagina web que carga sus datos por API.
    - Aprender a hacer requerimientos a un API del cual no tenemos documentacion.
    - Aprender a utilizar la consola de NETWORKS de Google Chrome.
    - Aprender a procesar datos en formato JSON.
CREADO POR: LEONARDO KUFFO
ULTIMA VEZ EDITADO: 09 ENERO 2023
"""
import requests
import pandas as pd

headers = {
    # El encabezado de referer es importante. Sin esto, este API en especifico me respondera 403
    "Referer": "https://www.udemy.com/courses/search/?p=2&q=python&src=ukw",
    "User-Agent": "Chrome/119.0.6045.124 Chromium/119.0.6045.124 Safari/537.36' Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Ubuntu"
}

# Cursos totales es una lista que contendrá todos los cursos que extraigamos del API
cursos_totales = []

# Este lazo for me ayudara a iterar el parametro "page" del API
for i in range(1, 4):
    # Esta URL, y los parametros la deciframos gracias al panel de Networks y a una tarea de investigacion
    url_api = 'https://www.udemy.com/api-2.0/search-courses/?src=ukw&q=python&skip_price=true&p=' + str(i)

    response = requests.get(url_api, headers=headers)
    print(response)

    # Parseo la respuesta en formato JSON. Requests automaticamente lo convierte en un diccionario de Python
    data = response.json()

    # Extraigo los datos del diccionario
    cursos = data["courses"]

    for curso in cursos:
        cursos_totales.append({
            "title":  curso["title"],
            "num_reviews": curso["num_reviews"],
            "rating": curso["rating"]
        })
        # print(curso["title"])
        # print(curso["num_reviews"])
        # print(curso["rating"])
        # print(cursos_totales)

    # Hago que el usuario tenga que aplastar enter antes de seguir a la siguiente pagina
    input()

df = pd.DataFrame(cursos_totales)

print(df)

df.to_csv("cursos_udemy.csv")
