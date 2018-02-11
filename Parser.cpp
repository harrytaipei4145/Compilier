#include<iostream>
#include<fstream>
#include<string>
using namespace std;
//k紀錄路徑儲存幾個
//j目前arr儲存位置
//arr儲存路徑字元
//num每一個儲存多少字元


int main(){
	fstream f_in,f_out;
	char a[128];
	char arr[128];
	char arr_tem[128];
	int num[128];
	int x=0,word=0,k=0;
	int check=0;
	int temp = 0;
	int d = 0,line=3; 
	int tem1=0,tem_check;
	string filename1,filename2;
	cout << "input filename:";
	cin >> filename1;
	if (filename1 == "XSL-1.txt")
	filename2 = "Result-1.txt";
	else if (filename1 == "XSL-2.txt")
	filename2 = "Result-2.txt";
	else if (filename1 == "XSL-3.txt")
	filename2 = "Result-3.txt";
	f_in.open(filename1, ios::in);
	f_out.open(filename2, ios::out);
	f_in.getline(a, sizeof(a), '\n');
	f_in.getline(a, sizeof(a), '\n');
	f_in.getline(a, sizeof(a), '\n');
	int j = 0;
	int error = 0;
	while (f_in.getline(a, sizeof(a), '\n'))
	{
		line++;
		size_t length = strlen(a);
		int i = 0;
		while (i < length)
		{

			if (a[i] == '<')
			{
				i++;
				while (a[i] != '>')
				{
					if (a[i] == 'x' && a[i + 1] == 's' && a[i + 2] == 'l' && a[i + 3] == ':')
					{
						i = i + 4;
						if (a[i] == 't')
						{
						   i++;
						   if (a[i] == 'e' && a[i + 1] == 'm')
						   {
							   if (check == 1)
							   {
								   j = j - num[k-1];
								   k--;
								   i = length;
								   check = 0;
								   tem_check = 0;
								   break;
							   }
							   else
							   {
								   int par = 0;
								   if (tem_check == 1)
								   {
									   error = 1;
									   f_out.close();
									   f_out.open(filename2, ios::out);
									   f_out << "Error" << "\n" << "line	" << tem1 << "	<xsl:t"<<arr_tem<<">" <<endl;
									   f_out << "line	" << line << "	<xsl:t";
									   while (a[i]!='>')
									   {
										   f_out << a[i];
										   i++;
									   }
									   f_out<< ">" << endl;
									   break;
								   }
								   
								   tem_check = 1;
								   tem1 = line;
								   if (d > 0)
								   {
									   f_out << "----------" << endl;
								   }
								   d++;
								   f_out << "tags:xsl:template" << endl;
								   while (a[i - 1] != '"')//skip
								   {
									   arr_tem[par]=a[i];
										   par++;
									   i++;
								   }
								   f_out << "select:";
								   temp = 0;
								   while (a[i] != '"')
								   {
									   arr_tem[par] = a[i];
									   par++;
									   f_out << a[i];
									   arr[j] = a[i];
									   i++;
									   j++;
									   temp++;
									   
								   }
								   arr_tem[par] = '"';
								   par++;
								   num[k] = temp;//記錄檔名字數
								   k++;
								   f_out << "\n"<<"parameters:null" << endl;

								   break;
							   }
							   
	  					   }
		  				   else if (a[i] == 'e' && a[i + 1] == 'x')
						   {
						   i = length;
						   break;
						   }
						
						}
						else if (a[i] == 'v')
						{
							if (d > 0)
							{
								f_out << "----------" << endl;
							}
							d++;
							f_out << "tags:xsl:value-of" << endl;
							while (a[i - 1] != '"')//skip
							{
								i++;
							}
							f_out << "select:" ;
							int p = 0;
							for (int count = 0; count < k; count++)
							{
								if (count>0)
									f_out << "/";
								for (int count1 = 0; count1 < num[count]; count1++)
								{
									f_out << arr[p + count1];
								}
								p = p + num[count];
							}
							if (k>0)
							{
								f_out << "/";
							}
							while (a[i] != '"')
							{

								f_out << a[i];
								i++;
							}
							f_out << "\n" << "parameters:null" << endl;
							break;
						}
						else if (a[i] == 'f')
						{
							
							if (check == 1)
							{
								j = j - num[k - 1];
								k--;
								i = length;
								check = 0;
								break;
							}
							else
							{
								
								if (d > 0)
								{
									f_out << "----------" << endl;
								}
								d++;
								while (a[i - 1] != '"')//skip
								{
									i++;
								}
								f_out << "tags:xsl:for-each" << endl;
								f_out << "select:";
								int p = 0;
								for (int count = 0; count < k; count++)
								{
									for (int count1 = 0; count1 < num[count]; count1++)
									{
										f_out << arr[p + count1];
									}
									p = p + num[count];
								}
								if (k>0)
								{
									f_out << "/";
								}
								temp = 0;
								int check_f=0;
								char arr_f[128];
								int par = 0;
								while (a[i] != '"')
								{
									if (a[i] == '[')
									{
										i++;
										check_f = 1;
										while (a[i] != ']')
										{
											arr_f[par] = a[i];
											i++;
											par++;
										}
										i++;
									}
									else
									{
										f_out << a[i];
										arr[j] = a[i];
										i++;
										j++;
										temp++;
									}
									

								}
								num[k] = temp;//記錄檔名字數
								k++;
								if (check_f == 1)
								{
									f_out << "\n" << "parameters:";
									for (int u = 0; u < par; u++)
									{
										f_out << arr_f[u];
									}
									f_out << endl;
								}
								else
								f_out << "\n" << "parameters:null" << endl;
								break;
							}
							
						}
						else if (a[i] == 's')
						{
							i++;
							if (a[i] == 't')
							{

									i = length;
									check = 0;
									break;
							}
							else if (a[i] == 'o')
							{
								if (d > 0)
								{
									f_out << "----------" << endl;
								}
								d++;
								f_out << "tags:xsl:sort" << endl;
								f_out << "select:";
								while (a[i - 1] != '"')//skip
								{
									i++;
								}
								int p = 0;
								for (int count = 0; count < k; count++)
								{
									if (count>0)
										f_out << "/";
									for (int count1 = 0; count1 < num[count]; count1++)
									{
										f_out << arr[p + count1];
									}
									p = p + num[count];
								}
								
								
								
								f_out << "\n" << "parameters:";
								while (a[i] != '"')
								{

									f_out << a[i];
									i++;
								}
								f_out << "\n";
								break;
							}
						
						}
							 
						else if (a[i] == 'i')
						{
							if (check == 1)
							{
								check = 0;
								break;
							}
						
							else
							{
								if (d > 0)
								{
									f_out << "----------" << endl;
								}
								d++;
								f_out << "tags:xsl:if" << endl;
								f_out << "select:";
								while (a[i - 1] != '"')//skip
								{
									i++;
								}
								int p = 0;
								for (int count = 0; count < k; count++)
								{
									if (count>0)
										f_out << "/";
									for (int count1 = 0; count1 < num[count]; count1++)
									{
										f_out << arr[p + count1];
									}
									p = p + num[count];
								}



								f_out << "\n" << "parameters:";
								while (a[i] != '"')
								{

									f_out << a[i];
									i++;
								}
								f_out << "\n";
								break;
							}
							
						}
					}
					else if (a[i] == '/')
					{
						check = 1;
						i++;
					}
					else
					{
						i++;
					}
				}
				break;
			}
			else
			{
				i++;
			}
		}
		if (error == 1)
			break;
	}
			

	system("pause");
	return 0;
}