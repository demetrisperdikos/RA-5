#include <iostream>
#include <cctype>
#include <string>
#include "lex.h"
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

LexItem id_or_kw(const string & lexeme, int linenum) {
    
    Token token;
   
 map<string,Token>  check /*map for checking*/  = {
        {"PROGRAM", PROGRAM /*declare map Program*/},
        {"REPEAT", IDENT /*declare map IDENT for repeat */},
        {"WRITELN", WRITELN /*declare map writeln */},
        { "INTEGER", INTEGER /*declare map integer*/},
        { "BEGIN", BEGIN /*declare map begin*/},
        { "END", END /*declare map end */},
        { "IF", IF  /*declare map if*/},
        { "REAL", REAL /*declare map real*/},
        {"STRING", STRING /*declare map string*/},
        { "VAR", VAR /*declare map var*/},
        { "ELSE", ELSE /*declare map else*/},
        { "FOR", FOR /*declare map for*/},
        {"THEN", THEN /*declare map THEN*/}, 
        { "DO", DO /*declare map DO*/},
        { "TO", TO /*declare map TO*/},
        { "DOWNTO", DOWNTO /*declare map Downto*/}
};
    

    if (check[lexeme] == PROGRAM/*checking with program*/) {
      token = check[lexeme];
    } 
    
    else if (check[lexeme] == WRITELN/*checking with WRITELN*/) {
      token = check[lexeme];
    }
    
    else if (check[lexeme] == INTEGER/*checking with INTEGER*/) {
      token = check[lexeme];
    }
    
    else if (check[lexeme] == BEGIN/*checking with BEGIN*/) {
      token = check[lexeme];
    }
    
    else if (check[lexeme] == END/*checking with END*/) {
      token = check[lexeme];
    } 
    
    else if (check[lexeme] == IF/*checking with IF*/) {
      token = check[lexeme];
    } 
    
    else if (check[lexeme] == REAL/*checking with REAL*/) {
      token = check[lexeme];
    }
    
    else if (check[lexeme] == STRING/*checking with STRING*/) {
      token = check[lexeme];
    }
    
    
     else if (check[lexeme] == VAR/*checking with VAR*/) {
      token = check[lexeme];
    }
    
    
     else if (check[lexeme] == ELSE/*checking with ELSE*/) {
      token = check[lexeme];
    }

     else if (check[lexeme] == FOR/*checking with FOR*/) {
      token = check[lexeme];
    }

      else if (check[lexeme] == THEN/*checking with THEN*/) {
      token = check[lexeme];
    }
     
else if (check[lexeme] == DO/*checking with DO*/) {
      token = check[lexeme];
    }
    
      else if (check[lexeme] == TO/*checking with TO*/) {
      token = check[lexeme];
    }
    
      else if (check[lexeme] == DOWNTO/*checking with DOWNTO*/) {
      token = check[lexeme];
    }
    
    else {
      token = IDENT/*making token equal ident*/;
    }
    
       if (lexeme == "circle"/*if it is circle*/
           ||lexeme ==  "square"/*OR square*/
           ||lexeme ==  "rectangle"/*OR rectangle*/
           || lexeme ==  "ellipse"/*OR ellipse*/){
        token = IDENT/*IDENT then declared*/;
       }
    
    return {token, lexeme, linenum} /*returns the needed values*/;
}

ostream& operator << (ostream& COUT, const LexItem& tok) {
    

 map<Token,string>   printer/*to print the items*/ = {
        {PROGRAM, "PROGRAM"/*program being named into string*/},
        {WRITELN, "WRITELN"/*WRITELN being named into string*/},
        {  INTEGER , "INTEGER"/*INTEGER being named into string*/},
        {  BEGIN , "BEGIN"/*BEGIN being named into string*/},
        {  END , "END"/*END being named into string*/},
        {  IF , "IF" /*IF being named into string*/},
        {  REAL , "REAL" /*REAL being named into string*/},
        { STRING , "STRING"/*STRING being named into string*/},
        {  VAR , "VAR"/*VAR being named into string*/},
        {  ELSE , "ELSE" /*ELSE being named into string*/},
        {  FOR , "FOR" /*FOR being named into string*/},
        { THEN , "THEN"/*THEN being named into string*/},
        {  DO , "DO" /*DO being named into string*/},
        {  TO , "TO" /*TO being named into string*/},
        {  DOWNTO , "DOWNTO"/*DOWNTO being named into string*/ },
        {  IDENT , "IDENT"/*IDENT being named into string*/},
        {  ICONST , "ICONST"/*ICONST being named into string*/ },
        {  RCONST , "RCONST"/*RCONST being named into string*/ },
        { SCONST , "SCONST"/*SCONST being named into string*/},
        {  PLUS , "PLUS" /*PLUS being named into string*/},
        {  MINUS , "MINUS" /*MINUS being named into string*/},
        {  MULT , "MULT" /*MULT being named into string*/},
        {  DIV , "DIV"/*DIV being named into string*/},
        {  ASSOP , "ASSOP" /*ASSOP being named into string*/},
        {  LPAREN , "LPAREN"/*LPAREN being named into string*/ },
        { RPAREN , "RPAREN"/*RPAREN being named into string*/},
        {  COMMA , "COMMA" /*COMMA being named into string*/},
        {  EQUAL , "EQUAL" /*EQUAL being named into string*/},
        {  GTHAN , "GTHAN" /*GTHAN being named into string*/},    
        {  LTHAN , "LTHAN" /*LTHAN being named into string*/},
        {  SEMICOL , "SEMICOL"/*SEMICOL being named into string*/ },
        { COLON , "COLON"/*COLON being named into string*//*END being named into string*/},
        {  ERR , "ERR" /*ERR being named into string*/},
        {  DONE , "DONE" /*DONE being named into string*/}  
};

   if (printer[tok.GetToken()] == "IDENT"/*IF to display the IDENT line#*/) {
        COUT/*cout is not actual cout*/ << "IDENT "/*actual COUT overloaded*/ << "("<< tok.GetLexeme() << ") Line #: " << tok.GetLinenum() << std::endl;
    } 
    
    else if(printer[tok.GetToken()] == "ERR"/*OVERLOADING printer and showing results with ERR*/) {
        COUT/*cout is not actual cout*/ << printer[tok.GetToken()] << " ("<< tok.GetLexeme() << ") Line #: " << tok.GetLinenum() << std::endl;
    }
    
    else if (printer[tok.GetToken()] == "ICONST"/*printing overload iconst*/ || printer[tok.GetToken()] == "SCONST" || printer[tok.GetToken()] == "RCONST" /**/) {
        COUT/*cout is not actual cout*//*cout is not actual cout*/ << printer[tok.GetToken()] << " ("<< tok.GetLexeme() << ") Line #: " << tok.GetLinenum() << std::endl;
    }
    
    else {
        COUT/*cout is not actual cout*/ << printer[tok.GetToken()] << " ("<< tok.GetLexeme() << ") Line #: " << tok.GetLinenum() << std::endl/**/;
    }
    
    return COUT/*returns results*/;
}