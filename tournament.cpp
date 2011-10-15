#include "tournament.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <stdio.h>
#include <ctype.h>

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

void tournament::runTournament()
{
    do {
        cout << "Current Round: " << this->getCurrRound() << endl;
        this->nextRound();
        this->queryPlayers();
    } while (this->m_is_active_round);
}

void tournament::nextRound()
{
    this->m_curr_round++;
}

void tournament::queryPlayers()
{
    char user_input;
    cout << "Play another round? (y/n)";
    cin >> user_input;
    
    if (tolower(user_input) == 'y') {
        this->m_is_active_round = true;
    } else {
        this->m_is_active_round = false;
    }
    
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

void tournament::setActiveRound(bool a_is_active_round = true)
{
    this->m_is_active_round = a_is_active_round;
}