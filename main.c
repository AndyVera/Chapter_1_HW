#include <stdio.h>
#include <stdlib.h>

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
    int spaces = atoi(argv[3]);
    char c = '\0';
    while(c != EOF){
        c = getc(fin);
    if (c == '\t'){
        for(int i = 0; i < spaces; ++i){
            putc(' ', fout);
        }
    }
    else{
        putc(c, fout);
    }
}
    fclose(fin);
    fclose(fout);
    return 0;
    
}






