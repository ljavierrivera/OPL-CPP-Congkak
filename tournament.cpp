#include "tournament.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

tournament::tournament()
{
    this->setRounds(0);
}

~tournament::tournament()
{
    //Trash Collection
    //destroy the tournament
}

//void tournament::setCurrRound()
//{
//    this->m_curr_round = 1;
//}

void tournament::setCurrRound(int a_curr_round)
{
    //force all negative entries to be set to 1
    if (a_curr_rount <= 1) {
        this->setCurrRound();
    } else {
        this->m_curr_round = a_curr_round;
    }
}

int tournament::getRounds()
{
    if (this->m_curr_round == NULL) {
        this->setCurrRound();
    }
    
    return this->m_curr_round;
}

//basePlayer::basePlayer()
//{
//    basePlayer::setName("");
//    basePlayer::setNumWins(0);
//}
//
//void basePlayer::setName(string a_name)
//{
//    basePlayer::m_player_name = a_name;
//}
//
//string basePlayer::getName()
//{
//    return basePlayer::m_player_name;
//}
//
//void basePlayer::setNumWins(int a_num_wins)
//{
//    basePlayer::m_num_wins = a_num_wins;
//}
//
//int basePlayer::getNumWins()
//{
//    return basePlayer::m_num_wins;
//}
//
//basePlayer::~basePlayer()
//{
//    basePlayer::m_player_name.clear();
//    basePlayer::m_num_wins = 0;
//}
//
