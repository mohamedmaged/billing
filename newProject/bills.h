#pragma once
#include  <iostream>
#include "bill.h"
#include<string>
#include <fstream>
using namespace std;
class bills
{
	bill *header;
	int n;
public:
	bills()
	{
		header = NULL;
	}
	void addbill(bill x)
	{
		if (header == NULL)
		{
			header = new bill(x.getheader(),x.getn());
			n++;
		}
		else
		{
			bill *currentbill = header;
			while (currentbill->next != NULL)
				currentbill = currentbill->next;
			currentbill->next = new bill(x.getheader(), x.getn());
			n++;
		}
	}
	void display()
	{
		bill *currentbill = header;
		while (currentbill != NULL)
		{
			cout << "\t" << "\t" << "New bill" << endl;
			currentbill->display();
			cout << " id " << "name " << "\t" << "price " << "\t" << "quantity available " << endl;
			
			for (int i = 0; i < currentbill->getn(); i++)
			{

				cout << i + 1 << " - " << currentbill->getitem(i).getname()<< "\t" << currentbill->getitem(i).getprice() << "\t" << currentbill->getitem(i).getquantity() << endl;
				
			}
			currentbill = currentbill->next;
		}

	}
	bool save(string f)
	{
		ofstream file("bills.csv");
		if (file.is_open())
		{
			bill *currentbill;
			currentbill = header;

			while (currentbill != NULL)
			{
				
				for (int i = 0; i < currentbill->getn(); i++)
				{
					file << currentbill->getitem(i).getid() << "," << currentbill->getitem(i).getname() << "," << currentbill->getitem(i).getmanf() << "," << currentbill->getitem(i).gettype() << "," << currentbill->getitem(i).getprice() << "," << currentbill->getitem(i).getquantity() << "\n";
				}
				file << "#" << "\n";
				currentbill = currentbill->next;
			}
		}
		file.close();
		return true;
	}
	bool read(string f)
	{
		ifstream inf("bills.csv");

		if (inf.is_open())
		{
			string x;
			while (1)
			{
				bill *currentbill=new bill();
				bills currentbills;
				bool newbill=false;
				string  id1;
				string name;
				string manf;
				string type;
				string price1;
				string quantity1;
				getline(inf, x);
				if (x.length() == 0)
					break;
				if (x.length() == 1)
					newbill = true;
				cout << x << endl;
				int z = 0;
				for (int i = 0; i < x.length(); i++)
				{
					if (x[i] == '#')
						break;
					if (x[i] == ',')
					{
						z++;
						continue;
					}
					if (z == 5)
					{
						quantity1 = quantity1 + x[i];

					}
					if (z == 4)
					{
						price1 = price1 + x[i];

					}
					if (z == 3)
					{
						type = type + x[i];

					}
					if (z == 2)
					{
						manf = manf + x[i];

					}
					if (z == 0)
					{
						id1 = id1 + x[i];

					}
					if (z == 1)
					{
						name = name + x[i];

					}
				}

				if (newbill == false)
				{
					item s(stoi(id1), name, manf, type, stof(price1), stof(quantity1));
					currentbill->additem(s);
				}
				else
				{
					addbill(*currentbill);
					currentbill = new bill();
					newbill = false;
					n++;
				}

			}
		}
		inf.close();
		return true;

	}

};
