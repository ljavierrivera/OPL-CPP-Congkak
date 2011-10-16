#include <string>
#include <iostream>

#include "board.h"
#include "boardViewController.h"


using namespace std;

boardViewController::boardViewController()
{
    initBoardView();
}

boardViewController::~boardViewController()
{
    //destructor
}

void boardViewController::initBoardView()
{
    //init
}

void boardViewController::queryNumPits()
{
    unsigned short i_num_pits = 0;
    bool invalid_input = true;
    
    do {
        cout << "Setting up pits; (MIN: " << board::MIN_NUM_PITS
                << ", MAX: " << board::MAX_NUM_PITS << ")" << endl;
        cout << "Enter the Number of pits for this game [" 
                << board::DEF_NUM_PITS << "]: ";
        cin >> i_num_pits;
        cout << endl;
        
        if (i_num_pits >  board::MIN_NUM_PITS && i_num_pits <= board::MAX_NUM_PITS) {
            invalid_input = false;
            system("CLS");
            cout << "OK: Board will have " << i_num_pits << " pits per player!" << endl;
        } else {
            cout << "ERROR: Invalid Input (Outside of Range): Must be between " << board::MIN_NUM_PITS
                    << " and " << board::MAX_NUM_PITS << endl;
        }
    } while (invalid_input);
}