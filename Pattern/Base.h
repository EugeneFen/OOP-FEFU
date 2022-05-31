//#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Myclass
{
	int life; //æèçíè
	T name; //èìÿ
	int damage; //óðîí
    
    public:    	
    MyClass(T v_name, int v_life, int v_damage)
    {
    	this->name = v_name;
    	this->life = v_life;
    	this->damage = v_damage;	
	}

    int Info_life()
    {
    	return life;
	}
	
    int Info_damage()
    {
    	return damage;
	}
	
    T Info_name()
    {
    	return name;
    }
    
    void Del()
    {
    	this->name = 0;
    	this->life = 0;
    	this->damage = 0;
    }	
};
