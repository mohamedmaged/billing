#ifndef ITEM_H
#define ITEM_H
#include<iostream>
#include<string>
#include "date.h"
using namespace std;

class item
{
    private:
        int  id;
	string name;
	string manf;
	string type;
	float price;
	bool edible;
	int quantity;
	date exp;

    public:
		item *next;
item(){
id=-1;
quantity=0;
next =NULL;
}
item(int i,string n,string man,string t,float p,int q=0)
	{
		id=i;
		name = n;
		manf = man;
		type = t;
		price=p;
		edible = false;
     quantity=q;
	 next = NULL;
	}

	item(int i,string n,string man,string t,float p,date e,date pr,int q=0,bool ed= false)
	{
		id=i;
		name = n;
		manf = man;
		type = t;
		price=p;
		edible = ed;
     quantity=q;
     exp=e;
	 next = NULL;
	}
	void setid(int i)
	{
		id=i;
	}
	void setname (string n)
	{
		name = n;
	}
	void setmanf(string man)
	{
		manf = man;
	}
	void settype ( string t)
	{
		type = t;
	}
	void setprice ( float p)
	{
		price=p;
	}
	void setquantity(int q)
	{
		quantity=q;
	}
	int getquantity()
	{
		return quantity;
	}
	int getid()
	{
		return id;
	}
	string  getname()
	{
		return name;
	}
	string getmanf()
	{
	 return manf;
	}
	string gettype()
	{
		return type;
	}
	float getprice()
	{
		return price;
	}
	bool getedib()
	{
		return edible;
	}

	void changequantity (int q)
	{
	    if((quantity+q)>=0)
        {
            quantity=quantity+q;
        }
        else
        {
            cout<<" quantity  less than zero"<<endl;
        }
	}


};

#endif // ITEM_H