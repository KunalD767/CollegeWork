import os

target_dir = '.'  # You can change this to any path

for root, dirs, files in os.walk(target_dir):
    for file in files:
        if file.endswith('.txt'):
            print(os.path.join(root, file))
