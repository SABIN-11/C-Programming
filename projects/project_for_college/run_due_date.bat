@echo off
echo Compiling the program...
cd "C:\codes\vs code\c codes\projects\project_for_college"
gcc -o due_date due_date.c -lwinmm
if %errorlevel% neq 0 (
    echo Compilation failed!
    pause
    exit /b
)
echo Running the program...
due_date.exe
pause
