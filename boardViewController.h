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
    static const <string> HORIZONTAL_BAR = "=";
    static const <string> VERTICAL_BAR = "||";
    static const int m_display_height = 17;
    
    boardViewController();
    ~boardViewController();
    
    void displayBoard();
    
    
protected:
private:
    board m_board;
    map<string, int> m_pits_group1;
    map<string, int> m_pits_group2;
    int m_display_width;
    
    void initBoardView();
    void queryNumPits();
};



#endif	/* BOARDVIEWCONTROLLER_H */

