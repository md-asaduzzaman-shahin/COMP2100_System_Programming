#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Program to use is_yes to check input line

void fail_now() {
    //Something went wrong. Report and exit.
    fprintf (stderr, "Failure\n");
    exit(1);
}

long is_yes(char *p);

int main() {
    char line[80];
    int status, len;

    // Prompt for user input
    printf("Input > ");

    // Read user input into line
    if (fgets(line, 80, stdin) == NULL)
        fail_now();

    // Strip newline off the end of user input
    len = strlen(line);
    if (len > 0 && line[len - 1] == '\n')
        line[len - 1] = '\0';

    // Check the quality of the input
    status = is_yes(line);

    // Report input quality
    if (status == 1) 
        printf("Excellent input\n");
    printf("Everything is ok\n");

    // Done
    return 0;
}
