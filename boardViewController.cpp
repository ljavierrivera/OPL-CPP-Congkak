#include <iostream>
#include <string>
#include <sstream>

#include "board.h"
#include "boardViewController.h"

using namespace std;

const string boardViewController::HORIZONTAL_BAR = "=";
const string boardViewController::VERTICAL_BAR = "|";

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
    queryNumPits();
}

void boardViewController::queryNumPits()
{
    unsigned short i_num_pits = 0;
    bool invalid_input = true;
    string input = "";
    
    do {
        cout << "Setting up pits; (MIN: " << board::MIN_NUM_PITS
                << ", MAX: " << board::MAX_NUM_PITS << ")" << endl;
        cout << "Enter the Number of pits for this game [" 
                << board::DEF_NUM_PITS << "]: ";
        do {
            getline(cin, input);
            stringstream input_stream(input);
            if (input_stream >> i_num_pits) {
                break;
            } else {
                cout << "Invalid entry, please enter a number: ";
            }
        } while (true);
        //cin >> i_num_pits;
        cout << endl;
        
        //if (i_num_pits >  board::MIN_NUM_PITS && i_num_pits <= board::MAX_NUM_PITS) {
        if (m_board.setNumPits(i_num_pits)) {
            invalid_input = false;
            //system("CLS");
            cout << "OK: Board will have " << i_num_pits << " pits per player!" << endl;
        } else {
            cout << "ERROR: Invalid Input (Outside of Range): Must be between " << board::MIN_NUM_PITS
                    << " and " << board::MAX_NUM_PITS << endl;
            invalid_input = true;
        }
    } while (invalid_input);   
}

void boardViewController::displayBoard()
{
    int p, pp, po, val;
    int num_pits = m_board.getNumPits();
    int board_width = ((2 + num_pits) * (m_display_pit_width + m_display_pit_border));
    int full_pit_width = m_display_width + m_display_pit_border;
  
    for (int rr = 1; rr <= m_display_height; rr++) {
        if (rr == 2 || rr == 4 || rr == 6 || rr == 9 || rr == (m_display_height-2)) {
            p = 2;
        } else {
            p = 1;
        }
        
       if (rr == 1 || rr == m_display_height) {
           displayChars(HORIZONTAL_BAR, board_width);
       } else if (rr == 2 || rr == (m_display_pit_height+3)) {
           displayBlankPitLine();
           for (pp = 1; pp <= num_pits; pp++) { 
               cout << VERTICAL_BAR << " P" << p << "_";
               if (p == 1) { 
                   po = num_pits - (pp-1);
               } else {
                   po = pp;
               }
               displayLeadingZero(po,2);
               cout << " " << VERTICAL_BAR;
           }
           displayBlankPitLine();
       } else if ((rr == 3 || rr == (m_display_height-2))
               || (rr == 5 || rr == (m_display_height-4)))
       
       {
           if (rr == 3) {
               displayScoringPitTitle(p);
           } else if (rr == 5) {
               cout << VERTICAL_BAR << "  ";
               displayLeadingZero(m_board.getPitCell(0,p),3);
               cout << "  " << VERTICAL_BAR;
           } else {
               displayBlankPitLine();
           }
           
           for (pp = 1; pp <= num_pits; pp++) {
               displayBlankPitLine();
           }
           
           if (rr == (m_display_height-2)) {
               displayScoringPitTitle(p);
           } else if (rr == (m_display_height-4)) {
               cout << VERTICAL_BAR << "  ";
               displayLeadingZero(m_board.getPitCell(0,p),3);
               cout << "  " << VERTICAL_BAR;
           } else {
               displayBlankPitLine();
           }
       } else if (rr == 4 || rr == (m_display_pit_height+5)) {
           displayBlankPitLine();
           for (pp = 1; pp <= num_pits; pp++) {
               cout << VERTICAL_BAR << "  ";
               if (p == 1) { 
                   po = num_pits - (pp-1);
               } else {
                   po = pp;
               }
               val = m_board.getPitCell(po, 1);
               displayLeadingZero(val, 3);
               cout << "  " << VERTICAL_BAR;
           }
           displayBlankPitLine();
       } else if (rr == 5 || rr == (m_display_pit_height+4)) {
           cout << VERTICAL_BAR << "  ";
           displayLeadingZero(val,3);
           cout << "  " << VERTICAL_BAR;
       } else if (rr == 6 || rr == (m_display_pit_height+7)) {
           displayBlankPitLine();
           for (pp = 1; pp <= num_pits; pp++) {
               cout << VERTICAL_BAR << " [";
               if (p == 1) { 
                   po = num_pits - (pp-1);
               } else {
                   po = pp;
               }               
               
               if (po < 10) {
                       cout << " ";
               }
               cout << po << "]  " ;
               cout << VERTICAL_BAR;
           }
           displayBlankPitLine();
       }else {
           displayBlankPitLine();
           for (pp = 1; pp <= num_pits; pp++) {
               if (rr == (m_display_pit_height+2)) { 
                   cout << VERTICAL_BAR;
                   displayChars(HORIZONTAL_BAR, m_display_pit_width);
                   cout << VERTICAL_BAR;
               } else {
                   displayBlankPitLine();
               }
           }
           displayBlankPitLine();
       }           
//           for (int cc = 1; cc <= board_width;) {
//               if (cc == 1 || cc == board_width 
//                       || (cc % m_display_ppit == 0) || (cc % m_display_ppit == 1)) {
//                   //vertical bar for first, last and every pit
//                   cout << VERTICAL_BAR;
//                   cc++;
//               } else {
//                   if ((rr < m_display_pit_height && cc < m_display_pit_width)
//                           || (rr > m_display_pit_height && cc < (board_width - m_display_pit_width))) {
//                       p = 1
//                   } else {
//                       p = 2;
//                   }
//                   if ((rr == 3 && cc < m_display_pit_width) 
//                           || (rr == (m_display_height - 1) && cc > board_width - full_pit_width)) {
//                       cout << " SP_P" << p << " ";
//                   } else {
//                       if (rr == 2 || rr == (m_display_height + m_display_border)) {
//                           int
//                           if (cc > full_pit_width || cc < (board_width - full_pit_width)) {
//                               cout << " P" << p << " PP"
//                           }
//                       }
//                       
//                       displayChars(" ", m_display_pit_width);
//
//                   }
//                   cc += m_display_width;
//               }
//           }
////       }
////           cout << "|";
////           if (rr == 3 || rr == (m_display_height-2)) {
////               
////           } if (rr ==) else {
////               //
////               displayChars(" ", m_display_spit_width);
////           }
////           cout << "|";
////       }
////       
////       displayChars(" ", )
////   
////   for(int ii = 1; ii <= num_pits; ii++) {
////       cout << "[" << ii << "]" << m_board.getPitCell(ii) << endl;
       cout << endl;
   }
}

void displayChars(string a_symbol, int a_repeat, bool a_new_line)
{
    for (int ii = 0; ii < a_repeat; ii++) {
        cout << a_symbol;
    }
    
    if (a_new_line) {
        cout << endl;
    }
}

void displayScoringPitTitle(int a_player)
{
    cout << boardViewController::VERTICAL_BAR 
            << " SP_P" << a_player << " "
            << boardViewController::VERTICAL_BAR;
}

void displayPlayerPitTitle(int a_player, int a_pit)
{
    cout << boardViewController::VERTICAL_BAR 
            << " P" << a_player << "_";
    if (a_pit < 10) {
        cout << "0";
    }
    cout << a_pit << " " << boardViewController::VERTICAL_BAR;
}

void displayBlankPitLine()
{
    cout << boardViewController::VERTICAL_BAR;
    displayChars(" ", boardViewController::m_display_pit_width);
    cout << boardViewController::VERTICAL_BAR;
}

void displayLeadingZero(int a_num, int a_num_digits)
{
    if (a_num_digits == 3) {
        if (a_num < 100) {
            if (a_num < 10) {
                cout << "00";
            } else {
                cout << "0";
            }
        }
    } else {
        if (a_num < 10) {
            cout << "0";
        }
    } 
    
    cout << a_num;
}
