#include <iostream>
#include <string>
using namespace std;

template<class T> class Person {
	
    private:
    
	T life; //æèçíè
	string name; //èìÿ
	int damage; //óðîí  !!!!!!!!!!!!!!!!!!!!!!
	
	public:
    
    Person(string v_name, T v_life, int v_damage)
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

template<class T>
class Stack
{
 
    struct Key {
        T value;
        Key *next;
    };
    
    Key *begin = NULL;
    
    void output(Key *a)
    {
        if (a==NULL) return;
        output(a->next);
        cout << a->value << " ";
    }
  
 public:
 	
 	void Push(T item)
     { 
        Key *c = new Key();
        c->value=item;
        c->next=begin;
        begin=c;
     } 
      
     T Pop()
     {
        Key *a; 
        if (begin != NULL) 
        {
            a=begin;
            begin=a->next;
            return a->value;
        }
        else
        {
            throw "Stack is empty!";
        }
     }
 
    int Empty()
    {
        return (begin==NULL);
    }
     
    void Show()
    {
        output(begin);
    }
 	
};
