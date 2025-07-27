#!/usr/bin/env python3
"""
Tile Renamer - Renames existing tile files to match the new naming convention.

This script will rename files like:
- tile_0.png, tile_1.png, etc. (for tiles)
- character_0.png, character_1.png, etc. (for characters)
- background_0.png, background_1.png, etc. (for backgrounds)
"""

import os
import sys
import shutil

def rename_tiles_in_directory(directory):
    """Rename tile files in the specified directory to match the new naming convention."""
    
    if not os.path.exists(directory):
        print(f"Directory '{directory}' does not exist.")
        return
    
    # Get all PNG files in the directory
    png_files = [f for f in os.listdir(directory) if f.endswith('.png')]
    
    if not png_files:
        print(f"No PNG files found in '{directory}'")
        return
    
    print(f"Found {len(png_files)} PNG files in '{directory}'")
    
    # Sort files to ensure consistent ordering
    png_files.sort()
    
    # Rename files
    for i, filename in enumerate(png_files):
        old_path = os.path.join(directory, filename)
        
        # Determine the type based on the original filename
        if 'tile' in filename.lower():
            new_name = f"tile_{i}.png"
        elif 'character' in filename.lower() or 'demo' in filename.lower():
            new_name = f"character_{i}.png"
        elif 'background' in filename.lower() or 'bricks' in filename.lower():
            new_name = f"background_{i}.png"
        else:
            # Default to tile if we can't determine the type
            new_name = f"tile_{i}.png"
        
        new_path = os.path.join(directory, new_name)
        
        # Only rename if the name is different
        if old_path != new_path:
            try:
                shutil.move(old_path, new_path)
                print(f"Renamed: {filename} -> {new_name}")
            except Exception as e:
                print(f"Error renaming {filename}: {e}")
        else:
            print(f"Already correctly named: {filename}")
    
    print(f"\nRenaming complete!")

def main():
    if len(sys.argv) != 2:
        print("Usage: python rename_tiles.py <directory>")
        print("Example: python rename_tiles.py res/images/")
        sys.exit(1)
    
    directory = sys.argv[1]
    rename_tiles_in_directory(directory)

if __name__ == "__main__":
    main() 