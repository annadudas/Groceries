#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Product
{
protected:
	string productName_;
	string label_;
	int price_;
	int rating_;
	int isle_;


public:
	string getProductName() { return productName_; }
	int getPrice() { return price_; }
	int getRating() { return rating_; }
	int getIsle() { return isle_;  }


	Product(string productName, string label, int price, int rating, int isle) : productName_(productName), label_(label), price_(price), rating_(rating), isle_(isle) {};
	virtual void print(std::ostream& os) = 0;
	~Product();
};

