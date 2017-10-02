/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Kruznice.hpp
 * Author: Dalibor Kyjovský
 *
 * Created on 29. září 2017, 11:54
 */

#ifndef KRUZNICE_HPP
#define KRUZNICE_HPP

class Kruznice {
public:
    Kruznice();
    Kruznice(float);
    float getPolomer() const;
    bool setPolomer(float);
    float obsah() const;
    float obvod() const;
    virtual ~Kruznice();
private:
    float polomer;

};

#endif /* KRUZNICE_HPP */

