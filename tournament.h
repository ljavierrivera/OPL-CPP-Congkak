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
    
    int getRoundsPlayed();
    void runTournament();
   
protected:
    void queryPlayers();
    void nextRound(); 
private:
    int m_curr_round;
    bool m_is_active_round;
    
    //void setCurrRound();
    void setCurrRound(int a_curr_round = 1);
    int getCurrRound(); 
    void setActiveRound(bool a_is_active_round);
    
};

#endif	/* TOURNAMENT_H */
