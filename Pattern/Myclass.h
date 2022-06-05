#include <iostream>
#include <string>
using namespace std;

template<class T> class Myclass {
	
    private:
    
	T life; //æèçíè
	string name; //èìÿ
	int damage; //óðîí  !!!!!!!!!!!!!!!!!!!!!!
	
	public:
    
    Myclass(string v_name, T v_life, int v_damage)
    {
    	this->name = v_name;
    	this->life = v_life;
    	this->damage = v_damage;	
	}

    T Info_life()
    {
    	return life;
	}
	
	T niw_life(T value)
	{
		this->life = value;
	}
	
    int Info_damage()
    {
    	return damage;
	}
	
    string Info_name()
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
//#endif
