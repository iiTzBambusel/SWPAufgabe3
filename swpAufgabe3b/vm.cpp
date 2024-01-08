#include "utility.h"
#include "vm.h"


Code newPush(int i) {
  return Code(PUSHVM, i);
}

Code newPlus() {
  return Code(PLUSVM);
}

Code newMult() {
  return Code(MULTVM);
}


Optional<int> VM::run() {

      // always start with an empty stack
      stack<int> d;
      s.swap(d);

      for(unsigned int i = 0; i < code.size(); i++) {
    switch(code[i].kind) {
    case PUSHVM:
      s.push(code[i].val);
        break;
    case MULTVM: {
      int right = s.top();
      s.pop();
      int left = s.top();
      s.pop();
      s.push(left * right);
      break;
    }
    case PLUSVM: {
      int right = s.top();
      s.pop();
      int left = s.top();
      s.pop();
      s.push(left + right);
      break;
    }
    }
      }

      if(s.empty())
    return nothing<int>();

      return just<int>(s.top());
} // run
