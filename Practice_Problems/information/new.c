#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *str1, const void *str2){
    return strcmp(*(char **)str1, *(char **)str2);
}

int main() {
    char *str[2] = {
        "[C PROGRAMMING]\n"
        "CATEGORY: PERSONAL\n"
        "PRIORITY: HIGH\n"
        "DEADLINE: 2090-10-23\n\n"
        "NOTES\n"
        "C LANGUAGE WAS DEVELOPED BY DENNIS RICHIE.\n\n"
        "[/C PROGRAMMING]",

        "[ANIME]\n"
        "CATEGORY: WORK\n"
        "PRIORITY: LOW\n"
        "DEADLINE: 2024-10-28\n\n"
        "NOTES\n"
        "ANIME IS A GOOD SOURCE OF ENTERTAINMENT.\n\n"
        "[/ANIME]"
    };

    qsort(str, 2, sizeof(str[0]), compare);

    // Example of printing the strings
    for (int i = 0; i < 2; i++) {
        printf("%s\n", str[i]);
    }

    return 0;
}

