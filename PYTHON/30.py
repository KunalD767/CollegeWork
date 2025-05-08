def pretty_print_students(students):
    if not students:
        print("No student data available.")
        return
    
    header = "{:<20} {:<10}".format("Name", "Marks")
    print(header)
    print("-" * len(header))
    
    for student in students:
        print("{:<20} {:<10}".format(student["Name"], student["Marks"]))

# Sample student data
students = [
    {"Name": "Alice Johnson", "Marks": 85},
    {"Name": "Bob Smith", "Marks": 92},
    {"Name": "Charlie Brown", "Marks": 78}
]

# Pretty-print the student details
pretty_print_students(students)
