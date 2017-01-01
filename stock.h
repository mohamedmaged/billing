// once
#include "item.h"
#include <iostream>
#include<fstream>
#include <string>
#include<iomanip>
using namespace std;
class stock
{
private :
	item *header;
	int n;
public :
	stock()
	{
		header = NULL;
	}
	void additem(item x)
	{
		if (searchbyname(x.getname()).getquantity() > 0)
		{
			searchbyname(x.getname()).changequantity(x.getquantity());
		}
		else
		{
			if (header == NULL)
			{
				header = new item(x.getid(), x.getname(), x.getmanf(), x.gettype(), x.getprice(), x.getquantity());
				n++;
			}
			else
			{
				item *currentitem = header;
				while (currentitem->next != NULL)
					currentitem = currentitem->next;
				currentitem->next = new item(x.getid(), x.getname(), x.getmanf(), x.gettype(), x.getprice(), x.getquantity());
				n++;
			}
		}
	}
	int getn()
	{
		return n;
	}
	void display()
	{
		cout << " id "<<"name " << "\t" << "price " << "\t" << "quantity available " << endl;
		item *currentitem = header;
		for (int i = 0; i < n; i++)
		{
			cout << i+1 << " - " << currentitem->getname() << "\t" << currentitem->getprice() << "\t" << currentitem->getquantity() << endl;
			currentitem = currentitem->next;
		}
	}
	void customerdisplay()
	{
		cout << " index " << "name " << "\t" << "price " <<  endl;
		item *currentitem = header;
		for (int i = 0; i < n; i++)
		{
			cout << setw(5)<<i + 1 << " - " << currentitem->getname() << "\t" << currentitem->getprice() << endl;
			currentitem = currentitem->next;
		}
	}
	bool save ()
	{
		ofstream file("stock.csv");
		if (file.is_open())
		{
			item *currentitem;
			currentitem = header;

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
				if (x.length() < 6)
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
					/*if (z == 6)
					{
						break;
					}*/
				

				}
			
				 item s (stoi(id1), name, manf, type,stof(price1),stof(quantity1));
				additem(s);
			}
		}
		inf.close();
		return true;

	}
	void deleteitem(int k)
	{
		if (k > n)
		{
			cout << "error" << endl;
		}
		item *currentitem = header;
		item *prev =header;
		if (k == 0)
		{
			header = currentitem->next;
			n--;
		}
		if (k == 1)
		{
			currentitem->next = currentitem->next->next;
			n--;
		}
		else {
			for (int i = 0; i < n; i++)
			{
				if (i == k - 2)
				{

					currentitem->next = currentitem->next->next;
					n--;
					break;
				}
				else
					currentitem = currentitem->next;
			}
		}

	}
	item &searchbyid(int id)
	{
		item x;
		item *currentitem = header;
		for (int i = 0; i < n; i++)
		{
			if (currentitem->getid() == id)
				return *currentitem;
			else
				currentitem = currentitem->next;
		}
		return x;
	}
	item &searchbyname(string q)
	{
		item x;
		item *currentitem = header;
		for (int i = 0; i < n; i++)
		{
			if (currentitem->getname() == q)
				return *currentitem;
			else
				currentitem = currentitem->next;
		}
		return x;

	}
	item &getitem(int k)
	{
		item x;
		item *currentitem = header;
		for (int i = 0; i < n; i++)
		{
			if (i == k)
				return *currentitem;
			else
				currentitem = currentitem->next;
		}
		return x;
	}
	void check()
	{
		item *currentitem = header;
		for (int i = 0; i < n; i++)
		{
			if (currentitem->getquantity() == 0)
			{
			      deleteitem(i);
			}
				currentitem = currentitem->next;
		}
	}
};