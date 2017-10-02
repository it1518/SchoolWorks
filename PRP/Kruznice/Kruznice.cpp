/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Kruznice.cpp
 * Author: student
 * 
 * Created on 29. září 2017, 11:54
 */

#include "Kruznice.hpp"
#include <cmath>

Kruznice::Kruznice() {
    polomer = 1;
}

Kruznice::Kruznice(float polomer) {
    if(polomer <= 0){
        this->polomer = 1;
    }else{
        this->polomer = polomer;
    }
}

float Kruznice::obvod() const{
    return 2 * M_PI * this->polomer;  
}

float Kruznice::obsah() const{
    return M_PI * this->polomer * this->polomer;
}

bool Kruznice::setPolomer(float polomer){
     if(polomer <= 0){
         return false;
    }else{
         return true;
    }
}


float Kruznice::getPolomer() const{
    return this->polomer;
}

Kruznice::~Kruznice() {
}

