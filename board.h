n
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
    board();
    ~board();
    
    board(int a_num_pits);
protected:
private:
    int m_num_pits
    map<string, int> m_player_1;
    map<string, int> m_player_2;
    vector<map> m_pits;
    
};

#endif	/* BOARD_H */

