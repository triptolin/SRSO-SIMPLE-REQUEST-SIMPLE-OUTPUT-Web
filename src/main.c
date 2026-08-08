#include <src/include/lexer.h>
#include <include/test.h>
#include <stdio.h>
#include <stdlib.h>


char* read_file(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f)
    {
        printf("Faila nety\n");
        return NULL;
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    
    char *buf = malloc(size + 1);
    fread(buf, 1, size, f);
    buf[size] = '\0';

    fclose(f);
    return buf;
}

int main() {
    char *code = read_file("main.srso");
    if (!code) return 1;

    int pos = 0;
    Token t;
    
    do {
        t = next_token(code, &pos);
        print_token_name(t.type);
        printf(" %s\n", t.value);
        free(t.value);
    } while (t.type != EOF);
    
    free(code);
    return 0;
}