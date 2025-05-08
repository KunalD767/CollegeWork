import os

base_path = 'project_structure'
dirs = ['docs', 'src', 'tests']
files = {
    'docs': ['readme.txt'],
    'src': ['main.py'],
    'tests': ['test_main.py']
}

# Create directories and write files
os.makedirs(base_path, exist_ok=True)
for d in dirs:
    dir_path = os.path.join(base_path, d)
    os.makedirs(dir_path, exist_ok=True)
    for f in files[d]:
        file_path = os.path.join(dir_path, f)
        with open(file_path, 'w') as file:
            file.write(f"This is the file: {f}\n")
        print(f"Created {file_path}")
