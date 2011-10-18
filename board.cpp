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
    m_pit_group1.assign(m_num_pits+1, vector<short int>(2,0));
    m_pit_group2.assign(m_num_pits+1, vector<short int>(2,0));
}

short int board::getPitCell(int a_x, int a_y, int a_pit_group)
{
    vector< vector<short int> > *temp_pit_group;
    int temp_size = 0;    
    if (a_pit_group == 1) {
        temp_pit_group = &m_pit_group1;
    } else {
        temp_pit_group = &m_pit_group2;
    }
    temp_size = temp_pit_group->size();
    
    //error checking. forcing invalid values to default to the first cell
    if (a_x < 1 || a_x > temp_pit_group->size()) {
        a_x = 1;
    }
    
    if (a_y < 0 || a_y > temp_pit_group->front().size()) {
        a_y = 0;
    }

    //will return default of [1][0]
    return temp_pit_group->at(a_x).at(a_y);//[a_y];
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
                    m_pit_group1[ii].assign(2,0);
                    m_pit_group2[ii].assign(2,0);
                }
            }
        }
        return true;
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
