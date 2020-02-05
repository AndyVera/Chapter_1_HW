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
    int max_char = atoi(argv[3]);
    int characters = 0;
    char c = '\0';
    while((c = getc(fin)) != EOF){
            ++characters;
            putc(c, fout);
        
            if((characters >= max_char) && (c == ' ')){
                putc('\n', fout);
                characters = 0;
            }
        }

    fclose(fin);
    fclose(fout);
    return 0;
    
}
