# Notes Management System

A command-line notes management program written in C. I built this as a larger project to practice combining C fundamentals with dynamic memory, structures, file handling, string processing, and Windows APIs.

## Features

- Create and store notes
- Remove and search notes
- View stored notes and tags
- Organize notes as **work**, **study**, or **personal**
- Mark notes with different priorities
- Add deadlines to applicable notes
- Store notes in a text file
- Encrypt stored note text using a simple Caesar-style shift
- Check deadlines and display a Windows message when a deadline is reached

## Files

- `notes_management.c` — main notes management program
- `due_date.c` — checks stored deadlines and displays a Windows notification
- `run_due_date.bat` — batch file used with the deadline-checking setup
- `notes.txt` — example/storage file used by the program
- `airplane.wav` — sound used with the Windows deadline notification

## Concepts Practiced

- Structures and `typedef`
- Pointers and dynamic memory allocation
- Strings and string manipulation
- File I/O
- Command-line input handling
- Searching and tokenization
- Encryption/decryption logic
- Date and time handling
- Windows API functions
- Error handling and memory management

## Running

This project currently uses Windows-specific functionality such as `windows.h`, `MessageBox`, `PlaySound`, and Windows startup paths. It is therefore intended to run on Windows.

Compile the main program with a C compiler such as GCC. The deadline checker also requires the files in this directory to remain in the expected relative locations.

## Note

This project was built as part of my C programming learning process. The encryption used here is educational and is **not intended to provide real-world security**.
