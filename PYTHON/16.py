class Car:
    def __init__(self, make, model, year, color):
        self.make = make
        self.model = model
        self.year = year
        self.color = color

    def display_info(self):
        return f"{self.year} {self.color} {self.make} {self.model}"

# Creating an object of the Car class
my_car = Car("Toyota", "Corolla", 2020, "Blue")

# Displaying the car information
print("Car Information:", my_car.display_info())
