/*
Name: Rahel Siefe, NSHE: 5007247591, 1001, ASSIGNMENT: 3
Description: This derived class of stockInvestor uses getter functions
to access variables of stockInvestor and prints the name, ID, stock 
information to the output file InvestorData.txt .
Input: Set investor type name, stock name, stock count, and stock price.
Output: stockInvestor member variables, investor type name, stock name, 
stock count, and stock price printed to output file. Error messages for
invalid stock price, stock count, ID. 
*/

#include "investorType.h"
#include <iomanip>
#include <iostream>

/*
 invesotrType: Default constructor to intialize member variables.
 parameters: None.
 return value: None.
*/
investorType::investorType()
{
typeName= " ";
stockName=" "; 
stockCount=0;
stockPrice=0;

} //Default constructor

/*
 investorType: Paramtereized constructor to set member variables
 of stockInvestor base class and InvestorType class.
 parameters: string ID, fName, lName, tyName, stName; int stCount, 
 double stPrice, ostream output object
 return value: None.
*/
investorType::investorType(string id, string fName, string lName,
string tyName, string stName, int stCount, double stPrice, 
ostream &output) : stockInvestor(fName, lName, id)
{ 
    typeName= tyName;
    stockName=stName; 
    stockCount=stCount;
    stockPrice=stPrice; 
    setInvestorID(id);
   if (!checkInvestorID(id)){
        output<< "Invalid ID; No calculations for " <<fName<<"; ID "
        <<id<<endl;
   }else if (getStockCount()<0){
        output<< fName<< "'s stock count is invalid"<<endl; 
   }else if(stockPrice<0){
        output<< fName<< "'s stock price is invalid"<<endl; 
   }

}

/*
 setInvestorInfo: Mutator function to set member variables of 
 investorType and stockInvestor. 
 parameters: string ID, fName, lName, tyName, stName; int stCount, 
 double stPrice
 return value: None.
*/
void investorType::setInvestorInfo(string id, string fName, string lName,
string tyName, string stName, int stCount, double stPrice){
    setName(fName, lName);
    setInvestorID(id);
    typeName= tyName;
    stockName=stName; 
    stockCount=stCount;
    stockPrice=stPrice; 
}

/*
 setType: Setter function to set typeName.
 parameters:string tyName
 return value: None.
*/
void investorType::setType(string tyName){
    typeName= tyName; 
}

/*
 setStockName: Setter function to set stockName.
 parameters:string stName
 return value: None.
*/
void investorType::setStockName(string stName){
    stockName=stName; 
}

/*
 setStockCount: Setter function to set stockCount.
 parameters:string stName
 return value: None.
*/
void investorType::setStockCount(int stCount) {
    stockCount=stCount;
}

/*
 setStockPrice: Setter function to set stockPrice.
 parameters: string stPrice
 return value: None.
*/
void investorType::setStockPrice(double stPrice){
    stockPrice=stPrice;
}

/*
 getID: Getter function overriding to return stockInvestor ID.
 parameters: None.
 return value: string 
*/
string investorType::getID() const {
    return stockInvestor::getID();
} //Function overriding

/*
 getFirstName: Getter function overriding to return stockInvestor first name.
 parameters: None.
 return value: string 
*/
string investorType::getFirstName() const{
    return stockInvestor::getFirstName();
}

/*
 getLastName: Getter function overriding to return stockInvestor last name.
 parameters: None.
 return value: string 
*/
string investorType::getLastName() const{
    return stockInvestor::getLastName();
}

/*
 getType: Getter function to return typeName.
 parameters: None.
 return value: string 
*/
string investorType::getType() const{
    return typeName;
}

/*
 getStockName: Getter function to return stockName.
 parameters: None.
 return value: string 
*/
string investorType::getStockName() const{
    return stockName; 
}

/*
 getStockPrice: Getter function to return stockPrice.
 parameters: None.
 return value: string 
*/
double investorType::getStockPrice() const{
    return stockPrice;
}

/*
 getStockCount: Getter function to return stockCount.
 parameters: None.
 return value: string 
*/
double investorType::getStockCount() const {
    return stockCount;
}

/*
 print: Function displays stockInvestor, investorType member variables,
 and borders.
 parameters: ostream outFile object
 return value: None.
*/
void investorType::print(ostream &outFile) const {
string stars; 
stars.append(65, '*');
outFile <<endl<< stars << endl;

outFile << "Investor Type:\n"<< 
"Type Name: "<< typeName<< endl << 
"Investor ID: "<< getID()<<endl<<
"First Name: "<< getFirstName()<<endl<< 
"Last Name: "<< getLastName()<< endl << endl<<

"Stock Name: "<< stockName << endl<<
"Stock Count: " << fixed << showpoint << setprecision(2)<<static_cast<double>(getStockCount())<<endl<< 
"Stock Price: "<< stockPrice; 
string dashes; 
dashes.append(50, '_');
outFile <<endl<< dashes << endl<<endl;
}

/*
 writeDataToFile: Getter function to return stockName.
 parameters: None.
 return value: string 
*/
void investorType::writeDataToFile(ofstream &outFile, investorType &tempObj){
 outFile <<setw(10) << tempObj.getID() <<setw(10)<< tempObj.getFirstName()<< setw(10)
 << tempObj.getLastName()<< setw(10)<< typeName<<setw(10)<< stockName<<setw(12)<<
 fixed<<setprecision(2)<< static_cast<double>(stockCount)<<setw(12)<<stockPrice<<setw(10);

}

