#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<class T> class People
{
	public:
		People(T value)
		{
			name.push_back(value);
		}
		
		void Writeln()
		{
			cout<<"Name: "<<endl;
			Write_name(name);
		}
		
		void Add(T value)
		{
			name.push_back(value);
		}
		
		void Search(T value)
		{
			if(Search_name(name,value)) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		
		T Write_number(int i)
		{
			if (i <= name.size())
			{
				return name(i);
			}
			else return -1;
		}
		
	private:		
		vector<T> name;
		
		void Write_name(vector<const T> a)
		{
		    typedef typename vector<const T>::iterator iteratorV;
		    iteratorV iteratorBegin=a.begin();
		    for (iteratorBegin = a.begin(); iteratorBegin != a.end(); ++iteratorBegin)
		    {
		        cout<<iteratorBegin<<endl;
		    }
		}
		
		bool Search_name(vector<const T> a, T value)
		{
			int i =0;
		    while(i != a.size())
		    {
		    	if (a(i) == value)
		    	{
		    		return true;
				}
		    	i++;
			}
			if(i == a.size()) return false;
		}
};
