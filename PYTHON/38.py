from pprint import pprint

class Student:
    def __init__(self, name, marks):
        self.name = name
        self.set_marks(marks)  # Validate marks

    def set_marks(self, marks):
        if not all(isinstance(m, (int, float)) and 0 <= m <= 100 for m in marks):
            raise ValueError("All marks must be numbers between 0 and 100.")
        self.marks = marks

    def average_marks(self):
        return sum(self.marks) / len(self.marks) if self.marks else 0

    def to_dict(self):
        return {"Name": self.name, "Marks": self.marks, "Average": self.average_marks()}

# Example usage
try:
    students = [
        Student("Alice", [85, 90, 78]),
        Student("Bob", [92, 88, 95]),
        Student("Charlie", [70, 75, 80]),
    ]
    pprint([s.to_dict() for s in students])
except ValueError as e:
    print(f"Error: {e}")
