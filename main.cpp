/* 
 * File:   main.cpp
 * Author: javier.rivera
 *
 * Created on September 11, 2011, 12:48 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>

#include "basePlayer.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv)
{
//    vector<int> justavector(5);
//    justavector.push_back(42);
//    cout << "Vector size is " << justavector.size() << endl;

    basePlayer bp;
    
    bp.setName("Jackson");
    cout << "Player name Changed to: " << bp.getName() << endl;
    
    bp.setNumWins(7);
    cout << "Player Wins changed to: " << bp.getNumWins() << endl;
            
    return 0;
}

