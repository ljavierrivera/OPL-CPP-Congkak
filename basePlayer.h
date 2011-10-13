/* 
 * File:   basePlayer.h
 * Author: javier.rivera
 *
 * Created on September 13, 2011, 10:56 PM
 */

#ifndef BASEPLAYER_H
#define	BASEPLAYER_H

#include <string>
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

class basePlayer
{
public:
    basePlayer();
     ~basePlayer();
     
    basePlayer(string a_player_name);
    basePlayer(string a_player_name, int a_num_wins);
   
    void setName(string a_player_name);
    string getName();
    
    void setNumWins(int a_num_wins);
    void addWin();
    void resetNumWins();
    int getNumWins();
    
    
protected:
private:
    string m_player_name;
    int m_num_wins;

};

#endif	/* BASEPLAYER_H */

