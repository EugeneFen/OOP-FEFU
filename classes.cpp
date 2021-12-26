#include <iostream>
#include <string>
using namespace std;

class exhibit //экспонат
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
	
	exhibit (const exhibit & other) //кнструктор копирования
    {
    	this->yearExp = other.yearExp;
    	this->nameExp = other.nameExp;
	}
	
	exhibit & operator = (const exhibit & other) //перегрузка оператора присваивания
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

class visitor //посетитель
{ 
   private:
    string status; 
    string NameVis; 
    int cash;   
    
    public:
    	void SetName(string valueName)
    	{
    		NameVis = valueName;
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

class excursion //экскурсия
{
  private:  	
    string NameExc; 
    int Price; 
    exhibit One[5];
	
    public:
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
};

class guide //экскурсовод
{ 
   private:
   	string nameGui;
    string fioGui;
    string twonameGui;
    
    public:
     	void SetName(string valueName)
    	{
    		nameGui = valueName;
		}
		void SetFio(string valueFio)
		{
			fioGui = valueFio;
		}
	    void SetTwoName(string valueTwoName)
		{
			twonameGui = valueTwoName;
		}
};
