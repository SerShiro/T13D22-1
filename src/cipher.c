#include <stdio.h>
#include <stdlib.h>

int readAndPrintFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    int ch;
    if (file == NULL || (ch = fgetc(file)) == EOF) {
        return 0;
    }
    while (ch != EOF) {
        putchar(ch);
        ch = fgetc(file);
    }
    fclose(file);
    return 1;
}

int appendToFile(const char *filename, const char *text) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        return 0;
    }

    fputs(text, file);
    fputc('\n', file);
    fclose(file);
    return 1;
}

int main() {
    int choice = 0;
    char filename[256];
    char text[256];
    char test[100];

    while (choice != -1) {
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                (scanf("%255s", filename));
                if (!readAndPrintFile(filename)) {
                    printf("n/a");
                }
                break;

            case 2:
                if (filename[0] == '\0') {
                    scanf("%99s", test);
                    printf("n/a");
                } else {
                    scanf(" %255[^\n]", text);
                    if (!appendToFile(filename, text)) {
                        printf("n/a");
                        break;
                    }
                    if (!readAndPrintFile(filename)) {
                        printf("n/a");
                    }
                }
                break;

            case -1:
                return 0;

            default:
                printf("n/a");
        }

        while (getchar() != '\n')
            ;

        printf("\n");
    }
}
