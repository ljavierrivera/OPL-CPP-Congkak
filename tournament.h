/* 
 * File:   tournament.h
 * Author: javier.rivera
 *
 * Created on October 13, 2011, 8:11 PM
 */

#ifndef TOURNAMENT_H
#define	TOURNAMENT_H

using namespace std;

class tournament
{
public:
    tournament();
    ~tournament();
    
    tournament(int a_num_rounds);
    
    void setRounds(int a_num_rounds);
    int getRounds();
   
protected:
    void queryPlayers();
    void nextRound(); 
private:
    int m_num_rounds;
    int m_curr_round;
    
    void setCurrRound(int a_curr_round);
    int getCurrRound();
};


#endif	/* TOURNAMENT_H */

