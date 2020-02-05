#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    
    int counter_curly = 0;
    int counter_paranthesis = 0;
    int counter_bracket = 0;
    int counter_single_quote = 0;
    int counter_double_quote = 0;
    
    char c;
    while((c = getc(fin)) != EOF){
        if( c == '{'){
            ++counter_curly;
        }
        else if ( c == '}'){
            --counter_curly;
        }
        if( c == '('){
            ++counter_paranthesis;
        }
        else if( c == ')'){
            --counter_paranthesis;
        }
        if( c == '['){
            ++counter_bracket;
        }
        else if (c == ']'){
            --counter_bracket;
        }
        if (c == 39) {
            ++counter_single_quote;
        }
        else if (c == 39){
            --counter_single_quote;
        }
        if( c == '"'){
            ++counter_double_quote;
        }
        else if (c == '"'){
            --counter_double_quote;
        }
        
    }
    
    char single_quote = 39;
    char double_quote = 34;
    fclose(fin);
    fclose(fout);
    //
    if(counter_curly == 0){
        printf("There are correct amount of {}\n");
    }
    else if(counter_curly != 0){
        printf("There are uneven amount of {}\n");
    }
    //
    if(counter_paranthesis == 0){
        printf("There are correct amount of ()\n");
    }
    else if(counter_paranthesis != 0){
        printf("There are uneven amount of ()\n");
    }
    //
    if(counter_bracket == 0){
        printf("There are correct amount of []\n");
    }
    else if(counter_bracket != 0){
        printf("There are uneven amount of []\n");
    }
    //
    if(counter_single_quote == 0){
        printf("There are correct amount of %c\n", single_quote);
    }
    else if(counter_single_quote != 0){
        printf("There are uneven amount of %c\n", single_quote);
    }
    //
    if(counter_double_quote == 0){
        printf("There are correct amount of %c\n", double_quote);
    }
    else if(counter_double_quote != 0){
        printf("There are uneven amount of %c\n", double_quote);
    }
    //
    return 0;
    
}
