#include <iostream>
#include <string>
#include "Person.h"
#include "People.h"
using namespace std;

template<class T> class Stack_cont { //контейнер
private:
    struct Key {
        T value;
        Key *next;
    };
    
    Key *begin = NULL;
    
    void output(Key *a) //вывод на экран содержимого стека
    {
        if (a==NULL) return;
        output(a->next);
        cout << a->value << " ";
    }
  
 public:
 	
 	void Push(T item) //добавление эл в стек
     { 
        Key *c = new Key();
        c->value=item;
        c->next=begin;
        begin=c;
     } 
      
     T Pop() //инфорация о первом эл
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
 
    int Empty() //проверка на пустату
    {
        return (begin==NULL);
    }
     
    void Show() //вывод стека
    {
        output(begin);
    }
 	
};

template <class T> class Shaman : public Person<T>
{
	public:
		Shaman(string v_name, T v_life, int v_damage) : Person<T>(v_name, v_life, v_damage) {}
		
		T Partial_Kill(T k)
		{
			cout<<"The shaman joins the fight"<<endl;
		    return (k/2); //óìåíüøàåò êîëëè÷åñòâî âðàãîâ â 2 ðàçà
		}
};

template <class T> class Knight : public Person<T> 
{
	public:
		Knight(string v_name, T v_life, int v_damage) : Person<T>(v_name, v_life, v_damage) {}
		
		T Complete_destruction(T villain)
		{
			cout<<"Knight kills everyone"<<endl;
		    return villain*0;  //óíè÷òîæàåò âñåõ âðàãîâ
		}
};

template <class T> class Warrior : public Person<T>  
{
	public:
		Warrior(string v_name, T v_life, int v_damage) : Person<T>(v_name, v_life, v_damage) {}
		
		T Provocation(T villain)
		{
			cout<<"Warrior uses provocation"<<endl;
		    return villain/2 ; //óåíüøàåò êîëè÷åñòâî õï ïðîòèâíèêà â 2 ðàçà
		}
};

template <class T> class Ants : public Person<T>
{
	int count;
	int krit;
	
	public:
		
	Ants(string v_name, T v_life, int v_damage) : Person<T>(v_name, v_life, v_damage) 
	{
		this->krit = krit * 2;
	}	
			
	void Create_ants(int vould)
	{
		this->count = vould;
		
	}
	
	int info_count()
	{
		return count;
	}
	
};

template <class T> class King_ants : public Person<T>
{	
	public:
		King_ants(string v_name, T v_life, int v_damage) : Person<T>(v_name, v_life, v_damage) {
		}
};

template<class T> class GameHero :  public Person<T>//, public Knight<T>, public Warrior<T>, public Shaman<T>
{
	int krit_damag;

	public:
		
	GameHero(string v_name, T v_life, int v_damage) : Person<T>(v_name, v_life, v_damage) 
	{
		this->krit_damag = krit_damag * 2;
	}
	
	void Hill(GameHero Good)
	{
		cout<<"Hero uses recovery"<<endl;
		T hill = Good.Info_life();
		hill = (hill * 150)/100;
		Good.niw_life(hill);
	}
	
	T Ability_Shaman(T value, Shaman<T> sham) //êîëè÷åñòâî âðàîâ
	{
		cout<<"The hero commands the shaman"<<endl;	
		return sham.Partial_Kill(value);
	}
	
	T Ability_Knight(T villain, Knight<T> knight) //êîëè÷åñòâî âðàãîâ
	{
		cout<<"The hero commands the knight"<<endl;
		return knight.Complete_destruction(villain);
	}
	
	T Ability_Warrior(T value, Warrior<T> warior)
	{
		cout<<"The hero commands the warrior"<<endl;
		return warior.Provocation(value);
	}
	
};

template <class T> class Boss_ants : public Person<T>
{
	int krit_bos;
	public:
		Boss_ants(string v_name, T v_life, int v_damage) : Person<T>(v_name, v_life, v_damage) {
		}
		
		void Krit_hero(GameHero<T> hero, Warrior<T> war, Knight<T> knig, Shaman<T> sham)
		{
			cout<<"Ant boss deals critical damage"<<endl;
			T value = hero.Info_life();
			value = (value * 50)/100;
			hero.niw_life(value);
			
			value = war.Info_life();
			value = (value * 50)/100;
			war.niw_life(value);
			
			value = sham.Info_life();
			value = (value * 50)/100;
			sham.niw_life(value);
			
			value = knig.Info_life();
			value = (value * 50)/100;
			knig.niw_life(value);
		}
};
