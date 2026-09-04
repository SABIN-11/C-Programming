//this program copies the file from one folder to another directly

#include <stdio.h>
#include <stdlib.h> //for getenv
#include <windows.h>    //for CopyFile and GetLastError

//MoveFile can be used to move the file instead of copying

int main() {

    char filePath[] = "C:\\Users\\Lenovo\\OneDrive\\Desktop\\batch files\\run_qsort.bat";  //path to our batch file
    // char startupPath[] = "C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\run_qsort.bat";  //path to startup

    char *startupPath = "C:\\Users\\Lenovo\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\run_qsort.bat";

    if (CopyFile(filePath, startupPath, TRUE)) {    //copies the file from filePath to startupPath
    //TRUE: doesn't overwrite if the same name file exists and returns error
    //good if the file doesn't already exist
    //FALSE: overwrites the already existing file
    //good for updating the file or changing something
    //CopyFile returns non-zero if successful and 0 is failure
    printf("File copied successfully to Startup folder.\n");
    } else {
        printf("Failed to copy the file. Error code: %lu\n", GetLastError());
        //GetLastError returns the last error value by Windows API functions
        //it returns 5 if the permission is denied
        //it returns 3 if file path is invalid
    }

    printf("\nPath: %s", getenv("PATH"));   //get the value in PATH variable in environment variable section
    //it gets both user and system variable values


    return 0;
}