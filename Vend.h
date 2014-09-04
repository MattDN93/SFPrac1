/*
			Vending Machine Class Definition and Accessors
			
			Holds the different methods for the Vend class and its 
			private variables. Manipulation by the end user and 
			console I/O is managed in main.cpp
			
			Matthew de Neef, 212503024, Software Engineering II 2014

*/

#include <iostream>
#include <string.h>

using namespace std;

class Vend
{
	public:
		//Initialization of the get accessors for the vending machine parameters' private vars
		int getProdCost()
		{
			return productCost;
		}
				
		string getProdName()
		{
			return productName;
		}
		
		int getQty()
		{
			return qty;
		}
		
		//set accessor intializers to allow changing private vars (only item quantity allowed
		void setQty(int q)
		{
			qty = q;
		} 
		
		//Initialiser for first run, when new object of class is instantiated (default accessor)
		//Uses member initialisation list to allow class abstract base classes, pure virtual fns etc.
		Vend(string name="Generic Product",int cost=0, int quant=0) : 
		productName(name), 
		productCost(cost),
		qty(quant) {} ;
		
		//Destructor for the class
		//~Vend();
		
		//overloading of the "<<" operator to allow objects of Vend type to interact with iostream objects
		friend ostream &operator<<(ostream &output, Vend &Machine);
		
	private:
		string productName;
		int productCost;
		int qty;
			
};

//instructing how object "Machine" of type "Vend" is displayed with the "<<" operator
ostream &operator<<(ostream &output, Vend &Machine)
{
	output<<Machine.productName<<"\t\t"<<Machine.productCost<<"\t\t"<<Machine.qty<<endl;
	return output;
}

//Function allows user to buy items, throws a status to main for error handling
//receives an array of Vend type with all parameters needed
int buy(Vend product[], int itemID)
{
	if(itemID>0 && itemID<=8)								//if correct item...
	{
		if(product[itemID-1].getQty()>0)		//if there is inventory...
		{
			cout << "Inventory OK, item available!"<<endl; 
		}
	}
	else return -1;		//we have an error
}

//simply displays current inventory
int display(Vend product[])
{
	cout<<"Item Name\t\tPrice\t\tQty In Stock"<<endl;
	for(int i=0;i<8;i++)
	{
		cout<<i+1<<"."<<product[i];
	}
}

//Coin return shows current state of machine eg. how much has been purchased
int coinReturn;


