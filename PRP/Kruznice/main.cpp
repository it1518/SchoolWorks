/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: student
 *
 * Created on 29. září 2017, 11:53
 */

#include <cstdlib>
#include <iostream>
#include "Kruznice.hpp"

using std::cout;
using std::cin;
using std::endl;



int main(int argc, char** argv) {
    
    float buffer;
    
    Kruznice k1;
    Kruznice k2(1.5);
    Kruznice* k3 = new Kruznice(6.11);
    
    cout << "Objekt k1: " << k2.getPolomer() << endl;    
    cout << "Objekt k2: " <<k2.getPolomer() << endl;  
    cout << "Objekt k3: " <<(*k3).getPolomer() << endl;  
    cout << "Zadej polomer pro k1: ";
    cin >> buffer;
    
    if(k1.setPolomer(buffer)){
        cout << "Byla ulozena hodnota" << k1.getPolomer() << "do polomeru kruznice k1" << endl;
    }else{
        cout << "Spatne" << endl;
    }
    
    cout << "Obvod k1: " << k1.obvod() << endl;
    cout << "Obvod k2: " << k2.obvod() << endl;
    cout << "Obsah k1: " << k1.obsah() << endl;
    cout << "Obsah k2: " << k2.obsah() << endl;
    
    
    return 0;
}

