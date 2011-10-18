#include <vector>
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
    //adds an additional pit. Pit[0] will be the scoring pit
    m_pit_group1.assign(m_num_pits+1, 0);
    m_pit_group2.assign(m_num_pits+1, 0);
}

int board::getPitCell(int a_x, int a_pit_group)
{
    vector<int> *temp_pit_group;
    
    if (checkPitCell(a_x)) {
        if (a_pit_group == 1) {
            temp_pit_group = &m_pit_group1;
        } else {
            temp_pit_group = &m_pit_group2;
        }
        
        return temp_pit_group->at(a_x);
    }
}

int board::getNumPits()
{
    return m_num_pits;
}

bool board::setNumPits(int a_num_pits)
{
    if (checkNumPitsRange(a_num_pits)) {
        m_num_pits = a_num_pits;
        return resizeBoard();
    }
    
    return false;
}

bool board::resizeBoard()
{
    int prev_size = m_pit_group1.size();
    
    if (checkNumPitsRange(m_num_pits)) {
        if (m_num_pits != m_pit_group1.size()) {
            m_pit_group1.resize(m_num_pits+1);
            m_pit_group2.resize(m_num_pits+1);
            
            if (m_num_pits > prev_size) {
                for (int ii = prev_size; ii <= m_num_pits; ii++) {
                    m_pit_group1[ii] = 0;
                    m_pit_group2[ii] = 0;
                }
            }

            return true;
        }
    }
    
    return false;
}

bool board::checkNumPitsRange(int a_num_pits)
{
    if (a_num_pits < MIN_NUM_PITS || a_num_pits > MAX_NUM_PITS) {
        return false;
    }
    
    return true;
}

bool board::checkPitCell(int a_x)
{
    if (a_x < 0 || a_x > m_num_pits) {
        return false;
    }
    
    return true;
}
