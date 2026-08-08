#ifndef LEXER_H
#define LEXER_H

enum TokenType {
    KEYWORD_INT, 
    KEYWORD_FLOAT, 
    KEYWORD_BOOL, 
    KEYWORD_STRING, 
    KEYWORD_IDENTIFER, 
    KEYWORD_NAME, 
    ASSIGN, 
    PLUS, 
    MINUS, 
    SEMICOLON, 
    UNKNOW, 
    //EOF, 
    SOF, 
};

    int curent;
    int line;
    
    typedef struct 
    {
        enum TokenType type;
        char *value;
    } Token;

    Token next_token(char *code, int *pos);
    void print_token_name(enum TokenType type);

#endif 