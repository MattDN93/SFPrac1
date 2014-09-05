/*
			Vending Machine Main Program
			
			Runs the I/O with the user, calls validation in the .h file.
			NOTE: PLEASE ENSURE "Vend.h" is included in the directory.
			
			Matthew de Neef, 212503024, Software Engineering II 2014

*/
#include <iostream>
#include <string>
#include "Vend.h"			//vending Class Definitions

using namespace std;

int main ()
{
	//Initialising an object of class Vend type
	Vend items[8];

	items[0]=Vend("Fritos.Chips",60,3);
	items[1]=Vend("Pretzels",60,10);
	items[2]=Vend("Popcorn",60,5);
	items[3]=Vend("Cheese.Crkrs",40,2);
	items[4]=Vend("Creme.Cookies",65,1);
	items[5]=Vend("Mint.Gums",25,5);
	items[6]=Vend("Chocolate",85,9);
	items[7]=Vend("Fruit.Chews",55,7);
 
	int choice;
	while(choice !=4){
	
	cout << "\n\n---------------------------------"<<endl;
	cout << "Hi-Tech Vending Machine"<<endl;
	cout << "---------------------------------"<<endl;
	cout << "Welcome. Please Choose an option"<<endl;
	cout << "\n1. Make a purchase"<<endl;
	cout << "\n2. Coin Return (view purchases)"<<endl;
	cout << "\n3. View Inventory (no purchase)" <<endl;
	cout << "\n4. Quit"<<endl;
	cout << "\nMake a selection: "<<endl;
	cin >>choice;
	
	switch (choice)
	{
		case 1:	
		display(items,0,0);					//gives user item list
		cout << "---------------------------------"<<endl;
		cout << "Choose an item to purchase: "<<endl;
		int purchchoice;
		cin >> purchchoice;
		
		int stockquery;
		stockquery = buy(items,choice);	//queries available stock (informs user if not)
		
		if(stockquery == -1)			//if no stock
		{
			cout << "---------------------------------"<<endl;
			cout << "No stock of this item, sorry! Make another selection."<<endl;
			cout << "---------------------------------"<<endl;
		}
		
		if(stockquery == -2)			//if user enters invalid number
		{
			cout << "---------------------------------"<<endl;
			cout << "That item is invalid! Make another selection."<<endl;
			cout << "---------------------------------"<<endl;
		}
		
		
		if(stockquery == 0)				//if OK--do transaction
		{
			cout << "---------------------------------"<<endl;
			cout << "Confirm order:"<<endl;
			display(items,1,purchchoice);
			cout << "---------------------------------"<<endl;
			cout << "How much are you paying?: "<<endl;
			int topay;
			cin >> topay;
			
			int payresult;				//check status of transaction
			payresult = purchasing(items,purchchoice,topay);
			if (payresult == 0)
			{
				cout << "Thank you! Vending "<< items[purchchoice-1].getProdName()<<" now."<<endl;
				int change;
				change = topay - items[purchchoice-1].getProdCost();
				cout << "Change of " << change << " cents to be collected. Have a nice day!"<<endl;
								
				//update the total purchased items & reduce stock.
				items[purchchoice-1].setQty(items[purchchoice-1].getQty()-1);
				coinReturn(items,purchchoice-1);
				
				break;
			}
			if (payresult == -1)
			{
				cout << "Not enough money entered, needed " << items[purchchoice-1].getProdCost() - topay << " cents more" <<endl;
				
			}
		}
		break;
		
		case 2:
			int profit; 
			profit = coinReturn(items,99); //signifies a completed total
			cout << "\n\n---------------------------------"<<endl;
			cout << "Current total for purchases: "<<profit <<" cents."<<endl;
			cout << "---------------------------------"<<endl;break;
		case 3:
		display(items,0,0); break;
		case 4:
		cout << "Thak you. Have a nice day!"<<endl;	
	}
}

}

Vend makepurchase()
{
	
}
