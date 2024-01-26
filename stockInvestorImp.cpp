/*
Description: Base class useful for setting investor's name and ID, 
as well as error checking the ID. 
Input: Set the investors data using setters or 
constructors from stockInvestors class.
Output: Error messages if investor ID is invalid.
*/

#include "stockInvestor.h"
#include <iostream> 

/*
 stockInvestor: Default constructor to initalize name and ID.
 parameters: None. 
 return value: None.
*/
stockInvestor::stockInvestor():firstName(""), lastName(""), ID(""){

} //Default constructor

/*
 stockInvestor: Paramtereized constructor to set name and ID. 
 parameters: first name string, last name string, ID string
 return value: None.
*/
stockInvestor::stockInvestor(string fName, string lName, string id): 
firstName(fName), lastName(lName), ID(id){

}

/*
 setStockInvestor: Mutator function to set firstName, lastName, 
 and id according to the parameters.
 parameters: first name string, last name string, ID string
 return value: None.
*/
void stockInvestor::setStockInvestor(string fName, string lName, string id){
    firstName=fName;
    lastName=lName; 
    ID=id;
}

/*
 checkInvestorID: Checks ID for character and length requirements, returns 
 true or false. 
 parameters: investor ID string
 return value: True or false. 
*/
bool stockInvestor::checkInvestorID(string investorIDTemp) const {
    if (investorIDTemp.length()<6){
        return false;
    }
    if(investorIDTemp[0]!='P'&&investorIDTemp[0]!='T'){
        return false; 
    }     
    string idTemp = investorIDTemp.substr(1);

    for(auto elm : idTemp){
        if(elm <48||elm>57){
            return false;
        }
    }

    return true;
}   
  
/*
 setinvestorID: Mutator function to set investor ID.
 parameters: ID string 
 return value: None.
*/
void stockInvestor::setInvestorID(string id){
    ID=id;
    if (!checkInvestorID(getID())){
        cout << "Error:- "<< id<< " is invalid investorID for "<< firstName<<endl;
    }
}
    
/*
 setName: Mutator function to set first and last name.
 parameters: first name string, last name string 
 return value: None.
*/
void stockInvestor::setName(string fName, string lName){
    firstName=fName;
    lastName=lName;
}

/*
 getID: Getter function to return ID.
 parameters: None
 return value: string
*/
string stockInvestor::getID() const {
    return ID;
}

/*
 getFirstName: Getter function to return first name. 
 parameters: None.
 return value: string 
*/
string stockInvestor::getFirstName() const{
    return firstName;
}

/*
 getLastName: Getter function to return last name.
 parameters: None.
 return value: stirng
*/
string stockInvestor::getLastName() const {
    return lastName; 
}

/*
 print: Prints first name, last name, and ID
 parameters: ostream output object
 return value: None.
*/
void stockInvestor::print(ostream &output) const {
 
 output<< "Investor ID: "<< ID<<endl<<
          "First Name: "<< firstName<< endl<< 
          "Last Name: "<< lastName<<endl; 
}
//Function to print the member variables 
    
