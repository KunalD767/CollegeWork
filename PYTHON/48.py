import requests
from bs4 import BeautifulSoup

url = 'https://example.com'
response = requests.get(url)
soup = BeautifulSoup(response.content, 'html.parser')

links = []
for link in soup.find_all('a', href=True):
    links.append(link['href'])

with open('links.txt', 'w', encoding='utf-8') as f:
    for link in links:
        f.write(link + '\n')

print(f"Extracted {len(links)} links and saved to links.txt")
