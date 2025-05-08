import zipfile

zip_filename = 'archive.zip'
files_to_add = ['4.py', '5.py']

with zipfile.ZipFile(zip_filename, 'a') as zipf:  
    for file in files_to_add:
        zipf.write(file)
        print(f"Appended {file} to {zip_filename}")
