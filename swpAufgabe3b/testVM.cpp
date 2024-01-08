#include <iostream>
#include <string>

using namespace std;

#include "vm.h"
#include "parser.h"
#include "ast.h"

void showVMRes(Optional<int> r) {
  if(r.isNothing())
    cout << "\nVM stack (top): empty";

  cout << "\nVM stack (top):" << r.fromJust();
  

}

void testVM() {

  {
    vector<Code> vc{
          newPush(1),
      newPush(2),
      newPush(3),
      newMult(),
      newPlus() };

    Optional<int> res = VM(vc).run();

    showVMRes(res);
  }
  
  {
    vector<Code> vc{
          newPush(2),
      newPush(3),
      newPush(5),
      newPlus(),
      newMult() };

    Optional<int> res = VM(vc).run();

    showVMRes(res);
  }
}
void testVM2(){
    { 
    Optional<EXP> e = Parser("1").parse();
    cout <<"\nInput: 1";
    cout <<"\nOutput supperPretty: " << e.fromJust()->supperPretty();
    vector<Code> vc = e.fromJust()->toVm();
    Optional<int> res = VM(vc).run();
    
    showVMRes(res);
  }
    { 
    Optional<EXP> e = Parser("1 + 0 ").parse();
    cout <<"\nInput: 1 + 0 ";
    cout <<"\nOutput supperPretty: " << e.fromJust()->supperPretty();
    vector<Code> vc = e.fromJust()->toVm();
    Optional<int> res = VM(vc).run();
    
    showVMRes(res);
  }
  { 
    Optional<EXP> e = Parser("1 + 2 * 0").parse();
    cout <<"\nInput: 1 + 2 * 0";
    cout <<"\nOutput supperPretty: " << e.fromJust()->supperPretty();
    vector<Code> vc = e.fromJust()->toVm();
    Optional<int> res = VM(vc).run();
    
    showVMRes(res);
  }
  { 
    Optional<EXP> e = Parser("1 * 2 + 0").parse();
    cout <<"\nInput: 1 * 2 + 0";
    cout <<"\nOutput supperPretty: " << e.fromJust()->supperPretty();
    vector<Code> vc = e.fromJust()->toVm();
    Optional<int> res = VM(vc).run();
    
    showVMRes(res);
  }
  { 
    Optional<EXP> e = Parser("(1* ( 1 + 2) * 0 )").parse();
    cout <<"\nInput: (1* ( 1 + 2) * 0 )";
    cout <<"\nOutput supperPretty: " << e.fromJust()->supperPretty();
    vector<Code> vc = e.fromJust()->toVm();
    Optional<int> res = VM(vc).run();
    
    showVMRes(res);
  }
    { 
    Optional<EXP> e = Parser("(1 + 2) * 0 + 2").parse();
    cout <<"\nInput: (1 + 2) * 0 + 2";
    cout <<"\nOutput supperPretty: " << e.fromJust()->supperPretty();
    vector<Code> vc = e.fromJust()->toVm();
    Optional<int> res = VM(vc).run();
    
    showVMRes(res);
  }
}

int main() {

  testVM();
  testVM2();
  
  return 1;
}