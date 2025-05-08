import requests
from bs4 import BeautifulSoup

base_url = 'https://example.com/page/'
page = 1
all_data = []

while True:
    response = requests.get(f"{base_url}{page}")
    if response.status_code != 200:
        break

    soup = BeautifulSoup(response.content, 'html.parser')
    items = soup.select('.item')  # Change this to actual CSS class

    if not items:
        break

    for item in items:
        all_data.append(item.get_text(strip=True))
    
    print(f"Scraped page {page}")
    page += 1

with open('paginated_data.txt', 'w', encoding='utf-8') as f:
    for line in all_data:
        f.write(line + '\n')

print("Saved all paginated data.")
