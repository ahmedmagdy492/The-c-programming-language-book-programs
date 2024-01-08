#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    if(argc >= 2) {
        int i = 1;
        for(; i < argc; ++i) {
            FILE* fp = fopen(argv[i], "r");
            if(fp != NULL) {
                int c;
                while((c = getc(fp)) != EOF) {
                    putchar(c);
                }
                fclose(fp);
                putchar('\n');
            }
            else {
                fprintf(stderr, "%s: can't open %s\n", argv[0], argv[i]);
                exit(1);
            }
        }
    }
    else {
        int c;
        while((c = getchar()) != EOF) {
            putchar(c);
        }
    }
}