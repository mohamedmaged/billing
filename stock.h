// once
#include "item.h"
#include <iostream>
#include<fstream>
#include <string>
#include<iomanip>
using namespace std;
class stock:public bill
{
private :

public :
	void customerdisplay()
	{
		cout << " index " << "name " << "\t" << "price " <<  endl;
		item *currentitem = bill::header;
		int i = 0;
		while(currentitem!=NULL)
		{
			cout << setw(5)<<i + 1 << " - " << currentitem->getname() << "\t" << currentitem->getprice() << endl;
			currentitem = currentitem->next;
			i++;
		}
	}
	
	bool save ()
	{
		ofstream file("stock.csv");
		if (file.is_open())
		{
			item *currentitem;
			currentitem = bill::header;

			while (currentitem != NULL)
			{
				file << currentitem->getid()<<","<< currentitem->getname()<<"," <<currentitem->getmanf()<<"," <<currentitem->gettype()<<","<< currentitem->getprice()<<","<< currentitem->getquantity()<<"\n";
				currentitem = currentitem->next;
			}

		}
		file.close();
		return true;
	}
	bool read()
	{
		ifstream inf("stock.csv");
		
		if (inf.is_open())
		{
			string x;
			while (1)
			{
				
				string  id1;
				string name;
				string manf;
				string type;
				string price1;
				string quantity1;
				getline(inf, x);
				if (x.length() < 3)
					break;
		//		cout << x << endl;
				int z = 0;
				for (int i = 0; i < x.length(); i++)
				{
					if (x[i] == ',')
					{
						z++;
						continue;
					}
					if (z == 5)
					{
						quantity1 = quantity1+x[i];
						
					}
					if (z == 4)
					{
						price1 =price1 + x[i];
						
					}
					if (z == 3)
					{
						type = type+x[i];
						
					}
					if (z == 2)
					{
						manf = manf+x[i];
						
					}
					if (z == 0)
					{
						id1 = id1+x[i];

						
					}
					if (z == 1)
					{
						name = name+x[i];
						
					}
					
				

				}
			
				 item s (stoi(id1), name, manf, type,stof(price1),stof(quantity1));
				additem(s);
			}

		}
		inf.close();
		return true;

	}
};