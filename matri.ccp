#include <iostream>
#include <cmath>
using namespace std;


int main() 
{
	setlocale (LC_ALL,"Rus"); //чтобы можно было читать русский язык
	
	int N; //строки
	int M; //столбцы
	int coin = 0;
	int point;
	int v1;
	int v2;
	int m1;
	int poz;
	
	cin>>N>>M; cout<<endl;
	
	
	int **arr = new int* [N]; //количество строк в масиве
	
	for (int i = 0; i<N; i++)
	{
		arr[i] = new int[M]; //количество столбцов в масиве
	}
	/////////////////////////////////////////////////////////////////////
	
	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j<M; j++)
		{
			coin++;
			arr[i][j] = coin; //заполним масив по порядку
		}
	}  
	
/*		for (int i = 0; i<N; i++)
	{
		for (int j = 0; j<M; j++)
		{
			cout<<i<<','<<j<<':';//заполним масив ручками с консоли
			cin>>arr[i][j];
		}
	}  
*/	
	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j<M; j++)
		{
			cout<<arr[i][j]<<"\t"; //вывод масива на экран
		}
		cout<<endl;
	}  
	
	cout<<endl;
		
	if (N>M)
	{
		v1 = v2 = M;
	}
	else
	{
		if (M>N)
	     {
	     	v1 = v2 = N;
	     	
		 }
		 else 
		 {
		 	v1 = v2 = N;
		 }
	}
	
	for (int i = 0; i<v1; i++)
	{
		point = abs(arr[i][0]);
		for (int j = 0; j<v2; j++)
		{
		     if (point<abs(arr[i][j]))
		     {
		     	point = arr[i][j];	
				m1 = j;	 
				
			 }
		}	
	    if (i!=m1)
	    {
	    	poz = arr[i][i];
	    	arr[i][i] = point;
	    	arr[i][m1] = poz; 
		}
	}  
	
	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j<M; j++)
		{
			cout<<arr[i][j]<<"\t"; //вывод масива на экран
		}
		cout<<endl;
	}  
	
	///////////////////////////////////////////////////////////
	for (int i = 0; i<N; i++) //удвление солбцов масива
	{
	    delete[] arr[i];	    
	}
	
	delete[] arr; //удаление всех строк
	return 0;
}
