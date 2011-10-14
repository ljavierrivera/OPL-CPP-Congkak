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
