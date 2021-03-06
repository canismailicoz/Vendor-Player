// COMPE226 first homework.cpp : Defines the entry point for the console application.
//
#pragma comment(lib,"LinkList.lib")
#include<iostream>
#include "stdafx.h"
#include"LinkList.h"
#include<string>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>


using namespace std;
class Material
{
	public:
		string MaterialName;
		int MaterialCount, MaterialPrice;
	
		Material() {}
		Material(string n, int mc, int mp)
		{
			MaterialName = n;
			MaterialCount = mc;
			MaterialPrice = mp;
		}
		
		friend ostream& operator <<(ostream &out, Material &material1)
		{
			out << material1.MaterialName << ",  Count: " << material1.MaterialCount << ",  Unit Price:  " << material1.MaterialPrice << endl;
			return out;
		}
		friend istream& operator >>(istream &is, Material & material2)
		{
			is>> material2.MaterialName;
			is >> material2.MaterialCount;
			is>> material2.MaterialPrice;
			return is;
		}
		friend bool operator ==(Material &material2, Material &material3)
		{
			return (material2.MaterialName == material3.MaterialName);
		}
		friend Material operator +(Material &material4, Material &material5)
		{
			//Material xc(material4.MaterialName, material4.MaterialCount + material5.MaterialCount,material4.MaterialPrice);
			material4.MaterialCount = material4.MaterialCount + material5.MaterialCount;
			
			return material4;
		}
	/*node<Material> operator=(Material &material6)
		{
			Node<Material> result;
			result.MaterialCount= MaterialCount + material6.MaterialCount;
		    
			return result;
		*/
		
	};
int main()
{
	char choose;
	int nl, bl, cl,kl,ol,ql,wl;
	LinkList<Material> Vendor;
	LinkList<Material> Player;
	string item[5] = { "Wood", "Diamond", "Stone", "Gold", "Iron" };
	int price[2] = { 1000,5000 };
	srand(time(NULL));
	
	nl = rand() % 4+1;
	
	for (int i = 0; i < nl; i++)
	{

		
		kl = rand() % 2;
		
		bl = rand() % 25 + 1;
		Material a(item[i], bl, price[kl]);
		Vendor.insertFirst(a);
	}
	
	ol = rand() % 4 + 1;
	for (int i = 0; i < ol; i++)
	{
		
		ql = rand() % 2;
		
		wl = rand() % 25 + 1;
		Material b(item[i], wl, price[ql]);
		Player.insertFirst(b);
	}
	cout << "Vendor has: " << endl;
	cout << Vendor;
	cout << endl << endl << endl;
	cout << "You have:" << endl;
	cout << Player;
	
		do {
			cout << "Move to another town with t/T, buy stuff from this town's vendor with b/B, sell stuff to this vendor with s/S..q/Q to Quit:";
			cin >> choose;
		} while (choose != 'T' && choose != 'B' && choose != 'S' && choose != 'Q'&& choose != 't' && choose != 'b' && choose != 's' && choose != 'q');
	
	do
	{
		
		
		
		if (choose == 't' || choose == 'T')
		{
			Vendor.destroyList();
			nl = rand() % 4 + 1;

			for (int i = 0; i < nl; i++)
			{


				kl = rand() % 2;

				bl = rand() % 25 + 1;
				Material a(item[i], bl, price[kl]);
				Vendor.insertFirst(a);
			}
			cout << "Vendor has: " << endl;
			cout << Vendor;
			cout << endl << endl << endl;
			cout << "You have:" << endl;
			cout << Player;
			

		}
		if (choose == 's' || choose == 'S')
		{
			string c1;
			Material b,x,y,c2;
			node<Material> *p,*q;
			char y1;
			do {
				cout << "Which item do you want to sell?:";
				cin >> c1;
				if (c1 != "Diamond"&&c1 != "Wood"&&c1 != "Stone"&&c1 != "Gold"&&c1 != "Iron")
					cout << "you enter wrong item." << endl;
				c2.MaterialName = c1;
				if (!Player.search(c2))
				{
					cout << "You don't have item" << endl;
					goto last;
				}
			} while (c1 != "Diamond"&&c1 != "Wood"&&c1 != "Stone"&&c1 != "Gold"&&c1 != "Iron");
			
			cout << "Do you want to sell " << c1 <<"?:"<< endl;
				cin >> y1;
	
				if (y1 == 'y' || y1 == 'Y')
				{
					
					b.MaterialName = c1;
					if (Vendor.search(b) != NULL)
					{
						cout << "You sold " << c1 << " to the vendor." << endl;
						p = Vendor.search(b);
						q = Player.search(b);
						x = p->info;
						y = q->info;
						p->info= x + y;
						Player.deleteNode(b);
						cout << "Vendor has: " << endl;
						cout << Vendor;
						cout << endl << endl << endl;
						cout << "You have:" << endl;
						cout << Player;
					}
					else
					{
						q = Player.search(b);
						//cout << "2You don't have item" << endl;
						Vendor.insertFirst(q->info);
						Player.deleteNode(b);
						cout << "Vendor has: " << endl;
						cout << Vendor;
						cout << endl << endl << endl;
						cout << "You have:" << endl;
						cout << Player;
						/*cout << "You don't have item" << endl;
						Vendor.insertFirst(q->info);*/
					}
				}
				else
				{
					goto last;
				}
		}
		if (choose == 'b' || choose == 'B')
		{
			string c12;
			char h;
			Material b2, x2, y2,b12;
			node<Material> *p2, *q2;
			do {
				cout << "Which item do you want to buy?: ";
				cin >> c12;
				if (c12 != "Diamond"&&c12 != "Wood"&&c12 != "Stone"&&c12 != "Gold"&&c12 != "Iron")
				{
					cout << "you enter wrong item." << endl;
					goto last;

				}
				b2.MaterialName = c12;
				if (!Vendor.search(b2))
				{
					cout << "You don't have item" << endl;
					goto last;
				}
			} while (c12 != "Diamond"&&c12 != "Wood"&&c12 != "Stone"&&c12 != "Gold"&&c12 != "Iron");
			b2.MaterialName = c12;
			cout << "Do you want to buy " << c12 << "?" << endl;
			cin >> h;
			if (h == 'y' || h == 'Y')
			{
				
				
					b12.MaterialName = c12;
					if (Player.search(b12) != NULL)
					{
						cout << "You bought " << c12 << " from the vendor." << endl;
						p2 = Player.search(b12);
						q2 = Vendor.search(b12);
						x2 = p2->info;
						y2 = q2->info;
						p2->info = x2 + y2;
						Vendor.deleteNode(b12);
						cout << "Vendor has: " << endl;
						cout << Vendor;
						cout << endl << endl << endl;
						cout << "You have:" << endl;
						cout << Player;

					}
					else
					{
						q2 = Vendor.search(b12);
						//cout << "2You don't have item" << endl;
						Player.insertFirst(q2->info);
						Vendor.deleteNode(b12);
						cout << "Vendor has: " << endl;
						cout << Vendor;
						cout << endl << endl << endl;
						cout << "You have:" << endl;
						cout << Player;

					}
				
				/*else if(Player.search(b12))
				{

				}*/
				
			}
			else
			{
				goto last;
			}

		}
		last:
		
		do {
			cout << "Move to another town with t/T, buy stuff from this town's vendor with b/B, sell stuff to this vendor with s/S..q/Q to Quit:";
			cin >> choose;
		} while (choose != 'T' && choose != 'B' && choose != 'S' && choose != 'Q'&& choose != 't' && choose != 'b' && choose != 's' && choose != 'q');
	}while (choose != 'q' && choose != 'Q');
	
    return 0;
}