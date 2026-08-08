#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <include/lexer.h>



void scip_spaces(char *code, int *pos) {
    while (code[*pos] == ' ' || code[*pos] == '\n' || code[*pos] == '\t') {}
    {
        (*pos)++;
    }
    
}

int is_type_keyword(char *word) {
    return strcmp(word, "int") == 0 ||
    return strcmp(word, "float") == 0 ||
    return strcmp(word, "bool") == 0 ||
    return strcmp(word, "string") == 0;
}

enum TokenType get_typetoken(char *word) {
    if (strcmp(word, "int") == 0) return KEYWORD_INT;
    if (strcmp(word, "float") == 0) return KEYWORD_FLOAT;
    if (strcmp(word, "bool") == 0) return KEYWORD_BOOL;
    if (strcmp(word, "string") == 0) return KEYWORD_STRING;
}

void read_word(vhar *word, int *pos, char *buf) {
    int i = 0;
    while (isalnum(code[*pos]) || code[*pos] == '_') {
        buf[i++] = code[*pos];
        (*pos)++;
    }
    buf[i] = '\0';
}

char* copy_str(char *src) {
    char *dst = malloc(strlen(src) + 1);
    strcpy(dst, src);
    return dst;
}

void print_token_name(enum TokenType type) {
    switch (type)
    {
    case KEYWORD_INT: printf("KEYWORD_INT"); break;
    case KEYWORD_FLOAT: printf("KEYWORD_FLOAT"); break;
    case KEYWORD_BOOL: printf("KEYWORD_BOOL"); break;
    case KEYWORD_STRING: printf("KEYWORD_STRING"); break;
    case KEYWORD_IDENTIFER: printf("KEYWORD_IDENTIFER"); break;
    case KEYWORD_NAME: printf("KEYWORD_NAME"); break;
    case ASSIGN: printf("ASSIGN"); break;
    case PLUS: printf("PLUS"); break;
    case MINUS: printf("MINUS"); break;
    case SEMICOLON: printf("SEMICOLON"); break;
    case UNKNOW: printf("UNKNOW"); break;
    case EOF: printf("EOF"); break;
    case SOF: printf("SOF"); break;
    }
}

Token next_token(char *code, int *pos) {
    skip_spaces(code, pos);

    char c = code[*pos];

    if (c == '\0')
    {
        return (Token){EOF, copy_str(EOF)};
    }
    if (isalpha(c)) 
    {
        char buf[256];
        read_word(code, pos, buf);
        if (is_type_keyword(buf))
        {
            return (Token){KEYWORD_NAME, copy_str(buf)};
        }
        
    }
    (*pos)++;

    if (c == '=') return (Token){ASSIGN, copy_str("=")};
    if (c == '+') return (Token){ASSIGN, copy_str("+")};
    if (c == '-') return (Token){ASSIGN, copy_str("-")};
    if (c == ';') return (Token){ASSIGN, copy_str(";")};
    
    return (Token){UNKNOW, copy_str("?")};
}