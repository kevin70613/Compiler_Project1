#include<iostream>
#include<string>
#include<fstream>
#include<cctype>
  
using namespace std;
  
void errorCheck(string inputstr);
void charDFA(string inputstr);
void numDFA(string inputstr);
void idDFA(string inputstr);
  
fstream fileIn;
fstream fileOut;
  
int main(){
   // line for input string
  string line;
   // the line number
  int lineNum = 1;
  fileIn.open("main.c",ios::in);
  fileOut.open("token.txt",ios::out);
   
  if(!fileIn || !fileOut){  // error file can't open and exit main function
     cout << "File can't open or doesn.t exit\n";
     return 0; 
  }   
    
  while( getline(fileIn,line) ){
      // store the current front of string which doesn't check
     int front = 0;
      // check substring length
     int length = 1;
       
     int state = 0;
       
     fileOut << "Line  " << lineNum << endl;
  
     for(length=1;length<line.size()-front+1;length++ ){
          //fileOut << "front = " << front <<" , length = " << length << endl;
          string subLine = line.substr(front,length);
          // fileOut << "SubString : " << subStr << endl;
            // check the last six words
          if(subLine.size() >= 6 && !state){
               // check the keyword
             if( (subLine.substr(subLine.size()-6,6).compare("double") == 0 ||
                  subLine.substr(subLine.size()-6,6).compare("return") == 0 ||
                  subLine.substr(subLine.size()-6,6).compare("return") == 0) && subLine.size() == 6 ){
           
                 string nextStr = line.substr(front,length+1);
                   // check the next char is white space or not
                   // use isspace to check whitespace,note: this function needs char not string!
                 if( isspace(nextStr[nextStr.size()-1]) ){   // not white space and enter 
                       // check is number or not
                     numDFA(subLine.substr(0,subLine.size()-6));
                       // check is identifier or not
                     idDFA(subLine.substr(0,subLine.size()-6));
                       // check is char or not
                     charDFA(subLine.substr(0,subLine.size()-6));
                       // check is error or not
                     errorCheck(subLine.substr(0,subLine.size()-6));
        
                     fileOut << "    <Keyword>     : " << subLine.substr(subLine.size()-6,6) << endl;
                     state = 1;
                 }
             }
             else if( (subLine.substr(subLine.size()-6,6).compare("double") == 0 ||
                       subLine.substr(subLine.size()-6,6).compare("return") == 0 ||
                       subLine.substr(subLine.size()-6,6).compare("return") == 0 ) && subLine.size() > 6 ){
                       // identifier which contain those keywords
                       // check is number or not
                     numDFA(subLine.substr(0,subLine.size()-6));
                       // check is identifier or not
                     idDFA(subLine.substr(0,subLine.size()-6));
                       // check is char or not
                     charDFA(subLine.substr(0,subLine.size()-6));
                       // check is error or not
                     errorCheck(subLine.substr(0,subLine.size()-6));
                   
                     state = 1;
             }
          }
            // check the last five words
          if(subLine.size() >= 5 && !state){
                // check the keywords
             if( (subLine.substr(subLine.size()-5,5).compare("float")==0 || subLine.substr(subLine.size()-5,5).compare("while")==0 ||
                  subLine.substr(subLine.size()-5,5).compare("break")==0 || subLine.substr(subLine.size()-5,5).compare("print")==0)
                  && subLine.size()==5 ){
 
                 string nextStr2 = line.substr(front,length+1);
                   // check the next char is white space or not
                   // use isspace to check whitespace,note: this function needs char not string!
                 if( isspace(nextStr2[nextStr2.size()-1]) ){   // not white space and enter 
                       // check is number or not
                     numDFA(subLine.substr(0,subLine.size()-5));
                       // check is identifier or not
                     idDFA(subLine.substr(0,subLine.size()-5));
                       // check is char or not
                     charDFA(subLine.substr(0,subLine.size()-5));
                       // check is error or not
                     errorCheck(subLine.substr(0,subLine.size()-5));
  
                     fileOut << "    <Keyword>     : " << subLine.substr(subLine.size()-5,5) << endl;
                     state = 1;
                 }
             }
             else if( (subLine.substr(subLine.size()-5,5).compare("float")==0 ||
                       subLine.substr(subLine.size()-5,5).compare("while")==0 ||
                       subLine.substr(subLine.size()-5,5).compare("break")==0 ||
                       subLine.substr(subLine.size()-5,5).compare("print")==0 ) && subLine.size()>5 ){
                       // identifier which contain those keywords
                       // check is number or not
                     numDFA(subLine.substr(0,subLine.size()-5));
                       // check is identifier or not
                     idDFA(subLine.substr(0,subLine.size()-5));
                       // check is char or not
                     charDFA(subLine.substr(0,subLine.size()-5));
                       // check is error or not
                     errorCheck(subLine.substr(0,subLine.size()-5));
  
                     state = 1;
              }
          }
            // check the last four words
          if(subLine.size() >= 4 && !state){
               // check the keywords
             if( (subLine.substr(subLine.size()-4,4).compare("char")==0 || subLine.substr(subLine.size()-4,4).compare("else")==0)
                   && subLine.size() == 4 ){
 
                 string nextStr3 = line.substr(front,length+1);
                   // check the next char is white space or not
                   // use isspace to check whitespace,note: this function needs char not string!
                 if( isspace(nextStr3[nextStr3.size()-1]) ){   // not white space and enter 
                        // check is number or not
                      numDFA(subLine.substr(0,subLine.size()-4));
                        // check is identifier or not
                      idDFA(subLine.substr(0,subLine.size()-4));
                        // check is char or not
                      charDFA(subLine.substr(0,subLine.size()-4));
                        // check is error or not
                      errorCheck(subLine.substr(0,subLine.size()-4));
  
                      fileOut << "    <Keyword>     : " << subLine.substr(subLine.size()-4,4) << endl;
                      state = 1;
                 }
             }else if( (subLine.substr(subLine.size()-4,4).compare("char")==0 || subLine.substr(subLine.size()-4,4).compare("else")==0)
                        && subLine.size() > 4 ){ // identifier which contain those keywords
                     // check is number or not
                   numDFA(subLine.substr(0,subLine.size()-4));
                     // check is identifier or not
                   idDFA(subLine.substr(0,subLine.size()-4));
                     // check is char or not
                   charDFA(subLine.substr(0,subLine.size()-4));
                     // check is error or not
                   errorCheck(subLine.substr(0,subLine.size()-4));
  
                   state = 1;
             }
          }
            // check the last three words
          if(subLine.size() >= 3 && !state){
               // check the keywords
             if( (subLine.substr(subLine.size()-3,3).compare("int")==0 || subLine.substr(subLine.size()-3,3).compare("for")==0)
                  && subLine.size()==3 ){
 
                 string nextStr4 = line.substr(front,length+1);
                   // check the next char is white space or not
                   // use isspace to check whitespace,note: this function needs char not string!
                 if( isspace(nextStr4[nextStr4.size()-1]) ){   // not white space and enter 
                       // check is number or not
                     numDFA(subLine.substr(0,subLine.size()-3));
                       // check is identifier or not
                     idDFA(subLine.substr(0,subLine.size()-3));
                       // check is char or not
                     charDFA(subLine.substr(0,subLine.size()-3));
                       // check is error or not
                     errorCheck(subLine.substr(0,subLine.size()-3));
  
                     fileOut << "    <Keyword>     : " << subLine.substr(subLine.size()-3,3) << endl;
                     state = 1;
                 }
             }else if( (subLine.substr(subLine.size()-3,3).compare("int")==0 || subLine.substr(subLine.size()-3,3).compare("for")==0)
                        && subLine.size() > 3){// identifier which contain those keywords
                      // check is number or not
                    numDFA(subLine.substr(0,subLine.size()-3));
                      // check is identifier or not
                    idDFA(subLine.substr(0,subLine.size()-3));
                      // check is char or not
                    charDFA(subLine.substr(0,subLine.size()-3));
                      // check is error or not
                    errorCheck(subLine.substr(0,subLine.size()-3));
  
                    state = 1;
             }
          }
           // check the last two words
          if(subLine.size() >= 2 && !state){
               // check the keywords
             if( (subLine.substr(subLine.size()-2,2).compare("if") == 0) && subLine.size() == 2){
 
                 string nextStr5 = line.substr(front,length+1);
                   // check the next char is white space or not
                   // use isspace to check whitespace,note: this function needs char not string!
                 if( isspace(nextStr5[nextStr5.size()-1]) ){   // not white space and enter 
                       // check is number or not
                     numDFA(subLine.substr(0,subLine.size()-2));
                       // check is identifier or not
                     idDFA(subLine.substr(0,subLine.size()-2));
                       // check is char or not
                     charDFA(subLine.substr(0,subLine.size()-2));
                       // check is error or not
                     errorCheck(subLine.substr(0,subLine.size()-2));
  
                     fileOut << "    <Keyword>     : " << subLine.substr(subLine.size()-2,2) << endl;
                     state = 1;
                 }
             }else if( (subLine.substr(subLine.size()-2,2).compare("if") == 0) && subLine.size() > 2){
                       // identifier which contain those keywords
                       // check is number or not
                     numDFA(subLine.substr(0,subLine.size()-2));
                       // check is identifier or not
                     idDFA(subLine.substr(0,subLine.size()-2));
                       // check is char or not
                     charDFA(subLine.substr(0,subLine.size()-2));
                       // check is error or not
                     errorCheck(subLine.substr(0,subLine.size()-2));
  
                     state = 1;
            }
              // check the Operators
            if(subLine.substr(subLine.size()-2,2).compare("==") == 0 || subLine.substr(subLine.size()-2,2).compare("!=") == 0 ||
               subLine.substr(subLine.size()-2,2).compare(">=") == 0 || subLine.substr(subLine.size()-2,2).compare("<=") == 0 ||
               subLine.substr(subLine.size()-2,2).compare("&&") == 0 || subLine.substr(subLine.size()-2,2).compare("||") == 0 ){
                   // check is number or not
                 numDFA(subLine.substr(0,subLine.size()-2));
                   // check is identifier or not
                 idDFA(subLine.substr(0,subLine.size()-2));
                   // check is char or not
                 charDFA(subLine.substr(0,subLine.size()-2));
                   // check is error or not
                 errorCheck(subLine.substr(0,subLine.size()-2));
  
                 fileOut << "    <Operator>    : " << subLine.substr(subLine.size()-2,2) << endl;
                 state = 1;
             }                  
              // check comment, ignore the comment
             else if(subLine.substr(subLine.size()-2,2).compare("//")==0){
                   // check is number or not
                 numDFA(subLine.substr(0,subLine.size()-2));
                   // check is identifier or not
                 idDFA(subLine.substr(0,subLine.size()-2));
                   // check is char or not
                 charDFA(subLine.substr(0,subLine.size()-2));
                   // check is error or not
                 errorCheck(subLine.substr(0,subLine.size()-2));
  
                 length = line.size()-front+1;
                 state = 1;
             }
          }
            // check the last one word        
          if(subLine.size() >= 1 && !state){
              // check the whitespace
              // use isspace to check whitespace,note: this function needs char not string!
             if( isspace(subLine[subLine.size()-1])){
                   // check is number or not
                 numDFA(subLine.substr(0,subLine.size()-1));
                   // check is identifier or not
                 idDFA(subLine.substr(0,subLine.size()-1));
                   // check is char or not, not case ' '
                 if(!(line.substr(front,length+1).compare("' '")==0) )
                     charDFA(subLine.substr(0,subLine.size()-1));
                   // check is error or not
                 errorCheck(subLine.substr(0,subLine.size()-1));
  
                 state = 1;
 
                   // check the case ' '
                 if( line.substr(front,length+1).compare("' '")==0 ){
                    state = 0;
                 }

             }
               // check the operators
             else if(subLine.substr(subLine.size()-1,1).compare("=") == 0 || subLine.substr(subLine.size()-1,1).compare("!") == 0 ||
                     subLine.substr(subLine.size()-1,1).compare("+") == 0 || subLine.substr(subLine.size()-1,1).compare("-") == 0 ||
                     subLine.substr(subLine.size()-1,1).compare("*") == 0 || subLine.substr(subLine.size()-1,1).compare("<") == 0 ||
                     subLine.substr(subLine.size()-1,1).compare(">") == 0 ){
                  // check the next char
                 string temp = line.substr(front,length+1);
                 if(!(temp.substr(temp.size()-2,2).compare("==") == 0 || temp.substr(temp.size()-2,2).compare("!=") == 0 ||
                      temp.substr(temp.size()-2,2).compare(">=") == 0 || temp.substr(temp.size()-2,2).compare("<=") == 0 ||
                      temp.substr(temp.size()-2,2).compare("+=") == 0 || temp.substr(temp.size()-2,2).compare("-=") == 0 ||
                      temp.substr(temp.size()-2,2).compare("*=") == 0) ){
                       // check is number or not
                     numDFA(subLine.substr(0,subLine.size()-1));
                       // check is identifier or not
                     idDFA(subLine.substr(0,subLine.size()-1));
                       // check is char or not
                     charDFA(subLine.substr(0,subLine.size()-1));
                       // check is error or not
                     errorCheck(subLine.substr(0,subLine.size()-1));
  
                     fileOut << "    <Operator>    : " << subLine.substr(subLine.size()-1,1) << endl;
                     state = 1;
                 }
  
             }
                // check the special symbols
             else if(subLine.substr(subLine.size()-1,1).compare("[") == 0 || subLine.substr(subLine.size()-1,1).compare("]") == 0 ||
                     subLine.substr(subLine.size()-1,1).compare("(") == 0 || subLine.substr(subLine.size()-1,1).compare(")") == 0 ||
                     subLine.substr(subLine.size()-1,1).compare("{") == 0 || subLine.substr(subLine.size()-1,1).compare("}") == 0 ||
                     subLine.substr(subLine.size()-1,1).compare(";") == 0 || subLine.substr(subLine.size()-1,1).compare(",") == 0 ){
                   // check is number or not
                 numDFA(subLine.substr(0,subLine.size()-1));
                   // check is identifier or not
                 idDFA(subLine.substr(0,subLine.size()-1));
                   // check is char or not
                 charDFA(subLine.substr(0,subLine.size()-1));
                   // check is error or not
                 errorCheck(subLine.substr(0,subLine.size()-1));
  
                 fileOut << "    <Special>     : " << subLine.substr(subLine.size()-1,1) << endl;
                 state = 1;
             }
              // / is the special case, because // and / are ambiguous
             else if(subLine.substr(subLine.size()-1,1).compare("/") == 0){
                 string temp2 = line.substr(front,length+1);
                 if( !(temp2.substr(temp2.size()-2,2).compare("//") == 0)){
                       // check is number or not
                     numDFA(subLine.substr(0,subLine.size()-1));
                       // check is identifier or not
                     idDFA(subLine.substr(0,subLine.size()-1));
                       // check is char or not
                     charDFA(subLine.substr(0,subLine.size()-1));
                       // check is error or not
                     errorCheck(subLine.substr(0,subLine.size()-1));
  
                     fileOut << "    <Operator>    : " << subLine.substr(subLine.size()-1,1) << endl;
                     state = 1;
                 }
             }
          }
            // check has enter the state or not
          if(state == 1){
             front = front+length;
               // change front to remove subString
             length = 0;
               // length set to 0
             state = 0;
          }
     }
       // print the Line number in token.txt
     lineNum++;
  }
  fileIn.close();
  fileOut.close();
}
  
void errorCheck(string inputstr){
     // first char is number and check the other
     // state = 1 : not a number ; state = 0 : number
    int state = 1;
    if(inputstr.substr(0,1).compare("0")==0 || inputstr.substr(0,1).compare("1")==0 || inputstr.substr(0,1).compare("2")==0 ||
       inputstr.substr(0,1).compare("3")==0 || inputstr.substr(0,1).compare("4")==0 || inputstr.substr(0,1).compare("5")==0 ||
       inputstr.substr(0,1).compare("6")==0 || inputstr.substr(0,1).compare("7")==0 || inputstr.substr(0,1).compare("8")==0 ||
       inputstr.substr(0,1).compare("9")==0 ){
          // check other of the string is a number or not
         for(int i=1;i<inputstr.length();i++){
           if(inputstr.substr(i,1).compare("a")==0 || inputstr.substr(i,1).compare("b")==0 || inputstr.substr(i,1).compare("c")==0 ||
              inputstr.substr(i,1).compare("d")==0 || inputstr.substr(i,1).compare("e")==0 || inputstr.substr(i,1).compare("f")==0 ||
              inputstr.substr(i,1).compare("g")==0 || inputstr.substr(i,1).compare("h")==0 || inputstr.substr(i,1).compare("i")==0 ||
              inputstr.substr(i,1).compare("j")==0 || inputstr.substr(i,1).compare("k")==0 || inputstr.substr(i,1).compare("l")==0 ||
              inputstr.substr(i,1).compare("m")==0 || inputstr.substr(i,1).compare("n")==0 || inputstr.substr(i,1).compare("o")==0 ||
              inputstr.substr(i,1).compare("p")==0 || inputstr.substr(i,1).compare("q")==0 || inputstr.substr(i,1).compare("r")==0 ||
              inputstr.substr(i,1).compare("s")==0 || inputstr.substr(i,1).compare("t")==0 || inputstr.substr(i,1).compare("u")==0 ||
              inputstr.substr(i,1).compare("v")==0 || inputstr.substr(i,1).compare("w")==0 || inputstr.substr(i,1).compare("x")==0 ||
              inputstr.substr(i,1).compare("y")==0 || inputstr.substr(i,1).compare("z")==0 || inputstr.substr(i,1).compare("A")==0 ||
              inputstr.substr(i,1).compare("B")==0 || inputstr.substr(i,1).compare("C")==0 || inputstr.substr(i,1).compare("D")==0 ||
              inputstr.substr(i,1).compare("E")==0 || inputstr.substr(i,1).compare("F")==0 || inputstr.substr(i,1).compare("G")==0 ||
              inputstr.substr(i,1).compare("H")==0 || inputstr.substr(i,1).compare("I")==0 || inputstr.substr(i,1).compare("J")==0 ||
              inputstr.substr(i,1).compare("K")==0 || inputstr.substr(i,1).compare("L")==0 || inputstr.substr(i,1).compare("M")==0 ||
              inputstr.substr(i,1).compare("N")==0 || inputstr.substr(i,1).compare("O")==0 || inputstr.substr(i,1).compare("P")==0 ||
              inputstr.substr(i,1).compare("Q")==0 || inputstr.substr(i,1).compare("R")==0 || inputstr.substr(i,1).compare("S")==0 ||
              inputstr.substr(i,1).compare("T")==0 || inputstr.substr(i,1).compare("U")==0 || inputstr.substr(i,1).compare("V")==0 ||
              inputstr.substr(i,1).compare("W")==0 || inputstr.substr(i,1).compare("X")==0 || inputstr.substr(i,1).compare("Y")==0 ||
              inputstr.substr(i,1).compare("Z")==0 || inputstr.substr(i,1).compare("_")==0  ){
                state *= 0;
              }
         }
   }
   
   if(state == 0){
      fileOut << "    <Error>       : " << inputstr << endl;
   }
}
  
  
void charDFA(string inputstr){
   // check the first and last char of string is '
  if(inputstr.find_first_of("'")== 0 && inputstr.find_last_of("'")==inputstr.length()-1){
      fileOut << "    <Char>        : " << inputstr << endl;
   }
}
  
void numDFA(string inputstr){
     // number string length
    int count = 0;
  
    if(inputstr.substr(0,1).compare("0")==0 || inputstr.substr(0,1).compare("1")==0 || inputstr.substr(0,1).compare("2")==0 ||
       inputstr.substr(0,1).compare("3")==0 || inputstr.substr(0,1).compare("4")==0 || inputstr.substr(0,1).compare("5")==0 ||
       inputstr.substr(0,1).compare("6")==0 || inputstr.substr(0,1).compare("7")==0 || inputstr.substr(0,1).compare("8")==0 ||
       inputstr.substr(0,1).compare("9")==0 ){
        count++;
    }
     // check other of the string is a number or not
    for(int i=1;i<inputstr.length();i++){
       if(inputstr.substr(i,1).compare("0")==0 || inputstr.substr(i,1).compare("1")==0 || inputstr.substr(i,1).compare("2")==0 ||
          inputstr.substr(i,1).compare("3")==0 || inputstr.substr(i,1).compare("4")==0 || inputstr.substr(i,1).compare("5")==0 ||
          inputstr.substr(i,1).compare("6")==0 || inputstr.substr(i,1).compare("7")==0 || inputstr.substr(i,1).compare("8")==0 ||
          inputstr.substr(i,1).compare("9")==0 || inputstr.substr(i,1).compare(".")==0 ){
           count++;
       }
    }
   if(inputstr.size() != 0 && count == inputstr.size()){
       fileOut << "    <Number>      : " << inputstr << endl;
   }
}
  
void idDFA(string inputstr){
     // id string length
    int count = 0;
  
    if(inputstr.substr(0,1).compare("a")==0 || inputstr.substr(0,1).compare("b")==0 || inputstr.substr(0,1).compare("c")==0 ||
       inputstr.substr(0,1).compare("d")==0 || inputstr.substr(0,1).compare("e")==0 || inputstr.substr(0,1).compare("f")==0 ||
       inputstr.substr(0,1).compare("g")==0 || inputstr.substr(0,1).compare("h")==0 || inputstr.substr(0,1).compare("i")==0 ||
       inputstr.substr(0,1).compare("j")==0 || inputstr.substr(0,1).compare("k")==0 || inputstr.substr(0,1).compare("l")==0 ||
       inputstr.substr(0,1).compare("m")==0 || inputstr.substr(0,1).compare("n")==0 || inputstr.substr(0,1).compare("o")==0 ||
       inputstr.substr(0,1).compare("p")==0 || inputstr.substr(0,1).compare("q")==0 || inputstr.substr(0,1).compare("r")==0 ||
       inputstr.substr(0,1).compare("s")==0 || inputstr.substr(0,1).compare("t")==0 || inputstr.substr(0,1).compare("u")==0 ||
       inputstr.substr(0,1).compare("v")==0 || inputstr.substr(0,1).compare("w")==0 || inputstr.substr(0,1).compare("x")==0 ||
       inputstr.substr(0,1).compare("y")==0 || inputstr.substr(0,1).compare("z")==0 || inputstr.substr(0,1).compare("A")==0 ||
       inputstr.substr(0,1).compare("B")==0 || inputstr.substr(0,1).compare("C")==0 || inputstr.substr(0,1).compare("D")==0 ||
       inputstr.substr(0,1).compare("E")==0 || inputstr.substr(0,1).compare("F")==0 || inputstr.substr(0,1).compare("G")==0 ||
       inputstr.substr(0,1).compare("H")==0 || inputstr.substr(0,1).compare("I")==0 || inputstr.substr(0,1).compare("J")==0 ||
       inputstr.substr(0,1).compare("K")==0 || inputstr.substr(0,1).compare("L")==0 || inputstr.substr(0,1).compare("M")==0 ||
       inputstr.substr(0,1).compare("N")==0 || inputstr.substr(0,1).compare("O")==0 || inputstr.substr(0,1).compare("P")==0 ||
       inputstr.substr(0,1).compare("Q")==0 || inputstr.substr(0,1).compare("R")==0 || inputstr.substr(0,1).compare("S")==0 ||
       inputstr.substr(0,1).compare("T")==0 || inputstr.substr(0,1).compare("U")==0 || inputstr.substr(0,1).compare("V")==0 ||
       inputstr.substr(0,1).compare("W")==0 || inputstr.substr(0,1).compare("X")==0 || inputstr.substr(0,1).compare("Y")==0 ||
       inputstr.substr(0,1).compare("Z")==0 || inputstr.substr(0,1).compare("_")==0 ){
        count++;
        for(int i=1;i<inputstr.length();i++){
          if(inputstr.substr(i,1).compare("a")==0 || inputstr.substr(i,1).compare("b")==0 || inputstr.substr(i,1).compare("c")==0 ||
             inputstr.substr(i,1).compare("d")==0 || inputstr.substr(i,1).compare("e")==0 || inputstr.substr(i,1).compare("f")==0 ||
             inputstr.substr(i,1).compare("g")==0 || inputstr.substr(i,1).compare("h")==0 || inputstr.substr(i,1).compare("i")==0 ||
             inputstr.substr(i,1).compare("j")==0 || inputstr.substr(i,1).compare("k")==0 || inputstr.substr(i,1).compare("l")==0 ||
             inputstr.substr(i,1).compare("m")==0 || inputstr.substr(i,1).compare("n")==0 || inputstr.substr(i,1).compare("o")==0 ||
             inputstr.substr(i,1).compare("p")==0 || inputstr.substr(i,1).compare("q")==0 || inputstr.substr(i,1).compare("r")==0 ||
             inputstr.substr(i,1).compare("s")==0 || inputstr.substr(i,1).compare("t")==0 || inputstr.substr(i,1).compare("u")==0 ||
             inputstr.substr(i,1).compare("v")==0 || inputstr.substr(i,1).compare("w")==0 || inputstr.substr(i,1).compare("x")==0 ||
             inputstr.substr(i,1).compare("y")==0 || inputstr.substr(i,1).compare("z")==0 || inputstr.substr(i,1).compare("A")==0 ||
             inputstr.substr(i,1).compare("B")==0 || inputstr.substr(i,1).compare("C")==0 || inputstr.substr(i,1).compare("D")==0 ||
             inputstr.substr(i,1).compare("E")==0 || inputstr.substr(i,1).compare("F")==0 || inputstr.substr(i,1).compare("G")==0 ||
             inputstr.substr(i,1).compare("H")==0 || inputstr.substr(i,1).compare("I")==0 || inputstr.substr(i,1).compare("J")==0 ||
             inputstr.substr(i,1).compare("K")==0 || inputstr.substr(i,1).compare("L")==0 || inputstr.substr(i,1).compare("M")==0 ||
             inputstr.substr(i,1).compare("N")==0 || inputstr.substr(i,1).compare("O")==0 || inputstr.substr(i,1).compare("P")==0 ||
             inputstr.substr(i,1).compare("Q")==0 || inputstr.substr(i,1).compare("R")==0 || inputstr.substr(i,1).compare("S")==0 ||
             inputstr.substr(i,1).compare("T")==0 || inputstr.substr(i,1).compare("U")==0 || inputstr.substr(i,1).compare("V")==0 ||
             inputstr.substr(i,1).compare("W")==0 || inputstr.substr(i,1).compare("X")==0 || inputstr.substr(i,1).compare("Y")==0 ||
             inputstr.substr(i,1).compare("Z")==0 || inputstr.substr(i,1).compare("0")==0 || inputstr.substr(i,1).compare("1")==0 ||
             inputstr.substr(i,1).compare("2")==0 || inputstr.substr(i,1).compare("3")==0 || inputstr.substr(i,1).compare("4")==0 ||
             inputstr.substr(i,1).compare("5")==0 || inputstr.substr(i,1).compare("6")==0 || inputstr.substr(i,1).compare("7")==0 ||
             inputstr.substr(i,1).compare("8")==0 || inputstr.substr(i,1).compare("9")==0 || inputstr.substr(i,1).compare("_")==0)
               count++; 
       }
    }
      // string is not empty
    if( inputstr.size() != 0 && count == inputstr.size() ){
      fileOut << "    <Identifier>  : " << inputstr << endl;
    }
}
