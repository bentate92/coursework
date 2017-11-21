
/**********************************************************************
 ** Program Filename: assignment3Main.cpp
 ** Author: Benjamin Tate
 ** Date: 2/14/16
 ** Description: Provides prompts for user to select a matchup, manages
 **   selected battle(s)
 ** Input: Choice of matchup(s), choice of whether to continue after
 ** Output: Prompts for user
 *********************************************************************/

#include "Barbarian.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "Potter.hpp"
#include "BlueMen.hpp"
#include <string>

using namespace std;

int main() {
  /*Create int to hold matchup selection*/
  int selection;
  /*Initialize string to hold continuation selection, start as "y"*/
  string cont = "y";

  /*Keep providing matchup selection as long as user wishes*/
  while(cont == "y") {
    /*Print matchup choices and accept user input*/
    cout << "\nWhich fight would you like to see?" << endl;
    cout << "1 -- Barbarian v. Barbarian" << endl;
    cout << "2 -- Barbarian v. Medusa" << endl;
    cout << "3 -- Barbarian v. Vampire" << endl;
    cout << "4 -- Barbarian v. Harry Potter" << endl;
    cout << "5 -- Barbarian v. Blue Men" << endl;
    cout << "6 -- Medusa v. Medusa" << endl;
    cout << "7 -- Medusa v. Vampire" << endl;
    cout << "8 -- Medusa v. Harry Potter" << endl;
    cout << "9 -- Medusa v. Blue Men" << endl;
    cout << "10 - Vampire v. Vampire" << endl;
    cout << "11 - Vampire v. Harry Potter" << endl;
    cout << "12 - Vampire v. Blue Men" << endl;
    cout << "13 - Harry Potter v. Harry Potter" << endl;
    cout << "14 - Harry Potter v. Blue Men" << endl;
    cout << "15 - Blue Men v. Blue Men" << endl;
    cin >> selection;

    /*Initialize chosen battle*/
    if(selection == 1) { 
      /*Print character names*/
      cout << "\nBarbarian 1 v. Barbarian 2:" << endl;

      /*Create necessary character objects*/
      Barbarian b1;
      Barbarian b2;
      
      /*Commence battle*/
      cout << "Ready.... FIGHT!" << endl;
    
      /*Initialize round counter to 1*/
      int round = 1;
    
      /*Repeat battle until one or both characters are defeated*/
      while(b1.getStr() > 0 && b2.getStr() > 0) {
        /*Print current round*/
        cout << "\nRound " << round << ":" << endl;

        /*1st character attacks*/    
        b1.attack();
        /*Print 1st character's attack power*/
        cout << "Barbarian 1 attack = " << b1.getAtt() << endl;
        /*2nd character defends against attack*/
        b2.defend(b1.getAtt());
        /*Print 2nd character's defense power*/
        cout << "Barbarian 2 defense = " << b2.getDef() << endl;
        /*Print 2nd character's remaining strength*/
        cout << "Barbarian 2 strength = " << b2.getStr() << endl;

        /*2nd character attacks*/   
        b2.attack();
        /*Print 2nd character's attack power*/
        cout << "Barbarian 2 attack = " << b2.getAtt() << endl;
        /*1st character defends against attack*/
        b1.defend(b2.getAtt());
        /*Print 1st character's defense power*/
        cout << "Barbarian 1 defense = " << b1.getDef() << endl;
        /*Print 1st character's remaining strength*/
        cout << "Barbarian 1 strength = " << b1.getStr() << endl;
    
        /*Increment round counter*/
        round++;
      }
    
      /*Determine and print results*/
      if(b1.getStr() <= 0 && b2.getStr() > 0) {
        cout << "\nBarbarian 2 wins!" << endl;
      }
      else if(b1.getStr() > 0 && b2.getStr() <= 0) {
        cout << "\nBarbarian 1 wins!" << endl;
      }
      else if(b1.getStr() <= 0 && b2.getStr() <= 0) {
        cout << "\nDraw!" << endl;
      }
    } else if(selection == 2) {
      cout << "\nBarbarian v. Medusa:" << endl;
    
      Barbarian b;
      Medusa m;
    
      cout << "Ready.... FIGHT!" << endl;
    
      int round = 1;
    
      while(b.getStr() > 0 && m.getStr() > 0) {
        cout << "\nRound " << round << ":" << endl;
    
        b.attack();
        cout << "Barbarian attack = " << b.getAtt() << endl;
        m.defend(b.getAtt());
        cout << "Medusa defense = " << m.getDef() << endl;
        cout << "Medusa strength = " << m.getStr() << endl;
    
        m.attack();
        cout << "Medusa attack = " << m.getAtt() << endl;
        b.defend(m.getAtt());
        cout << "Barbarian defense = " << b.getDef() << endl;
        cout << "Barbarian strength = " << b.getStr() << endl;
    
        round++;
      }
    
      if(m.getStr() <= 0 && b.getStr() > 0) {
        cout << "\nBarbarian wins!" << endl;
      }
      else if(m.getStr() > 0 && b.getStr() <= 0) {
        cout << "\nMedusa wins!" << endl;
      }
      else if(m.getStr() <= 0 && b.getStr() <= 0) {
        cout << "\nDraw!" << endl;
      }
    } else if(selection == 3) {
      cout << "\nBarbarian v. Vampire:" << endl;
    
      Barbarian b;
      Vampire v;
    
      cout << "Ready.... FIGHT!" << endl;
    
      int round = 1;
    
      while(v.getStr() > 0 && b.getStr() > 0) {
        cout << "\nRound " << round << ":" << endl;
    
        b.attack();
        cout << "Barbarian attack = " << b.getAtt() << endl;
        v.defend(b.getAtt());
        cout << "Vampire defense = " << v.getDef() << endl;
        cout << "Vampire strength = " << v.getStr() << endl;
    
        v.attack();
        cout << "Vampire attack = " << v.getAtt() << endl;
        b.defend(v.getAtt());
        cout << "Barbarian defense = " << b.getDef() << endl;
        cout << "Barbarian strength = " << b.getStr() << endl;
    
        round++;
      }
    
      if(v.getStr() <= 0 && b.getStr() > 0) {
        cout << "\nBarbarian wins!" << endl;
      }
      else if(v.getStr() > 0 && b.getStr() <= 0) {
        cout << "\nVampire wins!" << endl;
      }
      else if(v.getStr() <= 0 && b.getStr() <= 0) {
        cout << "\nDraw!" << endl;
      }
    } else if(selection == 4) {
      cout << "\nBarbarian v. Harry Potter:" << endl;
    
      Barbarian b;
      Potter p;
    
      cout << "Ready.... FIGHT!" << endl;
    
      int round = 1;
    
      while(p.getStr() > 0 && b.getStr() > 0) {
        cout << "\nRound " << round << ":" << endl;
    
        b.attack();
        cout << "Barbarian attack = " << b.getAtt() << endl;
        p.defend(b.getAtt());
        cout << "Harry Potter defense = " << p.getDef() << endl;
        cout << "Harry Potter strength = " << p.getStr() << endl;
    
        p.attack();
        cout << "Harry Potter attack = " << p.getAtt() << endl;
        b.defend(p.getAtt());
        cout << "Barbarian defense = " << b.getDef() << endl;
        cout << "Barbarian strength = " << b.getStr() << endl;
    
        round++;
      }
    
      if(p.getStr() <= 0 && b.getStr() > 0) {
        cout << "\nBarbarian wins!" << endl;
      }
      else if(p.getStr() > 0 && b.getStr() <= 0) {
        cout << "\nHarry Potter wins!" << endl;
      }
      else if(p.getStr() <= 0 && b.getStr() <= 0) {
        cout << "\nDraw!" << endl;
      }
    } else if(selection == 5) { 
      cout << "\nBarbarian v. Blue Men:" << endl;
    
      Barbarian b;
      BlueMen x;
    
      cout << "Ready.... FIGHT!" << endl;
    
      int round = 1;
    
      while(x.getStr() > 0 && b.getStr() > 0) {
        cout << "\nRound " << round << ":" << endl;
    
        b.attack();
        cout << "Barbarian attack = " << b.getAtt() << endl;
        x.defend(b.getAtt());
        cout << "Blue Men defense = " << x.getDef() << endl;
        cout << "Blue Men strength = " << x.getStr() << endl;
    
        x.attack();
        cout << "Blue Men attack = " << x.getAtt() << endl;
        b.defend(x.getAtt());
        cout << "Barbarian defense = " << b.getDef() << endl;
        cout << "Barbarian strength = " << b.getStr() << endl;
    
        round++;
      }
    
      if(x.getStr() <= 0 && b.getStr() > 0) {
        cout << "\nBarbarian wins!" << endl;
      }
      else if(x.getStr() > 0 && b.getStr() <= 0) {
        cout << "\nThe Blue Men win!" << endl;
      }
      else if(x.getStr() <= 0 && b.getStr() <= 0) {
        cout << "\nDraw!" << endl;
      }
    } else if(selection == 6) {
      cout << "\nMedusa 1 v. Medusa 2:" << endl;
    
      Medusa m1;
      Medusa m2;
    
      cout << "Ready.... FIGHT!" << endl;
    
      int round = 1;
    
      while(m2.getStr() > 0 && m1.getStr() > 0) {
        cout << "\nRound " << round << ":" << endl;
    
        m1.attack();
        cout << "Medusa 1 attack = " << m1.getAtt() << endl;
        m2.defend(m1.getAtt());
        cout << "Medusa 2 defense = " << m2.getDef() << endl;
        cout << "Medusa 2 strength = " << m2.getStr() << endl;
    
        m2.attack();
        cout << "Medusa 2 attack = " << m2.getAtt() << endl;
        m1.defend(m2.getAtt());
        cout << "Medusa 1 defense = " << m1.getDef() << endl;
        cout << "Medusa 1 strength = " << m1.getStr() << endl;
    
        round++;
      }
    
      if(m1.getStr() <= 0 && m2.getStr() > 0) {
        cout << "\nMedusa 2 wins!" << endl;
      }
      else if(m1.getStr() > 0 && m2.getStr() <= 0) {
        cout << "\nMedusa 1 wins!" << endl;
      }
      else if(m1.getStr() <= 0 && m2.getStr() <= 0) {
        cout << "\nDraw!" << endl;
      }
    } else if(selection == 7) {
      cout << "\nMedusa v. Vampire:" << endl;
    
      Medusa m;
      Vampire v;
    
      cout << "Ready.... FIGHT!" << endl;
    
      int round = 1;
    
      while(v.getStr() > 0 && m.getStr() > 0) {
        cout << "\nRound " << round << ":" << endl;
    
        m.attack();
        cout << "Medusa attack = " << m.getAtt() << endl;
        v.defend(m.getAtt());
        cout << "Vampire defense = " << v.getDef() << endl;
        cout << "Vampire strength = " << v.getStr() << endl;
    
        v.attack();
        cout << "Vampire attack = " << v.getAtt() << endl;
        m.defend(v.getAtt());
        cout << "Medusa defense = " << m.getDef() << endl;
        cout << "Medusa strength = " << m.getStr() << endl;
    
        round++;
      }
    
      if(v.getStr() <= 0 && m.getStr() > 0) {
        cout << "\nMedusa wins!" << endl;
      }
      else if(v.getStr() > 0 && m.getStr() <= 0) {
        cout << "\nVampire wins!" << endl;
      }
      else if(v.getStr() <= 0 && m.getStr() <= 0) {
        cout << "\nDraw!" << endl;
      }
    } else if(selection == 8) {
      cout << "\nMedusa v. Harry Potter:" << endl;
    
      Medusa m;
      Potter p;
    
      cout << "Ready.... FIGHT!" << endl;
    
      int round = 1;
    
      while(p.getStr() > 0 && m.getStr() > 0) {
        cout << "\nRound " << round << ":" << endl;
    
        m.attack();
        cout << "Medusa attack = " << m.getAtt() << endl;
        p.defend(m.getAtt());
        cout << "Harry Potter defense = " << p.getDef() << endl;
        cout << "Harry Potter strength = " << p.getStr() << endl;
    
        p.attack();
        cout << "Harry Potter attack = " << p.getAtt() << endl;
        m.defend(p.getAtt());
        cout << "Medusa defense = " << m.getDef() << endl;
        cout << "Medusa strength = " << m.getStr() << endl;
    
        round++;
      }
    
      if(p.getStr() <= 0 && m.getStr() > 0) {
        cout << "\nMedusa wins!" << endl;
      }
      else if(p.getStr() > 0 && m.getStr() <= 0) {
        cout << "\nHarry Potter wins!" << endl;
      }
      else if(p.getStr() <= 0 && m.getStr() <= 0) {
        cout << "\nDraw!" << endl;
      }
    } else if(selection == 9) { 
      cout << "\nMedusa v. Blue Men:" << endl;
    
      Medusa m;
      BlueMen x;
    
      cout << "Ready.... FIGHT!" << endl;
    
      int round = 1;
    
      while(x.getStr() > 0 && m.getStr() > 0) {
        cout << "\nRound " << round << ":" << endl;
    
        m.attack();
        cout << "Medusa attack = " << m.getAtt() << endl;
        x.defend(m.getAtt());
        cout << "Blue Men defense = " << x.getDef() << endl;
        cout << "Blue Men strength = " << x.getStr() << endl;
    
        x.attack();
        cout << "Blue Men attack = " << x.getAtt() << endl;
        m.defend(x.getAtt());
        cout << "Medusa defense = " << m.getDef() << endl;
        cout << "Medusa strength = " << m.getStr() << endl;
    
        round++;
      }
    
      if(x.getStr() <= 0 && m.getStr() > 0) {
        cout << "\nMedusa wins!" << endl;
      }
      else if(x.getStr() > 0 && m.getStr() <= 0) {
        cout << "\nThe Blue Men win!" << endl;
      }
      else if(x.getStr() <= 0 && m.getStr() <= 0) {
        cout << "\nDraw!" << endl;
      }
    } else if(selection == 10) {
      cout << "\nVampire 1 v. Vampire 2:" << endl;
    
      Vampire v1;
      Vampire v2;
    
      cout << "Ready.... FIGHT!" << endl;
    
      int round = 1;
    
      while(v1.getStr() > 0 && v2.getStr() > 0) {
        cout << "\nRound " << round << ":" << endl;
    
        v1.attack();
        cout << "Vampire 1 attack = " << v1.getAtt() << endl;
        v2.defend(v1.getAtt());
        cout << "Vampire 2 defense = " << v2.getDef() << endl;
        cout << "Vampire 2 strength = " << v2.getStr() << endl;
    
        v2.attack();
        cout << "Vampire 2 attack = " << v2.getAtt() << endl;
        v1.defend(v2.getAtt());
        cout << "Vampire 1 defense = " << v1.getDef() << endl;
        cout << "Vampire 1 strength = " << v1.getStr() << endl;
    
        round++;
      }
    
      if(v1.getStr() <= 0 && v2.getStr() > 0) {
        cout << "\nVampire 2 wins!" << endl;
      }
      else if(v1.getStr() > 0 && v2.getStr() <= 0) {
        cout << "\nVampire 1 wins!" << endl;
      }
      else if(v1.getStr() <= 0 && v2.getStr() <= 0) {
        cout << "\nDraw!" << endl;
      }
    } else if(selection == 11) {
      cout << "\nVampire v. Harry Potter:" << endl;
    
      Vampire v;
      Potter p;
    
      cout << "Ready.... FIGHT!" << endl;
    
      int round = 1;
    
      while(p.getStr() > 0 && v.getStr() > 0) {
        cout << "\nRound " << round << ":" << endl;
    
        v.attack();
        cout << "Vampire attack = " << v.getAtt() << endl;
        p.defend(v.getAtt());
        cout << "Harry Potter defense = " << p.getDef() << endl;
        cout << "Harry Potter strength = " << p.getStr() << endl;
    
        p.attack();
        cout << "Harry Potter attack = " << p.getAtt() << endl;
        v.defend(p.getAtt());
        cout << "Vampire defense = " << v.getDef() << endl;
        cout << "Vampire strength = " << v.getStr() << endl;
    
        round++;
      }
    
      if(p.getStr() <= 0 && v.getStr() > 0) {
        cout << "\nVampire wins!" << endl;
      }
      else if(p.getStr() > 0 && v.getStr() <= 0) {
        cout << "\nHarry Potter wins!" << endl;
      }
      else if(p.getStr() <= 0 && v.getStr() <= 0) {
        cout << "\nDraw!" << endl;
      }
    } else if(selection == 12) { 
      cout << "\nVampire v. Blue Men:" << endl;
    
      Vampire v;
      BlueMen x;
    
      cout << "Ready.... FIGHT!" << endl;
    
      int round = 1;
    
      while(x.getStr() > 0 && v.getStr() > 0) {
        cout << "\nRound " << round << ":" << endl;
    
        v.attack();
        cout << "Vampire attack = " << v.getAtt() << endl;
        x.defend(v.getAtt());
        cout << "Blue Men defense = " << x.getDef() << endl;
        cout << "Blue Men strength = " << x.getStr() << endl;
    
        x.attack();
        cout << "Blue Men attack = " << x.getAtt() << endl;
        v.defend(x.getAtt());
        cout << "Vampire defense = " << v.getDef() << endl;
        cout << "Vampire strength = " << v.getStr() << endl;
    
        round++;
      }
    
      if(x.getStr() <= 0 && v.getStr() > 0) {
        cout << "\nVampire wins!" << endl;
      }
      else if(x.getStr() > 0 && v.getStr() <= 0) {
        cout << "\nThe Blue Men win!" << endl;
      }
      else if(x.getStr() <= 0 && v.getStr() <= 0) {
        cout << "\nDraw!" << endl;
      }
    } else if(selection == 13) {
      cout << "\nHarry Potter 1 v. Harry Potter 2:" << endl;
    
      Potter p1;
      Potter p2;
    
      cout << "Ready.... FIGHT!" << endl;
    
      int round = 1;
    
      while(p1.getStr() > 0 && p2.getStr() > 0) {
        cout << "\nRound " << round << ":" << endl;
    
        p1.attack();
        cout << "Harry Potter 1 attack = " << p1.getAtt() << endl;
        p2.defend(p1.getAtt());
        cout << "Harry Potter 2 defense = " << p2.getDef() << endl;
        cout << "Harry Potter 2 strength = " << p2.getStr() << endl;
    
        p2.attack();
        cout << "Harry Potter 2 attack = " << p2.getAtt() << endl;
        p1.defend(p2.getAtt());
        cout << "Harry Potter 1 defense = " << p1.getDef() << endl;
        cout << "Harry Potter 1 strength = " << p1.getStr() << endl;
    
        round++;
      }
    
      if(p1.getStr() <= 0 && p2.getStr() > 0) {
        cout << "\nHarry Potter 2 wins!" << endl;
      }
      else if(p1.getStr() > 0 && p2.getStr() <= 0) {
        cout << "\nHarry Potter 1 wins!" << endl;
      }
      else if(p1.getStr() <= 0 && p2.getStr() <= 0) {
        cout << "\nDraw!" << endl;
      }
    } else if(selection == 14) { 
      cout << "\nHarry Potter v. Blue Men:" << endl;
    
      Potter p;
      BlueMen x;
    
      cout << "Ready.... FIGHT!" << endl;
    
      int round = 1;
    
      while(x.getStr() > 0 && p.getStr() > 0) {
        cout << "\nRound " << round << ":" << endl;
    
        p.attack();
        cout << "Harry Potter attack = " << p.getAtt() << endl;
        x.defend(p.getAtt());
        cout << "Blue Men defense = " << x.getDef() << endl;
        cout << "Blue Men strength = " << x.getStr() << endl;
    
        x.attack();
        cout << "Blue Men attack = " << x.getAtt() << endl;
        p.defend(x.getAtt());
        cout << "Harry Potter defense = " << p.getDef() << endl;
        cout << "Harry Potter strength = " << p.getStr() << endl;
    
        round++;
      }
    
      if(x.getStr() <= 0 && p.getStr() > 0) {
        cout << "\nHarry Potter wins!" << endl;
      }
      else if(x.getStr() > 0 && p.getStr() <= 0) {
        cout << "\nThe Blue Men win!" << endl;
      }
      else if(x.getStr() <= 0 && p.getStr() <= 0) {
        cout << "\nDraw!" << endl;
      }
    } else if(selection == 15) { 
      cout << "\nBlue Men 1 v. Blue Men 2:" << endl;
    
      BlueMen x1;
      BlueMen x2;
    
      cout << "Ready.... FIGHT!" << endl;
    
      int round = 1;
    
      while(x1.getStr() > 0 && x2.getStr() > 0) {
        cout << "\nRound " << round << ":" << endl;
    
        x1.attack();
        cout << "Blue Men 1 attack = " << x1.getAtt() << endl;
        x2.defend(x1.getAtt());
        cout << "Blue Men 2 defense = " << x2.getDef() << endl;
        cout << "Blue Men 2 strength = " << x2.getStr() << endl;
    
        x2.attack();
        cout << "Blue Men 2 attack = " << x2.getAtt() << endl;
        x1.defend(x2.getAtt());
        cout << "Blue Men 1 defense = " << x1.getDef() << endl;
        cout << "Blue Men 1 strength = " << x1.getStr() << endl;
    
        round++;
      }
    
      if(x1.getStr() <= 0 && x2.getStr() > 0) {
        cout << "\nBlue Men 2 wins!" << endl;
      }
      else if(x1.getStr() > 0 && x2.getStr() <= 0) {
        cout << "\nBlue Men 1 wins!" << endl;
      }
      else if(x1.getStr() <= 0 && x2.getStr() <= 0) {
        cout << "\nDraw!" << endl;
      }
    } else {
      cout << "Please enter a number from 1 to 15." << endl;
    }

    /*Prompt user for choice about continuing*/
    cout << "\nWould you like to watch another fight? (y/n)" << endl;
    /*Accept user input*/
    cin >> cont;
  }

  return 0;
}
