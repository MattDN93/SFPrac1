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
		int getProductCost()
		{
			return productCost;
		}
				
		string getProductName()
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
		
		//Initialiser for first run, when new object of class is instantiated
		
		
	private:
		string productName;
		int productCost;
		int qty;
			
};

main()
{
}

