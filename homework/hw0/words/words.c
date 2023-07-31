#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    int i, N=0;
    char word[3];
    char str[100];
    FILE *ifile;

    if (argc > 1) {
        for (i=1; i<argc; i++) {
            ifile = fopen(argv[i], "r");
            while (fscanf(ifile, "%s", &word) != EOF) {
                //printf("%s %d word is %s\n", argv[i], i, word);
                N++;
            }
            fclose(ifile);
        }
        
    } else {
        fgets(str, 100, stdin);
        //scanf(" %[^\n]", &str);
        int i;
        int end;
        int start = 0;

        for (i = 0; i < strlen(str); i++) {

        if (str[i] == ' ' || i == strlen(str) - 1) {
            end = i;
            //printf("%.*s\n", (end - start), str + start);
            start = i + 1;
            N++;
            }
        }
    }
    printf("The total number of words is: %d\n", N);
    
    return 0;
}
