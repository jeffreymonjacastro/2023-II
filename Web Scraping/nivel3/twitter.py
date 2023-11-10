"""
OBJETIVO: 
    - Actualización de Twitter 2023
CREADO POR: LEONARDO KUFFO
ULTIMA VEZ EDITADO: 16 JUNIO 2023
"""

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager

opts = Options()
opts.add_argument("user-agent=Chrome/119.0.6045.124 Chromium/119.0.6045.124 Safari/537.36' Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Ubuntu")

driver = webdriver.Chrome(
    service=Service(ChromeDriverManager().install()),
    options=opts
)
driver.get('https://twitter.com/login')

user = "jeffrey_amc_"
# password = open('password.txt').readline().strip()
password = "TheWillyrex7"


# Me doy cuenta que la pagina carga el formulario dinamicamente luego de que la carga incial ha sido completada
# Por eso tengo que esperar que aparezca 
input_user = WebDriverWait(driver, 10).until(
    EC.presence_of_element_located((By.XPATH, "//input[@class = 'r-30o5oe r-1niwhzg r-17gur6a r-1yadl64 r-deolkf r-homxoj r-poiln3 r-7cikom r-1ny4l3l r-t60dpp r-1dz5y72 r-fdjqy7 r-13qz1uu']"))
)
input_user.send_keys(user)

# Obtengo el boton next y lo presiono para poder poner la pass
next_button = driver.find_element(By.XPATH, '//div[@class="css-18t94o4 css-1dbjc4n r-sdzlij r-1phboty r-rs99b7 r-ywje51 r-usiww2 r-2yi16 r-1qi8awa r-1ny4l3l r-ymttw5 r-o7ynqc r-6416eg r-lrvibr r-13qz1uu"]/div[@class="css-901oao r-1awozwy r-6koalj r-18u37iz r-16y2uox r-37j5jr r-a023e6 r-b88u0q r-1777fci r-rjixqe r-bcqeeo r-q4m81j r-qvutc0"]')
next_button.click()

# Obtengo los inputs de usuario (linea 28) y password
input_pass = WebDriverWait(driver, 10).until(
    EC.presence_of_element_located((By.XPATH, '//input[@class="r-30o5oe r-1niwhzg r-17gur6a r-1yadl64 r-deolkf r-homxoj r-poiln3 r-7cikom r-1ny4l3l r-t60dpp r-1dz5y72 r-fdjqy7 r-13qz1uu"]'))
)
input_pass.send_keys(password)

# Obtengo el boton de login
login_button = driver.find_element(By.XPATH, '//div[@data-testid="LoginForm_Login_Button"]')
# Le doy click
login_button.click()

# Espero a que aparezcan los tweets
tweets = WebDriverWait(driver, 10).until(
    EC.presence_of_all_elements_located((By.XPATH, '//div[@data-testid="tweetText"]'))
)

# Imprimo el texto de los tweets
for tweet in tweets:
  print(tweet.text)