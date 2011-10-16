#include "board.h"

using namespace std;

const unsigned short board::MIN_NUM_PITS;
const unsigned short board::DEF_NUM_PITS;
const unsigned short board::MAX_NUM_PITS;

board::board()
{
    initPits();   
}

board::~board()
{
    //default destructor
}

board::board(int a_num_pits)
{
    m_num_pits = a_num_pits;
}

void board::initPits(int a_num_pits)
{
    m_num_pits = a_num_pits;
    m_pit_group1.assign(m_num_pits, 0);
    m_pit_group2.assign(m_num_pits, 0);
    //m_pits.push_back(m_pit_group1);
    //m_pits.push_back(m_pit_group2);
}
