#include <stdio.h>

int main(int argc, char *argv[]){
    char c;
    int newlineCount = 0,
        charCount = 0,
        largestWord = 0;

    while((c = getchar()) != EOF){
        switch(c){
            case ' ':
            case '\t':
                c = '\n';
                printf(" (%d)", charCount);
                if(charCount > largestWord)
                    largestWord = charCount;
                newlineCount = 0;
                charCount = 0;
                break;
            case '\n':
                newlineCount++;
                charCount = 0;
                break;
            default:
                charCount++;
                c = '*';
                newlineCount = 0;
        }
        if(newlineCount <= 0)
            printf("%c", c);
    }

    printf("\n\nThe longest word in this text is %d characters long.\n\n", largestWord);
    return 0;
}
