#include <iostream>
#include <string>
using namespace std;

template<class T> class Person {
	
    private:
    
	T life; //жизни
	string name; //имя
	int damage; //урон
	
	public:
    
    Myclass(string v_name, T v_life, int v_damage) //конструктор
    {
    	this->name = v_name;
    	this->life = v_life;
    	this->damage = v_damage;	
	}

    T Info_life() //вывод информации о жизни
    {
    	return life;
	}
	
	T niw_life(T value) //перезапись жизни
	{
		this->life = value;
	}
	
    int Info_damage() //информация о уроне
    {
    	return damage;
	}
	
    string Info_name() //информация о имени
    {
    	return name;
    }
    
    void Del() //удаление информации
    {
    	this->name = 0;
    	this->life = 0;
    	this->damage = 0;
    }	
};
