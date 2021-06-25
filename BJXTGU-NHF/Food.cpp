#include "Food.h"



Food::~Food()
{
}

void Food::print(std::ostream & os)
{
	os <<"Product name: "<< productName_ << "\n" <<"Label: "<<label_ << "\n" <<"Price: "<< price_ << "\n" <<"Quality rating: " 
		<< rating_ << "/10\n" <<"Isle: " << isle_ << "\n" <<"Energy: "<< energy_ << " kcal/100g\n" <<"Expires in: "<< expiration_<< " days.\n";
	//irasd ki h mi mi 

}
