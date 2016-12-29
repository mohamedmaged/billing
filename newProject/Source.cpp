#include <iostream>
#include"bill.h"
#include"item.h"
#include "stock.h"
#include<string>
#include "bills.h"
using namespace std;
void main()
{

	/*stock mystock;
	mystock.read("test.csv");
	mystock.display();*/
	bills mybills;
	mybills.read("fsdf ");
	item s(1545, "pepsi", "pepsi", "drinks", 20, 2);
	item q(15, "chepsi", "chepsi", "potateos", 30, 2);
	item t(5452, "jelly", "dream", "deserts", 20, 30);
	bill b;
	b.additem(s);
	b.additem(q);
	bill c;
	b.additem(t);
	c.additem(t);
	c.additem(s);
	mybills.addbill(b);
	mybills.addbill(c);
	mybills.display();
	mybills.save("df sd");
	/*mystock.additem(s);
	mystock.additem(q);
	mystock.additem(t);
mystock.deleteitem(1);
	mystock.display();
	mystock.save("test.csv");*/
	
	system("pause");
}