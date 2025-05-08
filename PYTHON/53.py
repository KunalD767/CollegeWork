import os
import zipfile

base_dir = '.'  # Start here or change to specific root directory

for root, dirs, files in os.walk(base_dir):
    txt_files = [f for f in files if f.endswith('.txt')]
    if txt_files:
        archive_name = os.path.basename(root) or "root"
        zip_filename = f"{archive_name}_texts.zip"

        with zipfile.ZipFile(zip_filename, 'w') as zipf:
            for file in txt_files:
                file_path = os.path.join(root, file)
                zipf.write(file_path)
                print(f"Added {file_path} to {zip_filename}")
