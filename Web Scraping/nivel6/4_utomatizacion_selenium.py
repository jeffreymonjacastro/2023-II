import schedule
import time
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager

start_urls = [
        "https://www.accuweather.com/es/ec/guayaquil/127947/weather-forecast/127947",
        "https://www.accuweather.com/es/ec/quito/129846/weather-forecast/129846",
        "https://www.accuweather.com/es/es/madrid/308526/weather-forecast/308526"
]

opts = Options()
opts.add_argument("user-agent=Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/108.0.0.0 Safari/537.36")


def extraer_datos():
    driver = webdriver.Chrome(
        service=Service(ChromeDriverManager().install()),
        options=opts
    )

    for url in start_urls:
        driver.get(url)

        ciudad = driver.find_element(By.XPATH, '//h1').text
        current = driver.find_element(By.XPATH, '//div[contains(@class, "cur-con-weather-card__body")]//div[@class="temp"]').text
        real_feel = driver.find_element(By.XPATH, '//div[contains(@class, "cur-con-weather-card__body")]//div[@class="real-feel"]').text

        ciudad = ciudad.replace('\n', '').replace('\r', '').strip()
        current = current.replace('C', '').replace('°', '').replace('\n', '').replace('\r', '').strip()
        real_feel = real_feel.replace('RealFeel®', '').replace('°', '').replace('\n', '').replace('\r', '').strip()

        f = open("./datos_clima_selenium.csv", "a")
        f.write(ciudad + "," + current + "," + real_feel + "\n")
        f.close()

        print(ciudad)
        print(current)
        print(real_feel)
        print()

    driver.close()


schedule.every(5).seconds.do(extraer_datos)

while True:
    schedule.run_pending()
    time.sleep(1)

