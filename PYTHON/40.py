import zipfile

files_to_zip = ['1.py', '2.py']
zip_filename = 'archive.zip'

with zipfile.ZipFile(zip_filename, 'w') as zipf:
    for file in files_to_zip:
        zipf.write(file)
        print(f"{file} added to {zip_filename}")
