#include <iostream>
#include <string>

using namespace std;


#include "parser.h"
#include "ast.h"



void display(Optional<EXP> e) {
  if(e.isNothing()) {
    cout << "nothing \n";
  } else {
    cout << (e.fromJust())->pretty() << "\n";
  }
  return;
}

void superDisplay(Optional<EXP> e) {
  if(e.isNothing()) {
    cout << "nothing \n";
  } else {
    cout << (e.fromJust())->superPretty() << "\n";
  }
  return;
}


void testParserGood() {

cout << "display: ";
  display(Parser("1").parse());
cout << "display: ";
  display(Parser("1 + 0 ").parse());
cout << "display: ";
  display(Parser("1 + (0) ").parse());
cout << "display: ";
  display(Parser("1 + 2 * 0 ").parse());
cout << "display: ";
  display(Parser("1 * 2 + 0 ").parse());
cout << "display: ";
  display(Parser("(1* ( 1 + 2) * 0 )").parse());
cout << "display: ";
  display(Parser("(1 + 2) * 0 + 2").parse());
}
void testParserSuperGood() {

cout << "display: ";
  display(Parser("1").parse());
    cout << "superDisplay: ";
    superDisplay(Parser("1").parse());
cout << "display: ";
  display(Parser("1 + 0 ").parse());
    cout << "superDisplay: ";
    superDisplay(Parser("1 + 0 ").parse());
cout << "display: ";
  display(Parser("1 + (0) ").parse());
    cout << "superDisplay: ";
    superDisplay(Parser("1 + (0) ").parse());
cout << "display: ";
  display(Parser("1 + 2 * 0 ").parse());
    cout << "superDisplay: ";
    superDisplay(Parser("1 + 2 * 0 ").parse());
cout << "display: ";
  display(Parser("1 * 2 + 0 ").parse());
    cout << "superDisplay: ";
    superDisplay(Parser("1 * 2 + 0 ").parse());
cout << "display: ";
  display(Parser("(1* ( 1 + 2) * 0 )").parse());
    cout << "superDisplay: ";
    superDisplay(Parser("(1* ( 1 + 2) * 0 )").parse());
cout << "display: ";
  display(Parser("(1 + 2) * 0 + 2").parse());
    cout << "superDisplay: ";
    superDisplay(Parser("(1 + 2) * 0 + 2").parse());
    
}

void testParser() {

  testParserGood();
  testParserSuperGood();
}


int main() {

    testParser();

  return 1;
}