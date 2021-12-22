// Programmer: Rueil Manzambi                 Section: 109
// Date: February 26, 2021
// File: homework04.cpp
// Purpose: This program tranlates the user's inputted alphabetic character into morse code, 
//          its ascii value and generate random sets of letters and their morse codes 

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/* Constants declaration and initialization */
const int MENU_LOWER_BOUND = 1;
const int MENU_UPPER_BOUND = 5;
// with respect to ascii values of alphabet letters
const int LOWER_CASE_LOWER_BOUND = 97; 
const int LOWER_CASE_UPPER_BOUND = 122;
const int UPPER_CASE_LOWER_BOUND = 65;
const int UPPER_CASE_UPPER_BOUND = 90;
// pattern of random letters to generate
const int RANDOM_CHAR_PATTERN1 = 4;
const int RANDOM_CHAR_PATTERN2 = 3;
// to obtain random number between 0 and 26 inclusive
const int RANDOM_NUMBER_DIVISER = 26;


/* Function prototypes */
int present_menu();
bool option_handler(int option);
char get_input_from_user();
void output_morse(char character);
void output_ascii(char character);
void secret_message();
void error_message();


int main()
{
  // variable declaration
  int option;
  bool quit;

  srand(time(0)); // seeding the time for rand()

  cout << "\n\t\tWELCOME TO THE TRANSLATOR" << endl;
  cout << "\t\t-------------------------" << endl;

  do // executes until user chooses to quit (option 5)
  {
    option = present_menu();
    quit = option_handler(option);
  } while (!quit);

  cout << "\nThank you for using the translator.....bye!\n" << endl;

  return 0;
}


/* Functions definitions */


// Description: Displays the menu and reads user's menu option
// Pre: None
// Post: returns the user's menu option
int present_menu()
{
  // variable declaration
  int user_option;

  do // executes until user enters a valid menu option (1-5)
  {
    cout << "\n1. Enter a character (alphabetic)" << endl;
    cout << "2. Morse code equivalent" << endl;
    cout << "3. ASCII value" << endl;
    cout << "4. Secret Message" << endl;
    cout << "5. Kwit" << endl;
    cin >> user_option;

    if (user_option < MENU_LOWER_BOUND || user_option > MENU_UPPER_BOUND)
      cout << "Invalid input. Please choose one of options 1 through 5" << endl; // is displayed if user's option is invalid
  } while (user_option < MENU_LOWER_BOUND && user_option > MENU_UPPER_BOUND);

  return user_option;
}


// Description: handles menu options, it calls other functions for options (1-4). For option 5, it sets quit to true
// Pre: For options 2 and 3 to be executed succesfully, option has to be executed first.
// Post: Calls other functions or prints an error message and returns quit
bool option_handler(int option)
{
  // variable declaration
  bool quit = false;
  bool static first = true; // static variables have to keep the last updated values
  bool static option1_chosen;
  char static alpha_character; 

  if (first) // executes only the first time to make sure option1 hasn't been chosen yet
  {
    option1_chosen = false;
    first = false;
  }

  switch (option) // decides user option
  {
    case 1: // calls a function to get user's letter and updates option1_chosen to true
      alpha_character = get_input_from_user();
      option1_chosen = true;
      break;
    case 2: // calls a function to output  morse code or calls error function if option1_chosen is false
      if (option1_chosen)
      {
        cout << "This is the morse code for ";
        output_morse(alpha_character);
      }
      else
        error_message();
      break;
    case 3: // calls a function to output ascii value or calls error function if option1_chosen is false
      if (option1_chosen)
        output_ascii(alpha_character);
      else
        error_message();
      break;
    case 4: // calls secret_message function
      secret_message();
      break;
    case 5: // sets quit to true to terminate the program
      quit = true;
      break;
  }
  return quit;
}



// Description: reads an alphabet character from the user
// Pre: None
// Post: returns the alphabet letter
char get_input_from_user()
{
  // variable declaration
  char alpha_character;  

  do // executes until user enters an alphabet letter, either lower case or upper case
  {
    cout << "Enter a character (aphabetic): ";
    cin >> alpha_character;
    if (!((alpha_character >= UPPER_CASE_LOWER_BOUND && alpha_character <= UPPER_CASE_UPPER_BOUND) || (alpha_character >= LOWER_CASE_LOWER_BOUND && alpha_character <= LOWER_CASE_UPPER_BOUND)))
      cout << "Please, enter an alphabet letter" << endl;
  } while ((alpha_character < UPPER_CASE_LOWER_BOUND || alpha_character > UPPER_CASE_UPPER_BOUND) && (alpha_character < LOWER_CASE_LOWER_BOUND || alpha_character > LOWER_CASE_UPPER_BOUND)); 

  return alpha_character;
}


// Description: Outputs character and its morse value
// Pre: character has to be an alphabet letter, either lower case or upper case
// Post: returns nothing, outputs character and its morse value
void output_morse(char character)
{

  switch (character) // decides on character
  {
    case 'a':
    case 'A':
      cout <<character<<"   .-" << endl;
      break;
    case 'b':
    case 'B':
      cout <<character<< "   -..." << endl;
      break;
    case 'c':
    case 'C':
      cout <<character<< "   -.-." << endl;
      break;
    case 'd':
    case 'D':
      cout <<character<< "   -.." << endl;
      break;
    case 'e':
    case 'E':
      cout <<character<< "   ." << endl;
      break;
    case 'f':
    case 'F':
      cout <<character<<  "   ..-." << endl;
      break;
    case 'g':
    case 'G':
      cout <<character<< "   --." << endl;
      break;
    case 'h':
    case 'H':
      cout <<character<< "   ...." << endl;
      break;
    case 'i':
    case 'I':
      cout <<character<< "   .." << endl;
      break;
    case 'j':
    case 'J':
      cout <<character<< "   .---" << endl;
      break;
    case 'k':
    case 'K':
      cout <<character<< "   -.-" << endl;
      break;
    case 'l':
    case 'L':
      cout <<character<< "   .-.." << endl;
      break;
    case 'm':
    case 'M':
      cout <<character<< "   --" << endl;
      break;
    case 'n':
    case 'N':
      cout <<character<< "   -." << endl;
      break;
    case 'o':
    case 'O':
      cout <<character<< "   ---" << endl;
      break;
    case 'p':
    case 'P':
      cout <<character<< "   .--." << endl;
      break;
    case 'q':
    case 'Q':
      cout <<character<< "   --.-" << endl;
      break;
    case 'r':
    case 'R':
      cout <<character<< "   .-." << endl;
      break;
    case 's':
    case 'S':
      cout <<character<< "   ..." << endl;
      break;
    case 't':
    case 'T':
      cout <<character<< "   -" << endl;
      break;
    case 'u':
    case 'U':
      cout <<character<< "   ..-" << endl;
      break;
    case 'v':
    case 'V':
      cout <<character<< "   ...-" << endl;
      break;
    case 'w':
    case 'W':
      cout <<character<< "   .--" << endl;
      break;
    case 'x':
    case 'X':
      cout <<character<< "   -..-" << endl;
      break;
    case 'y':
    case 'Y':
      cout <<character<< "   -.--" << endl;
      break;
    case 'z':
    case 'Z':
      cout <<character<< "   --.." << endl;
      break;
  }
  return;
}



// Description: Outputs character and its ascii value
// Pre: character has to be an alphabet letter
// Post: returns nothing, outputs character and its ascii value
void output_ascii(char character)
{
  cout << "This is the ascii value for " << character << "   " << int(character) << endl;
  return;
}



// Description: Generates three sets (4-3-4) of random letters and outputs them and their morse codes 
// Pre: None
// Post: returns nothing, outputs three sets (4-3-4) of random letters and their morse codes
void secret_message()
{
  // variable declaration
  int random_number;
  char random_character;

  // loop for first set of 4 letters
  for (int i = 0; i < RANDOM_CHAR_PATTERN1; i++)
  {
    random_number = rand() % RANDOM_NUMBER_DIVISER;
    random_character = 'a' + random_number;
    output_morse(random_character); // calls output_morse function with each of the random letter
  }
  
  cout << endl;

  // loop for second set of 3 letters
  for (int i = 0; i < RANDOM_CHAR_PATTERN2; i++)
  {
    random_number = rand() % RANDOM_NUMBER_DIVISER;
    random_character = 'a' + random_number;
    output_morse(random_character);
  }

  cout << endl;

  // loop for third set of 4 letters
  for (int i = 0; i < RANDOM_CHAR_PATTERN1; i++)
  {
    random_number = rand() % RANDOM_NUMBER_DIVISER;
    random_character = 'a' + random_number;
    output_morse(random_character);
  }
  
  return;
}
  
  


// Description: Outputs an error message, because menu options 2 and 3 are chosen before option 1
// Pre: Options 2 or 3 have to chosen befor option 1 for this function to execute
// Post: returns nothing, outputs an error message
void error_message()
{
  cout << "Sorry, you have to enter an alphabet character first." << endl;
  return;
}

