#include<iostream>
#include<fstream>
using namespace std;



int main(){
	fstream f_in,f_out;
	char a[128];
	int x=0,word=0;
	int temp;
	f_in.open("input.xml", ios::in);
	f_out.open("output.txt", ios::out);
	while (f_in.getline(a, sizeof(a), '\n'))
	{
		size_t length = strlen(a);
		int i = 0;
		while(i < length)
		{
			temp = a[i + 1];
			if (x == 1 && a[i] != '"')
			{
				f_out << a[i];
			}
			
			else
			{
				if (a[i] == '<')
				{
					if (word == 0)
						f_out << a[i] << endl;
					else
					{
						f_out << "\n" << a[i] << endl;
						word = 0;
					}
				}

				else if (a[i] == '>')
				{
					if (word == 0)
					{f_out << a[i] << endl;
					}
						
					
					else
					{
						f_out << "\n" << a[i] << endl;
						word = 0;
					}
				}
				else if (a[i] == '?')
				{
					if (word == 0)
						f_out << a[i] << endl;
					else
					{
						f_out << "\n" << a[i] << endl;
						word = 0;
					}
				}
				else if (a[i] == ':')
				{
					if (word == 0)
						f_out << a[i] << endl;
					else
					{
						f_out << "\n" << a[i] << endl;
						word = 0;
					}
				}
				else if (a[i] == '/')
				{
					if (word == 0)
						f_out << a[i] << endl;
					else
					{
						f_out << "\n" << a[i] << endl;
						word = 0;
					}
				}
				else if (a[i] == '=')
				{
					if (word == 0)
						f_out << a[i] << endl;
					else
					{
						f_out << "\n" << a[i] << endl;
						word = 0;
					}
				}
				else if (a[i] == '"')
				{

					if (x == 0)
					{
						f_out << a[i] << endl;
						x = 1;
					}
					else if (x==1)
					{
						
						if (a[i + 1] == '<' || a[i + 1] == '>' || a[i + 1] == '?' || a[i + 1] == ':' || a[i + 1] == '/' || a[i + 1] == '=' || a[i + 1] == ' ' || a[i + 1] == '\n' || a[i + 1] == '\t')
						{
							f_out << "\n" << a[i] << endl;
							x = 0;
						}
						else
						{
							x = 1;
							i++;
							
						}
						


					}
				}
				else if (a[i] == ' ')
				{
					
					if (word == 1)
					{
						f_out << "\n";
						word = 0;
					}
				}
				else if (a[i] == '\t')
				{
				}
				else
				{
					f_out << a[i];
					word = 1;
				}

			}
			i++;
		}
		
		}
	

	system("pause");
	return 0;
}