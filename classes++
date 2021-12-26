#include <iostream>
#include <string>
using namespace std;

class people
{
    public:  
	string name;
	string fio;
	string twoname;
	int age;
};


class exhibit 
{
  private:

    int yearExp; 
    string nameExp;
    
    bool chekYear(int p) 
    {
    	bool Four;
    	if (p<=2021)
    	{
    		Four = true;
		}
		else
		{
			Four = false;
		}
    	return Four;
	};
  public:  	
	   	
	void SetYear(int valueYear) 
	{
		if (chekYear(valueYear))
		{
			yearExp = valueYear;
		}
		else
		{
			cout<<"error"<<endl;
		}
		
	};
	
	void SetName(string valueName)
	{
		nameExp = valueName;
	}
	
	exhibit (const exhibit & other) 
    {
    	this->yearExp = other.yearExp;
    	this->nameExp = other.nameExp;
	}
	
	exhibit & operator = (const exhibit & other) 
    {
    	if (this == & other) 
    	{
    		return *this;
		}
    	this->yearExp = other.yearExp;
    	this->nameExp = other.nameExp;
    	
    	return *this;
	}
};

class visitor : public people 
{ 
   private:
    string status; 
    int cash;    
    
    public:
    	void SetName(string valueName)
    	{
    		name = valueName;
		}
		void SetStatus(string valueStatus)
		{
			status = valueStatus;
		}
		string GetStatus()
		{
			return status;
		}
};

template<class T> 
class excursion 
{
  private:  	
    string NameExc; 
    int Price; 
    exhibit One[5];
    T value;
	
    public:
   	void SetValue(T value)
	{
		this->value = value;
	}
    	void SetName(string valueName)
    	{
    		NameExc = valueName;
		}
		void SetPrice(int valueprice)
		{
			Price = valueprice;
		}
		void Exp()
		{
		for(int p=0; p<5; p++)
        {
    	One[p].SetName("put");
    	One[p].SetYear(1930);
     	}
		}
		void printv()
		{
			cout<<"value  "<<value<<endl;
		}
};

class guide : public people 
{ 
   private:
    
    public:
     	void SetName(string valueName)
    	{
    		name = valueName;
		}
		void SetFio(string valueFio)
		{
			fio = valueFio;
		}
	    void SetTwoName(string valueTwoName)
		{
			twoname = valueTwoName;
		}
};
