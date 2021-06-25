#include "Household.h"




Household::~Household()
{
}

void Household::print(std::ostream & os)
{
	os <<"Product Name: "<< productName_ << "\n" <<"Label: "<< label_ << "\n" <<"Price: "<< price_ << "\n" <<"Quality rating: "
		<< rating_ << "\n" <<"Isle: "<<isle_ << "\n" <<"Color: "<< color_ << "\n";

}
