#ifndef BILL_H
#define BILL_H

#include <iostream>
#include"item.h"
using namespace std;
class bill
{
     private:
		 item *header;
		 int n;
    public:
		bill *next;
        bill()
        {
			header = NULL;
			next = NULL;
		}
		bill(item *h, int no)
		{
			header = h;
			n = no;
			next = NULL;

		}
		item *getheader()
		{
			return header;
		}
		int getn()
		{
			return n;
		}
		void setn(int no)
		{
			n = no;
		}
        void additem(item x)
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
       item &searchbyid(int id )
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
		   return x ;
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
    // return pointer addres
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
		void display()
		{
			cout << " id " << "name " << "\t" << "price " << "\t" << "quantity available " << endl;
			item *currentitem = header;
			for (int i = 0; i < n; i++)
			{
				cout << i + 1 << " - " << currentitem->getname() << "\t" << currentitem->getprice() << "\t" << currentitem->getquantity() << endl;
				currentitem = currentitem->next;
			}
		}
void deleteitem(int k)
{
	
		if (k > n)
		{
			cout << "error" << endl;
		}
		item *currentitem = header;
		item *prev = header;
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
};

#endif // BILL_H