
import csv
import json
import os

def create_sample_csv(file_name):

    if not os.path.exists(file_name):
        with open(file_name, 'w', newline='') as file:
            writer = csv.writer(file)
            writer.writerow(["name", "age", "city"])
            writer.writerow(["Alice", "30", "New York"])
            writer.writerow(["Bob", "25", "Los Angeles"])
            writer.writerow(["Charlie", "35", "Chicago"])
       
def convert_csv_to_json(input_file, output_file):
    data = []

    # Ensure the input file exists
    create_sample_csv(input_file)

    with open(input_file, 'r') as csv_file:
        reader = csv.reader(csv_file)
        for row in reader:
            data.append(row)

    with open(output_file, 'w') as json_file:
        json.dump(data, json_file, indent=4)

    print(f"Data successfully converted from {input_file} to {output_file}")

convert_csv_to_json('input.csv', 'output.json')
