Here’s an improved version of the README for the **TitleModifier** project, making it more detailed and professional:

---

# TitleModifier

**TitleModifier** is a system programming project developed by Guillaume IMHOFF. The main objective of this project was to gain experience and improve proficiency in system-level programming using the C language.

This tool allows you to scan a specified directory and remove a given substring from the filenames within that directory.

## Features

- **Directory Scanning**: The program scans a specified folder and checks the filenames of all files and directories.
- **Substring Removal**: If a filename contains the specified string, the program renames the file or directory by removing that substring.
- **Simple and Efficient**: Lightweight, command-line based, with a straightforward interface for ease of use.

## Installation & Compilation

You can either download the precompiled binary from the [Releases](https://github.com/g-imhoff/TitleModifier/releases) section or clone the repository and compile it on your local machine:

### Step-by-Step Instructions:

1. **Clone the Repository**:
   ```bash
   git clone git@github.com:purpl5/TitleModifier.git
   ```

2. **Navigate to the Project Directory**:
   ```bash
   cd TitleModifier
   ```

3. **Build the Project**:
   ```bash
   cd build
   make
   ```

4. **Run the Program**:
   ```bash
   ./TitleModifier
   ```

## Usage

Once compiled, the program can be run directly from the terminal:

```bash
computer@computer:~/TitleModifier/build$ ./TitleModifier 
Enter the name of the folder that you want to scan: ./
Enter the string to delete from the title: StrToDelete
The function was successful
```

In this example, the program scans the current directory (`./`) and checks the names of all files and folders. If any filenames contain the string `StrToDelete`, the program will rename those files or directories, removing the specified substring.

### Example:

If a file is named `exampleStrToDelete.txt` and you specify `StrToDelete` as the substring to delete, the file will be renamed to `example.txt`.

## Future Improvements

- **Recursive Search**: Implement the ability to search and modify filenames within nested directories.
- **File Type Filtering**: Allow users to modify only certain types of files (e.g., `.txt`, `.jpg`).
- **Dry Run Mode**: Add a "preview" feature to display the potential changes before making them.

## Contributing

If you would like to contribute to this project, feel free to fork the repository, make changes, and submit a pull request. Any improvements or suggestions are welcome.
