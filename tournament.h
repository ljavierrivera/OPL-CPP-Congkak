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
    
    tournament(int a_rounds);
    
protected:
    void queryPlayers();
    void nextRound(); 
private:
    int m_rounds;
};


#endif	/* TOURNAMENT_H */

