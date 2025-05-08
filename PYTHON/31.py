class Employee:
    def __init__(self, name, emp_id, salary):
        self.name = name
        self.emp_id = emp_id
        self.salary = salary
    
    def give_increment(self, percentage):
        self.salary += self.salary * (percentage / 100)
        print(f"New salary for {self.name} (ID: {self.emp_id}): {self.salary:.2f}")

# Sample usage
emp1 = Employee("Alice Johnson", 101, 50000)
emp2 = Employee("Bob Smith", 102, 60000)

emp1.give_increment(10)  # 10% increment
emp2.give_increment(5)   # 5% increment
