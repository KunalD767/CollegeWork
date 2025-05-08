import shutil

source_dir = 'source_folder'
destination_dir = 'backup_folder'

shutil.copytree(source_dir, destination_dir, dirs_exist_ok=True)
print(f"Copied '{source_dir}' to '{destination_dir}'")
