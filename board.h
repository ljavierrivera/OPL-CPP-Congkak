/* 
 * File:   board.h
 * Author: javier.rivera
 *
 * Created on October 15, 2011, 12:40 PM
 */

#ifndef BOARD_H
#define	BOARD_H
        
#include <string>
#include <map>
#include <vector>
#include <utility>

using namespace std;

class board
{
public:
    static const unsigned short MIN_NUM_PITS = 5;
    static const unsigned short DEF_NUM_PITS = 7;
    static const unsigned short MAX_NUM_PITS = 11;
    
    board();
    ~board();
    
    board(int a_num_pits);
    

    
    void initBoard();
    void initBoard(int a_num_pits);
    
    int getNumPits();
    bool setNumPits(int a_num_pits);
    
    map<string, int> getPitGroup();
    //void setPitGroup(map<)
    
    
    
    
    
protected:
private:
    int m_num_pits;
    vector< vector<short int> > m_pit_group1;
    vector< vector<short int> > m_pit_group2;
    //vector< vector <short int> > m_pits;
    
    //void initPits();
    void initPits(int a_num_pits = DEF_NUM_PITS);    
    
};

#endif	/* BOARD_H */

