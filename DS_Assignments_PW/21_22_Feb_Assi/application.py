#  Q1. Write a python program to extract the video URL of the first five videos.
# Q2. Write a python program to extract the URL of the video thumbnails of the first five videos.
# Q3. Write a python program to extract the title of the first five videos.
# Q4. Write a python program to extract the number of views of the first five videos.
# Q5. Write a python program to extract the time of posting of video for the first five videos.

# Note: Save all the data scraped in the above questions in a CSV file.

# Create a simple UI with all functionalities mentioned above and deploy it in AWS.

# Note: Create your assignment in Jupyter notebook and upload it to GitHub
# & share that uploaded assignment file link through your dashboard.
# Make sure the repository is public. Submit your deployment link as well.


from selenium.webdriver.chrome.service import Service
from webdriver_manager.chrome import ChromeDriverManager
from selenium import webdriver
from bs4 import BeautifulSoup as bs
import pandas as pd


options = webdriver.ChromeOptions()
# options.headless=True
options.add_argument("--headless")
browser = webdriver.Chrome(
    options=options, service=Service(ChromeDriverManager().install()))
browser.get("https://www.youtube.com/@PW-Foundation/videos")

browser.execute_script("window.scrollTo(0,400)", "")

html = browser.page_source

soup = bs(html, "html.parser")
b = soup.find("div", {"id": "contents"})


link = []
thumbnail = []
title = []
views = []
time = []


# Link
a = (b.find_all("a", {
    "class": "yt-simple-endpoint inline-block style-scope ytd-thumbnail"}))[0:5]
for i in a:
    link.append("https://www.youtube.com"+str(i.get("href")))

# Thumbnail
a = soup.find_all("img", {"class": "yt-core-image--fill-parent-height"})[:5]
for i in a:
    thumbnail.append(str(i['src']))

# Title
a = (b.find_all("a", {
    "class": "yt-simple-endpoint focus-on-expand style-scope ytd-rich-grid-media"}))[0:5]
for i in a:
    title.append(str(i.get("title")))

# No of views
a = (b.find_all("div", {"id": "metadata"}))[0:5]
for i in a:
    views.append(str(i.find_all("span")[1].text))


# Time of Posting
a = (b.find_all("div", {"id": "metadata"}))[0:5]
for i in a:
    time.append(str(i.find_all("span")[2].text))

# mydict = {
#     "link": link,
#     "thumbnail": thumbnail,
#     "title": title,
#     "views": views,
#     "time": time
# }


with open("Q.csv", "w") as f:
    f.write("link, thumbnail, title, views, time"+"\n")
    for i in range(5):
        f.write(link[i]+","+thumbnail[i]+"," +
                title[i]+","+views[i]+","+time[i]+"\n")


with open("Q.csv") as f:
    r = f.read()
print(r)
# for i in r:
#     print(i)

with open("QT.csv", "w") as f:
    f.writelines(r)



# with open("Q.csv") as f:
#     print(f.read())
# print(pd.read_csv("Q.csv"))

# with open("Q.csv", "w") as f:
#     for key, value in mydict.items():
#         f.write('%s:\n%s\n\n' % (key, value))

# with open("Q.csv") as f:
#     print(f.read())
