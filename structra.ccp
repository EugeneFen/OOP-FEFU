#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

struct size{ // габаритныеразмеры
float x;
float y;
float z;
};

struct notebook{
string model; // наименование
float w; // вес
int price; // цена
struct size metre;
};
//Написать функцию, которая читает данные о ноутбуках из файла note.txt
//в структуру приведенного вида. 
//Структура note.txt: первые 4 байта (целое) — число записей в файле; 
//далее записи в формате структуры NOTEBOOK.

void readFile(notebook *book, int z)
{
	int y;
	ifstream file;
	file.open("note.txt",ios_base::in|ios_base::binary);
	if (file.is_open())
	{
		file>>y;
		for(int i=0; i<z; i++)
		{
			file>>book[i].model;
			file>>book[i].metre.x;
			file>>book[i].metre.y;
			file>>book[i].metre.z;
			file>>book[i].w;
			file>>book[i].price;
		}
	}
	else {
		cout<<"oops";
	}
	file.close();
}

//Написать функцию, которая записывает содержимое структуры в конец бинарного файла. 
//Структура бинарного файла:первые 4 байта (целое) — число записей в файле; 
//далее записи в форматеструктуры NOTEBOOK. 

void writeFile(notebook *book, int z)
{
	ofstream file;
	file.open("output.txt",ios_base::app|ios_base::ate|ios_base::binary);
	if (file.is_open())
	{
		for(int i=0; i<z; i++)
		{
		file<<book[i].model<<"\n";
		file<<book[i].metre.x<<"\n";
		file<<book[i].metre.y<<"\n";
		file<<book[i].metre.z<<"\n";
		file<<book[i].w<<"\n";
		file<<book[i].price<<"\n";
    	}
	}
	file.close();
}

int main()
{
	int n;	
	int Obem=0;
	int w=0;
	ifstream file;
	file.open("note.txt");
	if (file.is_open())
	{
     file>>n;
	}
	file.close();	
	notebook *book=new notebook[n];
	readFile(book, n);
	
	for(int i=0; i<n; i++)
	{
		if ((Obem<1000001) and (w<286))
		{
			Obem=Obem+book[i].metre.x*book[i].metre.y*book[i].metre.z;
			w=i+1;
		}
	}
	
    cout<<w<<" "<<Obem;
	writeFile(book, w);	
	delete[] book;
}
