
/**********************************************************************
 ** Program Filename: assignment4Main.cpp
 ** Author: Benjamin Tate
 ** Date: 2/28/16
 ** Description: Contains main function to manage tournament and
 **   makeCreature function to create necessary Creature objects
 ** Input: Responses to prompts
 ** Output: Prompts regarding team creation
 *********************************************************************/

#include "Tournament.hpp"

using namespace std;

/**********************************************************************
 ** Function: makeCreature()
 ** Description: Creates and returns a pointer to the specified type of
 **   Creature, with the specified name
 ** Parameters: Int to identify Creature type, string to hold name
 ** Pre-Conditions: id and name must exist and hold values
 ** Post-Conditions: None
 *********************************************************************/
Creature* makeCreature(int id, string name) {
    switch (id) {
      case 1: return new Barbarian(name);
      case 2: return new Medusa(name);
      case 3: return new Vampire(name);
      case 4: return new Potter(name);
      case 5: return new BlueMen(name);
    }
}

/**********************************************************************
 ** Function: main()
 ** Description: Creates teams, runs tournament
 ** Parameters: None
 ** Pre-Conditions: File must have access to necessary objects
 ** Post-Conditions: None
 *********************************************************************/
int main() {
  /*Set rand() by time*/
  srand(time(NULL));

  /*Initialize team1 and team2 Queues*/
  Queue team1;
  Queue team2;
  /*Initialize int to hold desired team size*/
  int teamSize;
  /*Initialize int to hold desired creature id*/
  int creatureId;
  /*Initialize string to hold deired creature names*/
  string creatureName;

  /*Prompt user for desired team size and store in teamSize*/
  cout << "How many fighters would you like on each team?" << endl;
  cin >> teamSize;

  /*Prompt first player to build team*/
  cout << "\nPlayer 1, build your team:" << endl;
  /*Continue while i < teamSize*/
  for(int i = 0; i < teamSize; i++) {
    /*Prompt user for given Creature's type and store in creatureId*/
    cout << "\nWhat type would you like creature #" << i + 1 << " to be?" 
         << endl;
    cout << "1 - Barbarian" << endl;
    cout << "2 - Medusa" << endl;
    cout << "3 - Vampire" << endl;
    cout << "4 - Harry Potter" << endl;
    cout << "5 - Blue Men" << endl;
    cin >> creatureId;

    /*Prompt user for Creature's name and store in creatureName*/
    cout << "\nAnd what would you like creature #" << i + 1 
         << "'s name to be?" << endl;
    cin >> creatureName;

    /*Create specified creature and add to team1*/
    Creature* c = makeCreature(creatureId, creatureName);
    team1.add(c);
  }


  /*Prompt second player to build team*/   
  cout << "\nPlayer 2, build your team:" << endl;
  /*Continue while i < teamSize*/ 
  for(int i = 0; i < teamSize; i++) {
    /*Prompt user for given Creature's type and store in creatureId*/
    cout << "\nWhat type would you like creature #" << i + 1 << " to be?" 
         << endl;
    cout << "1 - Barbarian" << endl;
    cout << "2 - Medusa" << endl;
    cout << "3 - Vampire" << endl;
    cout << "4 - Harry Potter" << endl;
    cout << "5 - Blue Men" << endl;
    cin >> creatureId;
    /*Prompt user for Creature's name and store in creatureName*/

    cout << "\nAnd what would you like creature #" << i + 1 
         << "'s name to be?" << endl;
    cin >> creatureName;

    /*Create specified creature and add to team2*/
    Creature* c = makeCreature(creatureId, creatureName);
    team2.add(c);
  }

  /*Create Tournament object with team1 and team2*/
  Tournament tourney(team1, team2);

  /*
   * Continue to call Tournament's battle() until at least one team
   * has no more fighters
   */
  while(tourney.getT1().getSize() > 0 && 
        tourney.getT2().getSize() > 0) {
    tourney.battle();
  }

  /*Call Tournament's results()*/
  tourney.results();

  return 0;
}
