#include <iostream>
#include <string>
#include "Myclass.h"
#include "People.h"
using namespace std;


template <class T> class Shaman : public Myclass<T>
{
	public:
		Shaman(string v_name, T v_life, int v_damage) : Myclass<T>(v_name, v_life, v_damage) {}
		
		T Partial_Kill(T k)
		{
			cout<<"The shaman joins the fight"<<endl;
		    return (k/2); //óìåíüøàåò êîëëè÷åñòâî âðàãîâ â 2 ðàçà
		}
};

template <class T> class Knight : public Myclass<T> 
{
	public:
		Knight(string v_name, T v_life, int v_damage) : Myclass<T>(v_name, v_life, v_damage) {}
		
		T Complete_destruction(T villain)
		{
			cout<<"Knight kills everyone"<<endl;
		    return villain*0;  //óíè÷òîæàåò âñåõ âðàãîâ
		}
};

template <class T> class Warrior : public Myclass<T>  
{
	public:
		Warrior(string v_name, T v_life, int v_damage) : Myclass<T>(v_name, v_life, v_damage) {}
		
		T Provocation(T villain)
		{
			cout<<"Warrior uses provocation"<<endl;
		    return villain/2 ; //óåíüøàåò êîëè÷åñòâî õï ïðîòèâíèêà â 2 ðàçà
		}
};

template <class T> class Ants : public Myclass<T>
{
	int count;
	int krit;
	
	public:
		
	Ants(string v_name, T v_life, int v_damage) : Myclass<T>(v_name, v_life, v_damage) 
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


template <class T> class BOS_ants : public Myclass<T>
{
	int krit_bos;
	public:
		BOS_ants(string v_name, T v_life, int v_damage) : Myclass<T>(v_name, v_life, v_damage) {
		}
		
		void Krit_hero(GameHero hero, Warrior war, Knight knig, Shaman sham)
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
}

template <class T> class King_ants : public Myclass<T>
{	
	public:
		King_ants(string v_name, T v_life, int v_damage) : Myclass<T>(v_name, v_life, v_damage) {
		}
}

template<class T> class GameHero :  public Myclass<T>//, public Knight<T>, public Warrior<T>, public Shaman<T>
{
	int krit_damag;

	public:
		
	GameHero(string v_name, T v_life, int v_damage) : Myclass<T>(v_name, v_life, v_damage) 
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

int main()
{
	
	string name2 = "Hero!";
	int xp = 100;
	int damag = 50;
	
	GameHero<int> a(name2,xp,damag);
	cout<<a.Info_name()<<endl;
	cout<<a.Info_damage()<<endl;
	cout<<a.Info_life()<<endl;
	
	Shaman<int> b(name2,xp,damag);
	cout<<a.Ability_Shaman(10, b)<<endl;
	cout<<b.Info_name()<<endl;
	cout<<b.Info_damage()<<endl;
	cout<<b.Info_life()<<endl;
	
	Knight<int> c(name2,xp,damag);
	Warrior<int> d(name2,xp,damag);
	cout<<a.Ability_Knight(10, c)<<endl;
	cout<<a.Ability_Warrior(10, d)<<endl;
	
	return 0;
}
