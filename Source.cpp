#include <iostream>
#include"bill.h"
#include"item.h"
#include "stock.h"
#include<string>
#include "bills.h"
#include <iomanip>      // std::setw
using namespace std;
void main()
{
	stock mystock;
	bills mybills;

	while(1)
	{
		int k;

		cout <<setw(60)<<"**welcome to mechantus billing APP**"<<endl<<endl;
		cout << "RUlES ARE SIMPLE : " << endl<<endl;
		cout<<"1- "<<"all screens are numbered so you can choose your item by typing the number "<<endl<<endl;
		cout <<"2- "<<"You can always press 0 to go to the previous menu "<<endl<<endl;
		cout << "please choose one tap of these:" << endl << endl;
		cout <<setw(4)<<"1- "<<"customers " << endl;
		cout << setw(4) << "2- "  << "stock" << endl;
		cout << setw(4) << "3- " << "sales" << endl;
		cin >> k;
		if (k == 1)
		{
			bill c;
			int x,y;
			cout << setw(60) << "CUSTOMERS - TAB (WELCOME)" <<endl<<endl;
			cout << setw(40) << "please enter the number of the item you want" << endl<<endl;
			mystock.read();
			while (1) {
				mystock.check();
				mystock.customerdisplay();
				cin >> x;
				cout << "Please enter the qunatity of the item" << endl;
				cin >> y;
				while (mystock.getitem(x - 1).getquantity()< y|| y<0)
				{
					if (mystock.getitem(x - 1).getquantity() == y)
						break;
					cout << "WE ARE SORRY we don't have that quantity" << endl;
					cout << "the quantity of this item in the stock is :" << mystock.getitem(x - 1).getquantity() << endl;
					cout << "please enter again the quantity of your item or choose another item by hitting 0" << endl;
					cin >> y;
				}
				if (y == 0)
					continue;

				mystock.getitem(x - 1).changequantity(-1 * y);
				item n = mystock.getitem(x - 1);
				n.setquantity(y);
				c.additem(n);
				cout << "if you want to exit and pay for your bill press 0" << endl;
				cin >> y;
				if (y == 0)
				{
					c.display();
					while (1)
					{
						cout << "please choose what do you want to do ?" << endl << endl;
						cout << "1- " << "PAY" << endl;
						cout << "2- " << "EDIT" << endl;
						cout << "3- " << "delete item " << endl;
						cout << "4- " << "cancel all bill" << endl;
						cin >> y;
						if (y == 1)
						{
							mystock.save();
							mybills.addbill(c);
							break;
						}
						if (y == 2)
						{
							cout << "please enter the number of the item you want to edit" << endl;
							c.display();
							cin >> y;
							cout << "please enter the new quantity" << endl;
							cin >> x;
							while (mystock.getitem(y - 1).getquantity()< x||y<0)
							{
								if (mystock.getitem(x - 1).getquantity() == y)
									break;
								cout << "WE ARE SORRY we don't have that quantity" << endl;
								cout << "the quantity of this item in the stock is :" << mystock.getitem(y - 1).getquantity() << endl;
								cout << "please enter again the quantity of your item or choose another item by hitting 0" << endl;
								cin >> y;
							}
							if (y == 0)
								continue;
							mystock.getitem(y - 1).changequantity(c.getitem(y - 1).getquantity());
							mystock.getitem(y - 1).changequantity(-1 * x);
							c.getitem(y - 1).setquantity(x);
							c.display();
						}
						if (y == 3)
						{
							cout << "please enter the number of the item you want to delete" << endl;
							c.display();
							cin >> y;
							mystock.additem(c.getitem(y - 1));
							c.deleteitem(y - 1);
						}
						if (y == 4)
						{
							break;
						}
					}
					break;
				}
			}

		} // bug after edit 
		if (k == 2)
		{

		}
		if (k == 3)
		{

		}
	}
	/*stock mystock;
	mystock.read("test.csv");
	mystock.display();
	bills mybills;
	//mybills.read("fsdf ");
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
	mybills.save();
	/*mystock.additem(s);
	mystock.additem(q);
	mystock.additem(t);
mystock.deleteitem(1);
	mystock.display();
	mystock.save("test.csv");*/
	
	system("pause");
}