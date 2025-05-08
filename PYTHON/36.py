from pprint import pprint

class Product:
    def __init__(self, name, price, quantity):
        self.name = name
        self.set_price(price)  # Using setter to enforce validation
        self.quantity = quantity

    def set_price(self, price):
        if price <= 0:
            raise ValueError("Price must be a positive number.")
        self.price = price

    def to_dict(self):
        return {"Name": self.name, "Price": self.price, "Quantity": self.quantity}

# Example usage
try:
    products = [
        Product("Laptop", 1200, 5),
        Product("Mouse", 25, 50),
        Product("Keyboard", 45, 20),
    ]
    pprint([p.to_dict() for p in products])
except ValueError as e:
    print(f"Error: {e}")
