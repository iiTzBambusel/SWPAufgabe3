#include <iostream>
#include <string>

using namespace std;

#include "ast.h"
#include <vector>



/*
Methode  : eval
Klasse : IntExp
Beschreibung :
    Gibt den Wert des knotens zurück.
.
	
Parameter:
	keine

Rückgabe:  
	Numericher Wert der dem Wert dieses Knotens entspricht
*/

int IntExp::eval() { return val;}

/*
Methode  : pretty
Klasse : IntExp
Beschreibung :
    Bearbeitet den aktuellen Knoten einer Ganzzahl Ausdrucks und gibt diesem als ein Stringobjekt zurück.
.
	
Parameter:
	keine

Rückgabe:  
	ein Stringobjekt mit der Textrepresentation dieses Knotens.
*/


string IntExp::pretty() {
      return to_string(val);
}

/*
Methode  : supperPretty
Klasse : IntExp
Beschreibung :
    Bearbeitet den aktuellen Knoten einer Ganzzahl Ausdrucks und gibt diesem als ein Stringobjekt zurück.
.
	
Parameter:
	keine

Rückgabe:  
	ein Stringobjekt mit der Textrepresentation dieses Knotens.
*/
string IntExp::supperPretty(){
    return (this->pretty());
}




//////////////////////////////////////////////////////////////////
vector<Code> IntExp::toVm(){
    vector<Code> v1; //Create new Vector
    
    v1.push_back(newPush(this->eval())); //push the vm instruction onto the Vector
    
    return v1; //return the vector
}
//////////////////////////////////////////////////////////////////



/*
Methode  : eval
Klasse : IntExp
Beschreibung :
    Berehnet den wert des knotens, sowie aller Tochterknoten.
.
	
Parameter:
	keine

Rückgabe:  
	Numericher Wert der dem wert dieses Knotens sowie aller Tochterknotten entspricht
*/


int PlusExp::eval() { return e1->eval() + e2->eval(); }

/*
Methode  : pretty
Klasse : PlusExp
Beschreibung :
    Bearbeitet den Aktuellen Knoten einer Additionsausdrucks und gibt diesem als ein Stringobjekt zurück.
	Das erstellte Objekt beinhaltet neben dem eigentlichen Knotten auch alle diesem Knoten zugeordnete Tochterknoten.
	Der Gesammte Ausdruck wird in dem erstelltten Stringobjekt automatisch mit einer Anfangs- sowie endklammer versehen.
	
Parameter:
	keine

Rückgabe:  
	ein Stringobjekt mit der Textrepresentation dieses Knotens sowie allen diesem Knoten zugewisenen Tochterknoten.
*/
string PlusExp::pretty() {
    string s("(");				// "klammer öffnen" anhängen	
    s.append(e1->pretty());		// linken Knotten ausführen und das Ergebnis anhängen
    s.append("+");				// Pluszeichen anhängen
    s.append(e2->pretty());		// rechten Knotten ausführen und das Ergebnis anhängen
    s.append(")");    			// "klammer zu" anhängen	
    return s;
}


/*
Methode  : supperPretty
Klasse : PlusExp
Beschreibung :
    Bearbeitet den Aktuellen Knoten einer Additionsausdrucks und gibt diesem als ein Stringobjekt zurück.
	Das erstellte Objekt beinhaltet neben dem eigentlichen Knotten auch alle diesem Knoten zugeordnete Tochterknoten.
	Der Gesammte Ausdruck wird in dem erstelltten Stringobjekt bei bedarf mit einer Anfangs- sowie endklammer versehen.
	
Parameter:
	keine

Rückgabe:  
	ein Stringobjekt mit der Textrepresentation dieses Knotens sowie allen diesem Knoten zugewisenen Tochterknoten.
*/

string PlusExp::supperPretty(){
    string s;
    s.append(e1->supperPretty());
    s.append("+");
    s.append(e2->supperPretty());
    return s;
}



//////////////////////////////////////////////////////////////////
vector<Code> PlusExp::toVm(){
    vector<Code> v1; //Create return vector
    
    vector<Code> v2 = e1->toVm(); //Create vector of e1 instruction
    vector<Code> v3 = e2->toVm(); //Create vector of e2 instruction
    
    v1.insert(v1.end(), v2.begin(), v2.end()); //append vector of e1 instruction
    v1.insert(v1.end(), v3.begin(), v3.end()); //append vector of e2 instruction
    
    v1.push_back(newPlus()); //push the vm instruction for Plus onto the Vector
    return v1; //return the vector
}
//////////////////////////////////////////////////////////////////



/*
Methode  : eval
Klasse : MultExp
Beschreibung :
    Berehnet den wert des knotens, sowie aller Tochterknoten.
.
	
Parameter:
	keine

Rückgabe:  
	Numericher Wert der dem wert dieses Knotens sowie aller Tochterknotten entspricht
*/

int MultExp::eval() { return e1->eval() * e2->eval(); }

/*
Methode  : pretty
Klasse : MultExp
Beschreibung :
    Bearbeitet den Aktuellen Knoten eines Multiplikationsausdrucks und gibt diesem als ein Stringobjekt zurück.
	Das erstellte Objekt beinhaltet neben dem eigentlichen Knotten auch alle diesem Knoten zugeordnete Tochterknoten.
	Der Gesammte Ausdruck wird in dem erstelltten Stringobjekt automatisch mit einer Anfangs- sowie Endklammer versehen.
	
Parameter:
	keine

Rückgabe:  
	ein Stringobjekt mit der Textrepresentation dieses Knotens sowie allen diesem Knoten zugewisenen Tochterknoten.
*/
string MultExp::pretty() {
    string s("(");				// "klammer öffnen" anhängen	
    s.append(e1->pretty()); 	// linken Knotten durchwandern und das Ergebnis anhängen
    s.append("*");				// multiplikationszeichen anhängen
    s.append(e2->pretty());		// rechten Knotten ausführen und das Ergebnis anhängen
    s.append(")");    			// "klammer zu" anhängen	
    return s;
  }

/*
Methode  : supperPretty
Klasse : MultExp
Beschreibung :
    Bearbeitet den Aktuellen Knoten eines Multiplikationsausdrucks und gibt diesem als ein Stringobjekt zurück.
	Das erstellte Objekt beinhaltet neben dem eigentlichen Knotten auch alle diesem Knoten zugeordnete Tochterknoten.
	Der Gesammte Ausdruck wird in dem erstelltten Stringobjekt bei bedarf mit einer Anfangs- sowie endklammer versehen.
	
Parameter:
	keine

Rückgabe:  
	ein Stringobjekt mit der Textrepresentation dieses Knotens sowie allen diesem Knoten zugewisenen Tochterknoten.
*/
  string MultExp::supperPretty() {
    string s;
    if(typeid(*e1) == typeid(PlusExp)){
        s.append("(");
        s.append(e1->supperPretty());
        s.append(")");
        
    }   
    else{
        s.append(e1->supperPretty());
    }
    
    s.append("*");
    
    if(typeid(*e2) == typeid(PlusExp)){
        s.append("(");
        s.append(e2->supperPretty());
        s.append(")");
    }
    else{
        s.append(e2->supperPretty());
}
      return s;
  }


//////////////////////////////////////////////////////////////////
vector<Code> MultExp::toVm(){
    vector<Code> v1; //Create return Vector
    
    vector<Code> v2 = e1->toVm(); //Create vector of e1 instruction
    vector<Code> v3 = e2->toVm(); //Create vector of e2 instruction
    
    v1.insert(v1.end(), v2.begin(), v2.end()); //append vector of e1 instruction
    v1.insert(v1.end(), v3.begin(), v3.end()); //append vector of e2 instruction
    
    v1.push_back(newMult()); //push the vm instruction for Mult onto the Vector
    return v1; //return the vector
}
//////////////////////////////////////////////////////////////////



/*
Methode  : newInt
Klasse : IntExp
Beschreibung :
    Erstellt einem neuem Ausdruck/Objekt vom typ IntExp.
	Der neu erstellter Knoten ist immer ein Endknoten und bestzt selbst keine Äste.

Parameter:
	i - wert des Knotens.

Rückgabe:  
	ein Objekt vom Typ IntExp
*/


EXP newInt(int i) {
  return std::make_shared<IntExp>(i);
}
/*
Methode  : newPlus
Klasse : PlusExp
Beschreibung :
    Erstellt einem neuem Ausdruck/Objekt vom typ PlusExp.
	Der Objekt PlusExp ist ein Knoten der immer zwei Äste besitz.
	Dem knoten werden die beiden als Parameter angegebenen Expresionen ala linker und rechter Ast zugewiesen.
	
	Beispiele:
	
	2 + 4
	
	  +
	 / \
	2   4

Eine der zugewisenen Ausdrück kann wiederum wieitere Äaste anthalten: (ohne Gewähr da nur vermutung, nicht getestet)

   2 + 4 * 5

	  +
	 / \
	2   *
       / \
	  4   5


Parameter:
	l - linker Ausdruck
	r - rechter Ausdruck
	
rückgabe:
		ein Objekt vom Typ PlusExp
*/
EXP newPlus(EXP l, EXP r) {
  return std::make_shared<PlusExp>(l,r);
}

/*
Methode  : newMult
Klasse : MultExp
Beschreibung :
    Erstellt einem neuem Ausdruck/Objekt vom typ MultExp.
	Der Objekt MultExp ist ein Knoten der immer zwei Äste besitz.
	Dem Knoten werden die beiden als Parameter angegebenen Expresionen ala linker und rechter Ast zugewiesen.
	
	Beispiele:
	
	2 * 4
	
	  *
	 / \
	2   4

Eine der zugewisenen Ausdrück kann wiederum wieitere Äaste anthalten:

    2 * 4 * 5
    
         *
  	    / \
  	   2   *
         / \
  	     4   5

wie der Ausdruck genau zerlegt wird mus ich erst mit dem debugger herausfinden, zumindest der Online GDB mag den Quelltext nicht richtig debuggen.

Parameter:
	l - linker Ausdruck
	r - rechter Ausdruck
	
rückgabe:
		ein Objekt vom Typ MultExp
*/

EXP newMult(EXP l, EXP r) {
  return std::make_shared<MultExp>(l,r);
}