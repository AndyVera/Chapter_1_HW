#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//hello there
//this comment is going to get removed after this program executes
//see ya later
//


int main(int argc, const char* argv[]){
    if(argc != 2 && argc != 3){
        fprintf(stderr, "Usage: ./detab inputfile outputfile tabsteps\n");
        exit(1);
    }
    
    FILE* fin = fopen(argv[1], "r");
    FILE* fout = fopen(argv[2], "w");
    
    if(fin == NULL || fout == NULL){
        fprintf(stderr, "ERROR\n");
        exit(1);
    }
    
    int counter = 0;
    int flag = 0;
    //0 for out and 1 for true
    char c;
    while((c = getc(fin)) != EOF){
        if( c == '/'){
            ++counter;
            if(counter % 2 != 0){
                flag = 1;
            }
        
        }
        if(flag != 1){
            putc(c, fout);
        }
        if(c == '\n' || c == '"' || c == 39){
            flag = 0;
        }
    }

    fclose(fin);
    fclose(fout);
    return 0;
    
}
