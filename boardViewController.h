/* 
 * File:   boardViewController.h
 * Author: javier.rivera
 *
 * Created on October 15, 2011, 10:03 PM
 */

#ifndef BOARDVIEWCONTROLLER_H
#define	BOARDVIEWCONTROLLER_H

#include <string>
#include <map>
#include <vector>
#include <utility>

#include "board.h"

using namespace std;

class boardViewController
{
public:
    static const string HORIZONTAL_BAR;
    static const string VERTICAL_BAR;
    static const int m_display_height = 13;
    static const int m_display_pit_width = 7;
    static const int m_display_pit_height = 5;
    static const int m_display_pit_border = 2;
    
    boardViewController();
    ~boardViewController();
    
    void displayBoard();
    void queryNumPits();
    void queryPitToSow();
    
    
protected:
private:
    board m_board;
    int m_display_width;
    
    void initBoardView();
    void displayPit();
};

void displayChars(string a_symbol, int a_repeat, bool a_new_line=false);
void displayScoringPitTitle(int a_player);
void displayPlayerPitTitle(int a_player, int a_pit);
void displayBlankPitLine();
void displayPlayerPitInfo(int a_row);
void displayLeadingZero(int a_num, int a_num_digits);


#endif	/* BOARDVIEWCONTROLLER_H */

