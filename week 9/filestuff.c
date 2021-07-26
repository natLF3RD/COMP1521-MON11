#include <stdio.h>


int main (int argc, char* argv[] ) {

    printf ("%c%c%c%c%c%c", 72, 101, 0x6c, 108, 111, 0x0a);

    // FILE* fp = fopen(argv[1], "w");
    
    // if (fp == NULL) {
    //     // it failed.
    //     perror("file failed to open to read");
    // }
    
    // int ch = fgetc(stdin);
    // while (ch != '\n') {
    //     fputc(ch, fp);
    //     ch = fgetc(stdin);
    // }
    
    // fclose(fp);
    
    // printf("next");
    
    // fp = fopen(argv[1], "a");

    // ch = fgetc(stdin);
    // while (ch != EOF) {
    //     fputc(ch, fp);
    //     ch = fgetc(stdin);
    // }
    
    // fclose(fp);

    // return 0;
}