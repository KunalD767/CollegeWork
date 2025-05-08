import zipfile
import os

directory = '.'  # Current directory
zip_filename = 'texts_archive.zip'

with zipfile.ZipFile(zip_filename, 'w') as zipf:
    for foldername, subfolders, filenames in os.walk(directory):
        for filename in filenames:
            if filename.endswith('.txt'):
                filepath = os.path.join(foldername, filename)
                zipf.write(filepath)
                print(f"Added {filepath} to archive.")
