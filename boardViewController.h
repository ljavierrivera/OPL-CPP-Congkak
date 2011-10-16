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
    //static const char 
    
    boardViewController();
    ~boardViewController();
    
    void displayBoard();
    void queryNumPits();
    
protected:
private:
    board m_board;
    map<string, int> m_pits_group1;
    map<string, int> m_pits_group2;
    
    void initBoardView();
};



#endif	/* BOARDVIEWCONTROLLER_H */

