import requests
from bs4 import BeautifulSoup

url = 'https://mait.ac.in'
response = requests.get(url)
soup = BeautifulSoup(response.content, 'html.parser')

# Save all text content
with open('scraped_content.txt', 'w', encoding='utf-8') as f:
    f.write(soup.get_text())

print("Website content saved to scraped_content.txt")
