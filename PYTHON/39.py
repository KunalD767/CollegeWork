import shutil

source_file = 'example.txt'
destination_folder = 'CopiedSample.txt'

shutil.copy(source_file, destination_folder)
print("File copied successfully.")
