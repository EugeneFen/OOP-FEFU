#include <iostream>
#include <string>
using namespace std;

class toys
{
	public:
	virtual void game() = 0;
};

class babybon : public toys
{
	public:
    	virtual void game()	override
    	{
    		cout<<"yaaaa yaaaa yaaaa"<<endl;
		}
};

class Car : public toys
{
	public:
		virtual void game() override
		{
			cout<<"wroom! wroom!"<<endl;
		}
};

class bear : public toys
{
	public:
		virtual void game() override
		{
			cout<<"wraaaa!"<<endl;
		}
};

class child
{
	public:
		void game(toys *toys)
		{
			toys->game();
		}
};

int main()
{
	child chil;
	bear  misha;
	Car  tesla;
	babybon baby;
	
	chil.game(&tesla);
	chil.game(&misha);
	chil.game(&baby);
	
	return 0;
};
