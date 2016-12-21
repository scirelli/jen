#include <stdio.h>

int main(int argc, char *argv[]){
    const unsigned int MAX_WORDS = 5;
    const char TAB     = '\t',
               NEWLINE = '\n',
               SPACE   = ' ',
               STAR    = '*';

    char c;
    unsigned int wordCount = 0,
                 words[MAX_WORDS],
                 indexOfLongestWord = 0;
    
    for(int i=0; i<MAX_WORDS; i++) {
        words[i] = 0;
    }

    while((c = getchar()) != EOF && wordCount < MAX_WORDS){
        switch(c){
            case TAB:
            case NEWLINE:
            case SPACE:
                wordCount++;
                break;
            default:
                words[wordCount]++;
        }
    }

    for(int i=0; i<MAX_WORDS; i++) {
        if( words[indexOfLongestWord] < words[i] ){
            indexOfLongestWord = i;
        }
    }

    printf("\n\nThe longest word in this text is %d characters long.\n\n", wordCount);

    for(int rowIndex=0, rowLength=words[indexOfLongestWord], rowHeight=0; rowIndex<rowLength; rowIndex++){
        rowHeight = (MAX_WORDS-1) - rowIndex;
        printf("%c", SPACE);
        for(int colIndex=0, curWordHeight=0; colIndex<MAX_WORDS; colIndex++){
            curWordHeight = words[colIndex];
            if(curWordHeight < rowHeight){
                printf("%c ", SPACE);
            }else{
                printf("%c ", STAR);
            }
        }
        printf("%c", NEWLINE);
    }
    
    for(int i=0; i<MAX_WORDS; i++) {
        printf("%s", "__");
    }
    printf("_%c", '\n');

    return 0;
}
