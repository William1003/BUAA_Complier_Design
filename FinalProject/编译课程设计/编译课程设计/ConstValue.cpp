﻿/*
** @author:止水清潇menghuanlater
** @date:2017-11-22
** @location:BUAA
*/
#include "ConstValue.h"
#include <vector>
using namespace std;
//保留字
const char * keyWordsArr[KEY_NUM] = {
    "const",   "int",     "char",   "void",
    "main" ,   "if" ,     "else",   "switch",
    "case" ,   "default", "while",  "scanf",
    "printf",  "return"
};
//记忆符(凡是带SY后缀的都是保留字的记忆符)
const char * SymbolArr[SYM_NUM] = {
    "CONSTSY",      "INTSY",        "CHARSY",       "VOIDSY",
    "MAINSY",       "IFSY",         "ELSESY",       "SWITCHSY",
    "CASESY",       "DEFAULTSY",    "WHILESY",      "SCANFSY",
    "PRINTFSY",     "RETURNSY",     "IDENTIFIER",   "INTNUM",
    "STRING",       "CHAR",         "ADD",          "SUB",
    "MULT",         "DIV",          "LESS",         "LESSEQ",
    "EQUAL",        "MOREEQ",       "NOTEQ",        "MORE",
    "COMMA",        "COLON",        "SEMI",         "LSBRACKET",    
    "RSBRACKET",    "LMBRACKET",    "RMBRACKET",    "LBBRACKET",    
    "RBBRACKET",    "ASSIGN"
};
