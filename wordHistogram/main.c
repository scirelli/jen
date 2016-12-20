#include <stdio.h>

int main(int argc, char *argv[]){
    char c;
    int newlineCount = 0;

    while((c = getchar()) != EOF){
        switch(c){
            case ' ':
                c = '\n';
                newlineCount = 0;
                break;
            case '\t':
                c = '\n';
                newlineCount = 0;
                break;
            case '\n':
                newlineCount++;
                break;
            default:
                newlineCount = 0;
                c = '*';
        }
        if(newlineCount <= 0)
            printf("%c", c);
    }

    return 0;
}
