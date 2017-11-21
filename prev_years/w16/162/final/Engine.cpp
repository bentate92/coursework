
/**********************************************************************
 ** Program Filename: Engine.cpp
 ** Author: Benjamin Tate
 ** Date: 3/15/16
 ** Description: Implementation of the Engine class, described in
 **   Engine.hpp
 ** Input: None
 ** Output: None
 *********************************************************************/

#include "Engine.hpp"
using namespace std;

/**********************************************************************
 ** Function: Constructor -- Engine()
 ** Description: Creates necessary Car objects, creates Train object,
 **   runs game(train)
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
Engine::Engine(string name) : Car() {
  carName = name;

  entrance = "\nYou wander into the engine room and look around. The engineer hasn't noticed you yet, and even from behind, it's apparent that he's more than a little drunk. There are valves all over, and the whole room is blazing hot. If it weren't for the intense heat, you might not have noticed the slight breeze coming from a gap in the floor. A hidden compartment? You barely have time to wonder what's in the compartment before the engineer finally clues in and tells you to get out.";
}

/**********************************************************************
 ** Function: inspect()
 ** Description: Prints responses to certain strings
 ** Parameters: String of what to inspect
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
string Engine::inspect(string inspection) {
  string inv;

  if(newEntrance.empty()) {
    if(inspection == "fight" && !extraCondition) {
      cout << "\nYou thow your glove on the ground and challenge the engineer to a round of fisticuffs, but as he shakily points his gun at you, you decide that you might be outmatched." << endl;
    }
    else if(inspection == "fight" && extraCondition) {
      cout << "\nYou hit the engineer over the head with your bottle of whiskey and he goes out like a light. Your bottle didn't even break! You put it back in your bag." << endl;
    }
    else if(inspection == "compartment" || inspection == "hidden compartment") {
      cout << "\nYou decide to ignore the engineer and kneel down towards the compartment, when you hear the sound of a gun being cocked right by your head. Maybe later." << endl;
    }
    else if(inspection == "valves" || inspection == "valve") {
      cout << "\nYou can't make heads or tails of all these valves, but they sure do look cool." << endl;
    }
    else if(inspection == "engineer") {
      cout << "\nThe engineer is made uncomfortable by your gaze and growls once more for you to go back to the passenger car." << endl;
    }
    else if(inspection == "gun") {
      cout << "\nIt's a nice looking gun, but you never much cared for those things. Better leave it be." << endl;
    }
    else {
      cout << "\nInspect what now?" << endl;
    }
  }
  else {
    if(inspection == "fight") {
      cout << "\nDon't kick a man while he's down." << endl;
    }
    else if(inspection == "compartment" || inspection == "hidden compartment") {
      cout << "\nWithout the engineer guarding it, you're pretty sure you could pry the hatch into the compartment open." << endl;
    }
    else if(inspection == "valves" || inspection == "valve") {
      cout << "\nYou can't make heads or tails of all these valves, but they sure do look cool." << endl;
    }
    else if(inspection == "engineer") {
      cout << "\nHe's still out cold. Hopefully he wakes up in time to stop this thing... oh well." << endl;
    }
    else if(inspection == "gun") {
      cout << "\nIt's a nice looking gun, but you never much cared for those things. Better leave it be." << endl;
    }
    else {
      cout << "\nInspect what now?" << endl;
    }
  }

  return inv;
}

/**********************************************************************
 ** Function: use()
 ** Description: Prints responses to certain strings
 ** Parameters: String of what to use
 ** Pre-Conditions: None
 ** Post-Conditions: None
 *********************************************************************/
void Engine::use(string item) {
  if(item == "key") {
    cout << "\nThere's nothing to unlock in here." << endl;
  }
  else if(item == "whiskey") {
    if(newEntrance.empty()) {
      cout << "\nYou offer the engineer some of your whiskey, and his demeanor changes entirely. He jovially snatches the bottle from you and prepares to uncork it. The effort seems to expend his final brain cells, however, and after a belch to be proud of, he passes out cold. You take the whiskey back and put it in your bag." << endl;

    newEntrance = "\nYou walk into the engine room and look around. The engineer is still out cold, drooling a puddle on the floor. The room is still sweltering, but a cool breeze issues from the hidden compartment below the floor.";
    }
    else {
      cout << "\nYou can't wait to enjoy the whiskey, but you know you have to. It will go better with your fancy new life anyway." << endl;
    }
  }
}
