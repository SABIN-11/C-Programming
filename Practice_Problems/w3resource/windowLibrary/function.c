// #include <windows.h>
// #include <stdio.h>

// int main() {
//     printf("Program started.\n");
//     int result = MessageBox(NULL, "Hello, World!", "Alarm", MB_OK | MB_ICONINFORMATION);
//     if (result == 0) {
//         DWORD error = GetLastError();
//         printf("MessageBox failed with error code %lu\n", error);
//     } else {
//         printf("MessageBox executed successfully.\n");
//     }
//     return 0;
// }

#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>

int main() {
    if (PlaySound(TEXT("C:/codes/vs code/c codes/projects/airplane.wav"), NULL, SND_FILENAME | SND_ASYNC)) {
        printf("Sound played successfully.\n");
    } else {
        printf("Failed to play sound.\n");
    }
    Sleep(5000); // Keep the program running to hear the sound
    return 0;
}

