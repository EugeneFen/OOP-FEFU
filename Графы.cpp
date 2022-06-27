#include<iostream>
#include <queue>
#include <string>
#include <fstream>
using namespace std;

class Graf
{
	private:
		int **distance; //растояние
		string *name; //названия
		int vertex; // количество ребер и вершин
		bool *visited;
		bool *used;
		queue <int> peak;
		queue <int> track;
		bool permit;
		
		void Dfs(int value)
		{
			peak.push(value);
			visited[value] = true;				
			for(int i=0; i<vertex; i++)
			{
				if((distance[value][i] != 0) and (!visited[i]))
				{
					Dfs(i);
				}
			}
		};
		
		bool Check()
		{			
			int ti=0;
			int scorer;
			
			while (ti <vertex)
			{
				scorer = 0;				
				for(int j=0; j<vertex; j++)
				{
					if(distance[ti][j] != 0) 
					{
						scorer++;
					}							
				}
				if(scorer == 0) return false;				
				ti++;
			}
			return true;					
		}
		
	public:
		Graf()
		{
			string letter_1, letter_2;
			int value,k,t;
			
			ifstream file;                 
			file.open("note.txt");
			if (file.is_open())           
			{
				cout<<"File open."<<endl;
				file>>vertex; //сколько имен в графе
								
				visited = new bool[vertex];
				name = new string[vertex];	//выделяем память для имен				
				distance = new int* [vertex]; //количество строк в масиве				
				for (int i = 0; i<vertex; i++)
					distance[i] = new int[vertex]; //количество столбцов в масиве
				
				for(int i=0; i<vertex; i++) //заполняем масив имен
					file>>name[i];
				
				for(int i=0; i<vertex; i++)
					for(int j=0; j<vertex; j++)
						distance[i][j] = 0;
				
				while(!file.eof()) //  feof(file)
				{
					file>>letter_1;
					file>>letter_2;
					file>>value;
					for(int i=0; i<vertex; i++)
					{
						if(letter_1 == name[i]) k=i;
						if(letter_2 == name[i]) t=i;
					}
					distance[k][t] = value;
					distance[t][k] = value;
				}
				permit = Check();
				//cout<<permit<<endl;
			}
			else cout<<"File is not open";
			file.close(); 
		}
		
		void Run_Dfs(int value)
		{
			for (int i = 0; i<vertex; i++) visited[i] = false;			
				Dfs(value);			
		}
		
		void Write_Dfs()
		{
			ofstream file;                                        
			file.open("output1.txt", ios::out);
			if (file.is_open())
			{				
				for(int i=0; i<vertex; i++)
				{
					if(!peak.empty())
					{
						int buff = peak.front();
						peak.pop();
						file<<name[buff]<<"  ";
					}
				}
				file<<"\n";
			}
			else cout<<"File is not open"<<endl;
			file.close();
		}
		
		void Prim(int value)
		{
			used = new bool[vertex];		
			for (int i=0; i<vertex; i++) used[i] = false;			
			used[value] = true;
			
			if(permit)
			{							
				for(int k = 0; k<vertex-1; k++)
				{
					int minx = -1 , miny = -1;
			        for(int i=0; i<vertex; i++)
			            if(used[i])
			                for(int j=0; j<vertex; j++)
			                    if(!used[j] && distance[i][j] > 0 && (miny == -1 || distance[i][j] < distance[miny][minx]))
			                    	miny = i, minx = j;
		                             
		        used[minx] = true;
		        track.push(miny);
		        track.push(minx);
				}
			}
			
		}
		
		void Write_prim()
		{
			cout<<"Write P"<<endl;
			ofstream file;                                        
			file.open("output2.txt", ios::out);
			if (file.is_open())
			{				
				for(int i=0; i<vertex; i++)
				{
					//cout<<track.size()<<endl;
					if(!track.empty())
					{
						int buff_1 = track.front();
					//	cout<<buff_1<<endl;
						track.pop();
						int buff_2 = track.front();
					//	cout<<buff_1<<endl;
						track.pop();
						if(name[buff_1] != name[buff_2])
						file<<name[buff_1]<<"  "<<name[buff_2]<<"  "<<distance[buff_1][buff_2]<<"\n";
					}
					
				}
				file<<"\n";
			}
			else cout<<"File is not open"<<endl;
			file.close();
		}
		
		void Write_graf()
		{
			ofstream file;                                        
			file.open("output.txt", ios::out);
			if (file.is_open())
			{
				cout<<"File open"<<endl;
				file<<vertex<<" x "<<vertex<<"\n";
				
				file<<"    ";
				for(int i=0; i<vertex; i++)
					file<<name[i]<<" ";
				file<<"\n";
				
				for(int i=0; i<vertex; i++) //строка
				{
					file<<name[i]<<"  ";
					for(int j=0; j<vertex; j++) //столбец
					{
						file<<distance[i][j]<<"  ";
					}
					file<<"\n";
				}
			}
			else cout<<"File is not open"<<endl;
			file.close();
		}
		
		~Graf()
		{			
			for (int i = 0; i<vertex; i++) //удвление солбцов масива
			{
			    delete[] distance[i];	    
			}			
			delete[] distance;			
			delete[] name;
			delete[] visited;
			delete[] used;
		}
};

int main()
{
	Graf a;
	a.Run_Dfs(0);
	a.Write_Dfs();
	a.Prim(0);
	//a.Write_prim();
	a.Write_graf();
	return 0;
};
