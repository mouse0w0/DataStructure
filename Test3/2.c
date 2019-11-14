#include <stdio.h>
#include <string.h>

#define MAX_CHARS 120
#define MAX_LINE 1000

char readWord(FILE *file, char *buf);

int main() {
    printf("Enter a word:\n");
    char word[MAX_CHARS];
    scanf("%s", word);

    FILE *file = fopen("novel.txt", "r");
    char line[MAX_CHARS];

    int sumWords = 0;
    int lineWords[MAX_LINE] = {0};
    int lineNumber = 1;
    while (1) {
        char end = readWord(file, line);
        if (strcmp(word, line) == 0) {
            sumWords++;
            lineWords[lineNumber]++;
        }
        if (end == '\n') {
            lineNumber++;
        } else if (end == EOF) {
            break;
        }
    }
    fclose(file);
    printf("The number of words in the novel: %d\n", sumWords);
    printf("Line Number\tWord Count\n");
    printf("==================================\n");
    for (int i = 1; i <= lineNumber; ++i) {
        if (lineWords[i] != 0) {
            printf("%d\t\t%d\n", i, lineWords[i]);
        }
    }
}

char readWord(FILE *file, char *buf) {
    int i = 0;
    char c;
    while ((c = fgetc(file)) != ' ' && c != '\n' && c != EOF) {
        buf[i++] = c;
    }
    buf[i] = '\0';
    return c;
}