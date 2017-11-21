
/**********************************************************************
 ** Program Filename: Tournament.cpp
 ** Author: Benjamin Tate
 ** Date: 2/28/16
 ** Description: Implementation of the Tournament class, described in
 **   Tournament.hpp
 ** Input: none
 ** Output: none
 *********************************************************************/

#include "Tournament.hpp"
using namespace std;

/**********************************************************************
 ** Function: Constructor -- Tournament()
 ** Description: Initializes battleCount to 1, sets t1 and t2 to
 **   parameter Queue objects
 **   sets creatureName and id 
 ** Parameters: Two Queue objects, representing each team's lineup
 ** Pre-Conditions: team1 and team2 must exist
 ** Post-Conditions: None
 *********************************************************************/
Tournament::Tournament(Queue team1, Queue team2) {
  battleCount = 1;
  t1 = team1;
  t2 = team2;
}

/**********************************************************************
 ** Function: battle()
 ** Description: Runs current battle, printing updates, calls victory()
 **   for winning creature, and then sends each creature to appropriate
 **   Queue or Stack
 ** Parameters: None
 ** Pre-Conditions: t1 and t2 must not be NULL, appropriate Creature
 **   objects must exist
 ** Post-Conditions: None
 *********************************************************************/
void Tournament::battle() {
  /*Create two Creatures from front members of each team*/
  Creature* c1 = t1.remove();
  Creature* c2 = t2.remove();

  /*Print statement to show which battle is starting*/
  cout << "\nBattle " << battleCount << "....\nFIGHT!" << endl;
 
  /*Initialize round to 1*/ 
  int round = 1;

  /*Repeat battle until one or both characters are defeated*/
  while ((*c1).getStr() > 0 && (*c2).getStr() > 0) {
    /*Print current round*/
    cout << "\nRound " << round << ":" << endl;

    /*1st character attacks*/    
    (*c1).attack();
    /*Print 1st character's attack power*/
    cout << (*c1).getName() << "'s attack = " << (*c1).getAtt() << endl;
    /*2nd character defends against attack*/
    (*c2).defend((*c1).getAtt());
    /*Print 2nd character's defense power*/
    cout << (*c2).getName() << "'s defense = " << (*c2).getDef() << endl;
    /*Print 2nd character's remaining strength*/
    cout << (*c2).getName() << "'s strength = " << (*c2).getStr() << endl;

    /*2nd character attacks*/   
    (*c2).attack();
    /*Print 2nd character's attack power*/
    cout << (*c2).getName() << "'s attack = " << (*c2).getAtt() << endl;
    /*1st character defends against attack*/
    (*c1).defend((*c2).getAtt());
    /*Print 1st character's defense power*/
    cout << (*c1).getName() << "'s defense = " << (*c1).getDef() << endl;
    /*Print 1st character's remaining strength*/
    cout << (*c1).getName() << "'s strength = " << (*c1).getStr() << endl;

    /*Increment round counter*/
    round++;
  }

  /*Determine and print results, send Creatures to appropriate place*/
  if((*c1).getStr() <= 0 && (*c2).getStr() > 0) {
    /*Print winner*/
    cout << "\n" << (*c2).getName() << " of team 2 wins!" << endl;

    /*Call victory() on winning Creature*/
    (*c2).victory();
    /*Add winning Creature to back of its team's Queue*/
    t2.add(c2);
    
    /*Add losing Creature to losers Stack*/
    losers.add(c1);
  }
  else if((*c1).getStr() > 0 && (*c2).getStr() <= 0) {
    /*Print winner*/
    cout << "\n" << (*c1).getName() << " of team 1 wins!" << endl;
    
    /*Call victory() on winning Creature*/
    (*c1).victory();
    /*Add winning Creature to back of its team's Queue*/
    t1.add(c1);

    /*Add losing Creature to losers Stack*/
    losers.add(c2);
  }
  else if((*c1).getStr() <= 0 && (*c2).getStr() <= 0) {
    /*Print draw*/
    cout << "\nDraw! Both fighters eliminated!" << endl;

    /*Add both Creatures to losers Stack*/  
    losers.add(c1);
    losers.add(c2);  
  }

  /*Increment battleCount*/
  battleCount++;
}

/**********************************************************************
 ** Function: results()
 ** Description: Determines and prints winning team, adds remaining 
 **   members of winning team ot losers Stack, pops each Creature off
 **   of losers, printing the first three as the top 3 winners.
 ** Parameters: None
 ** Pre-Conditions: t1 and t2 must not be NULL, losers Stack must exist
 **   and function properly
 ** Post-Conditions: None
 *********************************************************************/
void Tournament::results() {
  /*Initialize temp Creature*/
  Creature* temp;
  /*Determine and print winning teami, add remaining Creatures to losers*/
  if(t1.getSize() > 0 && t2.getSize() == 0) {
    /*Print winning team*/
    cout << "\nPlayer 1's team wins!" << endl; 
    
    /*Add remaining Creatures of winning team to losers Stack*/
    while(t1.getSize() > 0) {
      temp = t1.remove();
      losers.add(temp);
    }
  }
  else if(t1.getSize() == 0 && t2.getSize() > 0) {
    /*Print winning team*/  
    cout << "\nPlayer 2's team wins!" << endl;
    
    /*Add remaining Creatures of winning team to losers Stack*/ 
    while(t2.getSize() > 0) {
      temp = t2.remove();
      losers.add(temp);
    }
  }
  else if(t1.getSize() == 0 && t2.getSize() == 0) {
    /*Print draw*/
    cout << "\nDraw!" << endl;
  }

  /*Pop first three creatures off of Stack and save in 1st, 2nd, and 3rd*/
  Creature* first = losers.remove();
  Creature* second = losers.remove();
  Creature* third = losers.remove();

  /*Remove the rest of losers Stack*/
  while (losers.getSize() > 0) {
    losers.remove();
  }

  /*Print top three*/
  cout << "\nHere are the three fighters who lasted the longest, "
       << "in order:" << endl;
  cout << "In first place, with " << first->getScore() 
       << " wins, is " << first->getName() << "!" << endl;
  cout << "In second place, with " << second->getScore() 
       << " wins, is " << second->getName() << "!" << endl;
  cout << "In third place, with " << third->getScore() 
       << " wins, is " << third->getName() << "!" << endl;
}

/**********************************************************************
 ** Function: getT1()
 ** Description: Returns Queue t1
 ** Parameters: None
 ** Pre-Conditions: Queue must be initialized
 ** Post-Conditions: None
 *********************************************************************/
Queue Tournament::getT1() {
  return t1;
}

/**********************************************************************
 ** Function: getT2()
 ** Description: Returns Queue t2
 ** Parameters: None
 ** Pre-Conditions: Queue must be initialized
 ** Post-Conditions: None
 *********************************************************************/
Queue Tournament::getT2() {
  return t2;
}

