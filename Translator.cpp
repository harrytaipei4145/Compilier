#include<iostream>
#include<fstream>
#include<string>
#include<vector>



using namespace std;
//k魁隔畖纗碭
//jヘ玡arr纗竚
//arr纗隔畖じ
//num–纗ぶじ

int  comparei(float a, float b)
{
	if (a > b)
		return 1;
	else
		return 0;
}
int compare(string a, string b)
{
	int size;
	int bit=0;
	int aa = 0;
	if (a.size() > b.size())
		size = b.size();
	else
	size = a.size();
	while (aa<size)
	{
		if (a[aa] > b[aa])
		{
			bit = 1;
			break;
		}
		else if (a[aa] < b[aa])
		{
			bit = 2;
			break;
		}
		else if (a[aa] == b[aa])
		{
			aa++;
		}
	}
	if (bit == 1)
	{
		return 1;
	}
	else if (bit == 2)
		return 0;
	else
	{
		if (a.size() > b.size())
		{
			return 1;
		}
		else return 0;
	}
}
void changei(float *i, float *j)
{
	float temp;
	temp = *j;
	*j = *i;
	*i = temp;
}
void change(string *i, string *j)
{
	string temp;
	temp = *j;
	*j = *i;
	*i = temp;
}
class document
{
public:
	string name;
	document* right=NULL;
	document* left = NULL;
	document* next = NULL;
	string title="no";
	string author="no" ;
	string country="no" ;
	int price=-999;
	int year=-999;
	float price_num = -999.0;
	float year_num = -999.0;
	char com,wor='n';
	char sort;
	char for_each;
	string for_each_s;

	
};
int main(){
	fstream f_in,f_out,f_xml;
	char a[128];
	char arr[128];
	char arr_tem[128];
	int num[128];
	int x=0,word=0,k=0;
	int check=0;
	int temp = 0;
	int d = 0,line=3; 
	int tem1=0,tem_check;
	document *f_docu=new document;
	string filename1, filename2, filename3;
	cout << "input filename:";
	cin >> filename1;
	if (filename1 == "XSL-1.txt")
		filename2 = "select-1.txt";
	else if (filename1 == "XSL-2.txt")
		filename2 = "select-2.txt";
	else if (filename1 == "XSL-3.txt")
		filename2 = "select-3.txt";
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
								   num[k] = temp;//癘魁郎计
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
								num[k] = temp;//癘魁郎计
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
			


	//--------------------------------------------------------------------------------------------------------------------
	f_in.close();
	f_out.close();
	if (filename2 == "select-1.txt")
		filename1 = "Result-1.txt";
	else if (filename2 == "select-2.txt")
		filename1 = "Result-2.txt";
	else if (filename2 == "select-3.txt")
		filename1 = "Result-3.txt";
	f_in.open(filename2, ios::in);
	f_out.open(filename1, ios::out);
	int count_word=0;
	char check_tag;
	document *head = new document;
	strcpy(a, "");
	string document_temp,temp_word;
	int check_f = 0;
	while (f_in.getline(a, sizeof(a), '\n'))
	{
		
		if (a[0] == 't')
		{
				check_tag = a[9];
				continue;
		}
		else if (a[0] == 's')
		{
			if (check_tag == 't')
			{
				count_word = 8;
				while (a[count_word]!=NULL)
				{
					temp_word = a[count_word];
					document_temp = document_temp.append(temp_word,0,1);
					count_word++;
				}
				head->name = document_temp;
				document_temp.clear();
			}
			else if (check_tag == 'f')
			{
				document *node_save;
				
				document *node_temp ;
				count_word = 9+head->name.size();
				check_f = 1;
				int pp = 0;
				while (a[count_word] != NULL)
				{
					temp_word = a[count_word];
					document_temp = document_temp.append(temp_word, 0, 1);
					count_word++;
					if (a[count_word] == '/')
					{
						document *node = new document;
						count_word++;
						node->name = document_temp;
						if (pp == 0)
						{
							node_save = node;
							node_temp = node;
							pp++;
						}
						else
						{
							node_temp->right = node;
							node_temp->right->left = node_temp;
							node_temp = node_temp->right;
						}
						document_temp.clear();
						
					}
				
				}//while}
				document *node = new document;
				node->name = document_temp;
				if (pp == 0)
				{
					node_save = node;
					node_temp = node;
					pp++;
				}
				else
				{
					node_temp->right = node;
					node_temp->right->left = node_temp;
					node_temp = node_temp->right;
					f_docu = node_temp;
				}
				document_temp.clear();
				if (head->right==NULL)
				{
					head->right = node_save;
					head->right->left = head;
				}
				else
				{
					node_temp = head->right;
					while (true)
					{
						if (node_temp->next==NULL)
						{
							node_temp->next = node_save;
							node_temp->next->left = head;
							break;
						}
						else
						{
							node_temp = node_temp->next;
							continue;
						}


					}
				}
			}//else if}
			else if (check_tag == 'v')
			{
				count_word = 9 + head->name.size();
				document *node_temp;
				node_temp = head->right;
				while (a[count_word] != NULL)
				{
					temp_word = a[count_word];
					document_temp = document_temp.append(temp_word, 0, 1);
					count_word++;
					if (a[count_word] == '/')
					{
						count_word++;
						while (true)
						{
							if (node_temp->name == document_temp)
							{
								if (node_temp->right!=NULL)
								node_temp = node_temp->right;
								document_temp.clear();
								break;
							}
							else
							{
								node_temp = node_temp->next;
								continue;
							}
						}
						
					}

				}//while}
				if (document_temp == "title")
				node_temp->title.insert(0, "yes");
				else if (document_temp == "author")
				node_temp->author.insert(0,"yes");
				else if (document_temp == "country")
				node_temp->country.insert(0,"yes");
				else if (document_temp == "price")
				node_temp->price = 0;
				else if (document_temp == "year")
				node_temp->year = 0;

				document_temp.clear();
			}//elseif v
			else if (check_tag == 'i')
			{
				count_word = 9 + head->name.size();
				document *node_temp;
				node_temp = head->right;
				while (a[count_word] != NULL)
				{
					temp_word = a[count_word];
					document_temp = document_temp.append(temp_word, 0, 1);
					count_word++;
					if (a[count_word] == '/')
					{
						count_word++;
						while (true)
						{
							if (node_temp->name == document_temp)
							{
								if (node_temp->right != NULL)
									node_temp = node_temp->right;
								document_temp.clear();
								break;
							}
							else
							{
								node_temp = node_temp->next;
								continue;
							}
						}

					}

				}//while}
				strcpy(a, "");//睲array
				f_in.getline(a, sizeof(a), '\n');
				int number=0;
				int gg = 0;
				node_temp->wor = a[11];
				if (a[11] == 'p')
				{
					node_temp->com = a[18];
					gg = 22;
					while (a[gg] != NULL)
					{
						number = number * 10 + a[gg]-48;
						gg++;
					}
					node_temp->price_num = number;
				
				}
				else if (a[11] == 'y')
				{
					node_temp->com = a[17];
					gg = 21;
					while (a[gg] != NULL)
					{
						number = number * 10 + a[gg] - 48;
						gg++;
					}
					node_temp->year_num = number;
				}
				document_temp.clear();
			}//elseif i
			else if (check_tag == 's')
			{
				count_word = 9 + head->name.size();
				document *node_temp;
				node_temp = head->right;
				while (a[count_word] != NULL)
				{
					temp_word = a[count_word];
					document_temp = document_temp.append(temp_word, 0, 1);
					count_word++;
					if (a[count_word] == '/')
					{
						count_word++;
						while (true)
						{
							if (node_temp->name == document_temp)
							{
								if (node_temp->right != NULL)
									node_temp = node_temp->right;
								document_temp.clear();
								break;
							}
							else
							{
								node_temp = node_temp->next;
								continue;
							}
						}

					}

				}//while}
				strcpy(a, "");//睲array
				f_in.getline(a, sizeof(a), '\n');
				node_temp->sort=a[11];
				document_temp.clear();
			}//elseif s
		}

		else if (a[0] == 'p')
		{
			if (check_f == 1)
			{
				int xx,count_p;
				string temp_p;
				string document_p;
				check_f = 0;
				f_docu->for_each = a[11];
				if (f_docu->for_each == 'a')
				{
					xx = 19;
					while (a[xx] != 39)
					{
						temp_p = a[xx];
						document_p = document_p.append(temp_p, 0, 1);
						xx++;
					}
					f_docu->for_each_s = document_p;
					document_p.clear();
				}
				else if (f_docu->for_each == 'c')
				{
					xx = 20;
					while (a[xx] != 27)
					{
						temp_p = a[count_p];
						document_p = document_p.append(temp_p, 0, 1);
						count_p++;
					}
					f_docu->for_each_s = document_p;
					document_p.clear();
				}
				else if (f_docu->for_each == 't')
				{
					xx = 18;
					while (a[xx] != 27)
					{
						temp_p = a[count_p];
						document_p = document_p.append(temp_p, 0, 1);
						count_p++;
					}
					f_docu->for_each_s = document_p;
					document_p.clear();
				}
			}
			
		}
		else
		{
			strcpy(a, "");//睲array
			continue;
		}
		

		strcpy(a, "");//睲array
	}




	//---------------------------------------------------------------------------------------------------
	filename3 = "XML.txt";
	f_xml.open(filename3, ios::in);
	document *link;
	int test = 0;
	link = head;
	vector<string> tit, aut, cou;
	vector<float> pri, yea;
	int t_c, a_c, c_c, p_c, y_c;
	float year_t, price_t;
	char sort_temp;
	while (f_xml.getline(a, sizeof(a), '\n'))
	{
		
		count_word = 0;
		while (a[count_word] != '<')
		{
			count_word++;
		}
		count_word++;
		if (a[count_word] == '/')
		{
			
			if (link != head)
			{
				link = link->left;
				if (link->name == head->name)
				{					
					if (sort_temp == 't')
					{
						for (int ex = tit.size()-1; ex >= 0; ex--)
						{
							
							for (int ey = 0; ey < ex; ey++)
							{
								if (compare(tit[ey], tit[ey + 1]) == 1)
								{
									change(&tit[ey], &tit[ey + 1]);
									change(&aut[ey], &aut[ey + 1]);
									change(&cou[ey], &cou[ey + 1]);
									changei(&pri[ey],& pri[ey + 1]);
									changei(&yea[ey], &yea[ey + 1]);
								}//1璶ユ传
							}
						}
					}
					else if (sort_temp == 'a')
					{
						for (int ex = aut.size() - 1; ex >= 0; ex--)
						{
							for (int ey = 0; ey < ex; ey++)
							{
								if (compare(aut[ey], aut[ey + 1]) == 1)
								{
									change(&tit[ey], &tit[ey + 1]);
									change(&aut[ey], &aut[ey + 1]);
									change(&cou[ey], &cou[ey + 1]);
									changei(&pri[ey], &pri[ey + 1]);
									changei(&yea[ey], &yea[ey + 1]);
								}//1璶ユ传
							}
						}
					}
					else if (sort_temp == 'c')
					{
						for (int ex = cou.size() - 1; ex >= 0; ex--)
						{
							for (int ey = 0; ey < ex; ey++)
							{
								if (compare(cou[ey], cou[ey + 1]) == 1)
								{
									change(&tit[ey], &tit[ey + 1]);
									change(&aut[ey], &aut[ey + 1]);
									change(&cou[ey],& cou[ey + 1]);
									changei(&pri[ey],& pri[ey + 1]);
									changei(&yea[ey], &yea[ey + 1]);
								}//1璶ユ传

							}
						}
					}
					else if (sort_temp == 'p')
					{
						for (int ex = pri.size() - 1; ex >= 0; ex--)
						{
							for (int ey = 0; ey < ex; ey++)
							{
								if (comparei(pri[ey], pri[ey + 1]) == 1)
								{
									change(&tit[ey], &tit[ey + 1]);
									change(&aut[ey],& aut[ey + 1]);
									change(&cou[ey], &cou[ey + 1]);
									changei(&pri[ey],& pri[ey + 1]);
									changei(&yea[ey],& yea[ey + 1]);
								}//1璶ユ传

							}
						}
					}
					else if (sort_temp == 'y')
					{
						for (int ex = yea.size() - 1; ex >= 0; ex--)
						{
							for (int ey = 0; ey < ex; ey++)
							{
								if (comparei(yea[ey], yea[ey + 1]) == 1)
								{
									change(&tit[ey], &tit[ey + 1]);
									change(&aut[ey], &aut[ey + 1]);
									change(&cou[ey], &cou[ey + 1]);
									changei(&pri[ey],& pri[ey + 1]);
									changei(&yea[ey], &yea[ey + 1]);
								}//1璶ユ传

							}
						}
					}
					int cancel = 0;
					for (int yy = 0; yy < tit.size(); yy++)
					{

						if (t_c == 1)
							f_out << tit[yy] << " ";
						if (a_c == 1)
							f_out << aut[yy] << " ";
						if (c_c == 1)
							f_out << cou[yy] << " ";
						if (p_c == 1)
							f_out << pri[yy] << " ";
						if (y_c == 1)
							f_out << yea[yy] << " ";
						f_out << endl;
						if (yy == tit.size() - 1)
							cancel = 1;
					}
					if (cancel == 1)
					{
						tit.clear();
						aut.clear();
						cou.clear();
						pri.clear();
						yea.clear();
					}
				}//
			}
			
		}
		else
		{
			
			while (a[count_word] != '>')
			{
				temp_word = a[count_word];
				document_temp = document_temp.append(temp_word, 0, 1);
				count_word++;
			}
			if (document_temp == head->name)
			{
				document_temp.clear();
				continue;
			}
				
			if (link->right != NULL)
			{
				
				if (document_temp == link->right->name)
				{
					
					link = link->right;
					document_temp.clear();
					continue;
				}
				else if (document_temp == link->right->next->name)
				{
					link = link->right->next;
					document_temp.clear();
					continue;
				}
				else
					link = link->next;
			}
			else
			{
				sort_temp = link->sort;
				
				count_word++;
				if (link->title == "yesno")
					t_c = 1;
				else
					t_c = 0;
				if (link->author == "yesno")
					a_c = 1;
				else
					a_c = 0;
				if (link->country == "yesno")
					c_c = 1;
				else
					c_c = 0;
				if (link->price == 0)
					p_c = 1;
				else
					p_c = 0;
				if (link->year == 0)
					y_c = 1;
				else
					y_c = 0;

				
				
				if (document_temp == "title")
				{

					document_temp.clear();
					while (a[count_word] != '<')
					{
						temp_word = a[count_word];
						document_temp = document_temp.append(temp_word, 0, 1);
						count_word++;
					}
					tit.push_back(document_temp);
					document_temp.clear();
					continue;
				}
				else if (document_temp == "author")
				{

					document_temp.clear();
					while (a[count_word] != '<')
					{
						temp_word = a[count_word];
						document_temp = document_temp.append(temp_word, 0, 1);
						count_word++;
					}
					aut.push_back(document_temp);
					document_temp.clear();
					continue;
				}
				else if (document_temp == "country")
				{

					document_temp.clear();
					while (a[count_word] != '<')
					{
						temp_word = a[count_word];
						document_temp = document_temp.append(temp_word, 0, 1);
						count_word++;
					}
					cou.push_back(document_temp);
					document_temp.clear();
					continue;
				}
				else if (document_temp == "price")
				{

					document_temp.clear();
					float number = 0.0;
					int f_c = 0;
					int float_count = 1;
					float ff;
					while (a[count_word] != '<')
					{
						if (f_c == 0)
						{

							if (a[count_word] == '.')
								f_c++;

							else
								number = number * 10.0 - 48.0 + a[count_word];
							
						}
						else
						{
							ff = -48.0 + a[count_word];
								for (int oo = 0; oo < float_count; oo++)
								{
									ff = ff / 10.0;
								}
								number = number + ff;
								float_count++;
						}
						count_word++;
					}
					
					pri.push_back(number);
					price_t = number;
					continue;
				}
				else if (document_temp == "year")
				{

					document_temp.clear();
					float number = 0;
					int f_c = 0;
					int float_count = 1;
					int ff;
					while (a[count_word] != '<')
					{
						if (f_c == 0)
						{
							if (a[count_word] == '.')
								f_c++;
							else
							number = number * 10 - 48 + a[count_word];
							
						}
						else
						{
							ff = -48 + a[count_word];
								for (int oo = 0; oo < float_count; oo++)
								{
									ff=ff / 10.0;
								}
								number = number + ff;
								float_count++;
						}
						
						count_word++;

					}
					
					yea.push_back(number);

					

					year_t = number;
					if (link->wor == 'p')
					{
						if (link->com == 'g')
						{
							if (price_t <= link->price_num)
							{
								tit.pop_back();
								aut.pop_back();
								cou.pop_back();
								pri.pop_back();
								yea.pop_back();
							}
						}
						else if (link->com == 'l')
						{
							if (price_t >= link->price_num)
							{
								tit.pop_back();
								aut.pop_back();
								cou.pop_back();
								pri.pop_back();
								yea.pop_back();
							}
						}
					}
					else if (link->wor == 'y')
					{
						if (link->com == 'g')
						{
							if (year_t <= link->year_num)
							{
								tit.pop_back();
								aut.pop_back();
								cou.pop_back();
								pri.pop_back();
								yea.pop_back();
							}
						}
						else if (link->com == 'l')
						{
							if (year_t >= link->year_num)
							{
								tit.pop_back();
								aut.pop_back();
								cou.pop_back();
								pri.pop_back();
								yea.pop_back();
							}
						}
					}
					if (aut.size() > 0)
					{
						if (link->for_each == 'a')
						{
							if (aut[aut.size() - 1] != link->for_each_s)
							{
								tit.pop_back();
								aut.pop_back();
								cou.pop_back();
								pri.pop_back();
								yea.pop_back();
							}
						}
						else if (link->for_each == 'c')
						{
							if (cou[cou.size() - 1] != link->for_each_s)
							{
								tit.pop_back();
								aut.pop_back();
								cou.pop_back();
								pri.pop_back();
								yea.pop_back();
							}
						}
						else if (link->for_each == 't')
						{
							if (tit[aut.size() - 1] != link->for_each_s)
							{
								tit.pop_back();
								aut.pop_back();
								cou.pop_back();
								pri.pop_back();
								yea.pop_back();
							}
						}

					}
				



					continue;
				}
			}
		}
	}
	
	system("pause");
	return 0;
}