#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    const int bufferSize = 4096;
    char buffer[bufferSize];
    
    //while (fgets(buffer, bufferSize, stdin)){
        //int length = strlen(buffer);
        //buffer[length - 1] = "\0";
        //fprintf(stdout, "%s\n", buffer);
    //}

    //return 0;
    FILE *fp;
    if (argc > 1) {
        fp = fopen(argv[argc - 1], "rb");
        if (fp == NULL) {
            fprintf(stderr, "%s: %s: No such file or directory.", argv[0], argv[argc - 1]);
            exit(1);
        }
    }
    while(fgets(buffer, bufferSize, (fp == NULL ? stdin : fp))){
        int length = strlen(buffer);
        // buffer[length - 1] = "\0";
        fprintf(stdout, "%s", buffer);
    }
    return 0;
}