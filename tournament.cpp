#include "tournament.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

tournament::tournament()
{
    this->setCurrRound(1);
    this->setActiveRound(false);
}

tournament::~tournament()
{
    //Trash Collection
    //destroy the tournament
}

int tournament::getRoundsPlayed()
{
    this->nextRound();

    if (this->m_is_active_round == true) {
        return this->getCurrRound() - 1;
    } else {
        return this->getCurrRound();
    }
}

void tournament::nextRound()
{
    this->m_curr_round++;
}

void tournament::setCurrRound(int a_curr_round)
{
    //force all negative entries to be set to 1
    if (a_curr_round <= 1) {
        this->m_curr_round = 1;
    } else {
        this->m_curr_round = a_curr_round;
    }
}

int tournament::getCurrRound()
{
    return this->m_curr_round;
}

void tournament::setActiveRound(bool a_is_active_round)
{
    this->m_is_active_round = a_is_active_round;
}
