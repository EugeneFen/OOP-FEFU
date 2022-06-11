#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

template<class T> class Stack_cont 
{ 
private:
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

template <class T> class Shaman : public Person<T>
{
	public:
		Shaman(string v_name, T v_life, int v_damage) : Person<T>(v_name, v_life, v_damage) {}
		
		T Partial_Kill(T k)
		{
			cout<<"The shaman joins the fight"<<endl;
		    return k/2; //óìåíüøàåò êîëëè÷åñòâî âðàãîâ â 2 ðàçà
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
		    return villain/3 ;
		}
};

template <class T> class Ants : public Person<T>
{
	int count;
	int krit;
	
	public:
		
	Ants(string v_name, T v_life, int v_damage) : Person<T>(v_name, v_life, v_damage) 
	{
		this->krit = v_damage * 2;
	}	
	
	int Info_krit()
	{
		return krit;
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
	
	bool Krit_damage_Ants(Ants<T> a)
	{
		int count = a.info_count();
		T life = a.Info_life();
		T buff =0;
		
		if (count > 0)
		{
			buff = life * count;
			buff = buff - krit_damag;
			count = buff / life;
			a.Create_ants(count);
			return true;
		}
		else return false;
	}
	
	T Krit_damage_King_ants(King_ants<T> a)
	{
		T life = a.Info_life();
		if (life >0)
		{
			T buff = life - krit_damag;
			return buff;
		}
		else return 0;
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

void Play(string name)
{
	int count = 50;
	int buff;
	
	Stack_cont<string> team;
	Shaman<int> shaman("Iron", 100, 20);
	Knight<int> knight("God", 50, 40);
	Warrior<int> warrior("Kavin", 150, 30);
	GameHero<int> hero(name, 200, 30);
	Ants<int> ants("Mur", 30, 20);		
	King_ants<int> king("Queen", 200, 50);
	Boss_ants<int> boss("Boss", 500, 100);
	
	team.Push("Baek Un-ho");
	team.Push("Chah He-in");
	
	if (count > 0)
	{
		ants.Create_ants(count);
		cout<<"Ok. Forward!"<<endl;
		
	while (count > 0)
	{
		count = hero.Ability_Shaman(count, shaman);
		ants.Create_ants(count);					

		count = hero.Ability_Knight(count, knight);
		ants.Create_ants(count);
	}
}
cout<<endl;
	cout<<"Wow! It was cool!"<<endl;
	int life = king.Info_life();
	int life_hero = hero.Info_life();
	
	cout<<endl;
	while (life > 0 && life_hero > 0)
	{
		cout<<"The hero goes on the attack";
		int buff_10 = hero.Krit_damage_King_ants(king);
		king.niw_life(buff_10);
		life = king.Info_life();
		cout<<" "<<life<<"Queen"<<endl;
		
		cout<<"Queen attacks";
		int damage = king.Info_damage();
		life_hero -= damage;
		hero.niw_life(life_hero);	
		cout<<" "<<life_hero<<"Hero"<<endl;	
	}
	if (life_hero >0 )
	{
		cout<<endl;
		hero.Hill(hero);
		hero.Hill(hero);
		cout<<endl;
		while (hero.Info_life() > 0 && boss.Info_life() > 0)
		{
			cout<<"The hero attacks the boss"<<endl;
			int buff_2 = boss.Info_life();
			int buff_3 = hero.Info_damage();
			int buff_4 = buff_2 - buff_3;
			boss.niw_life(buff_4);
			
			if (hero.Info_life() > 49)
			{
				boss.Krit_hero(hero,warrior,knight,shaman);
			}
			else
			{
				cout<<"The boss attacks the hero"<<endl;
				buff_2 = hero.Info_life();
				buff_3 = boss.Info_damage();
				buff_4 = buff_2 - buff_3;
				hero.niw_life(buff_4);
			}
		}
		cout<<endl;
		cout<<"The hero won"<<endl;
	}
	else cout<<"The hero lost"<<endl;
}

int main()
{
	string name;
	
	cout<<"Hello traveler!"<<endl;
	cout<<"What is your name?"<<endl;
	name = "Kevin";
	cout<<name<<endl;
	cout<<"Wow! The name of a true hero"<<endl;
	cout<<"Let me tell you how it all works"<<endl;
	cout<<"There are monsters in the cave, you need to defeat them and not die"<<endl;
	cout<<"You have 3 assistants"<<endl;
	cout<<"If you need their help just call them"<<endl;
	cout<<"Be careful the monsters are very strong"<<endl;
	cout<<endl;
	
	Play(name);
	return 0;
}
