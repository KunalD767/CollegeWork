import pprint

def pretty_print_employees(employees):
    if not employees:
        print("No employee data available.")
        return
    
    pprint.pprint(employees, sort_dicts=False)

# Sample employee data
employees = [
    {"Name": "Alice Johnson", "Age": 30, "Department": "HR"},
    {"Name": "Bob Smith", "Age": 25, "Department": "IT"},
    {"Name": "Charlie Brown", "Age": 35, "Department": "Finance"}
]

# Pretty-print the employee details
pretty_print_employees(employees)
