#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char* argv[]){
    if(argc != 3 && argc != 4){
        fprintf(stderr, "Usage: ./detab inputfile outputfile tabsteps\n");
        exit(1);
    }
    
    FILE* fin = fopen(argv[1], "r");
    FILE* fout = fopen(argv[2], "w");
    
    if(fin == NULL || fout == NULL){
        fprintf(stderr, "ERROR\n");
        exit(1);
    }
    unsigned spaces = atoi(argv[3]);
    char blanks[spaces];
    int counter = 0;
    char c;
    while((c = getc(fin)) != EOF){
        if(c != ' '){
            putc(c, fout);
        }
        else if( c == ' '){
            blanks[counter] = c;
            ++counter;
            if(counter % (spaces-1) == 0){
                putc('\t', fout);
                memset(blanks, 0, sizeof(spaces));
                }
        }
        else if( counter < (spaces -1)){
            for(int i = 0; i < spaces; ++i){
                putc(' ', fout);

            }
        }

}
    fclose(fin);
    fclose(fout);
    return 0;
    
}

