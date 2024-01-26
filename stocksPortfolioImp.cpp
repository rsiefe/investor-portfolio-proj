/*
Name: Rahel Siefe, NSHE: 5007247591, 1001, ASSIGNMENT: 3
Description: stocksPortfolio is a base class with an object of other 
class(investorType) (Composition: has-a relationshipinvestorType).
stocksPortfolio is to set 3 different prices.
Input: Price changes and InvestorType object using constructors and functions 
called in the main function.
Output: The print function calculates price changes of the stock.
The investors' portfolios(reports) are printed on terminal or output
file according to the parameters.
*/

#include "stocksPortfolio.h"
#include <iostream> 
#include<cmath>

/*
 stocksPortfolio: Default constructor to initalize priceOne, priceTwo, 
 priceThree, and stockValue.
 parameters: None. 
 return value: None.
*/
stocksPortfolio::stocksPortfolio(): priceOne(0), priceTwo(0), priceThree(0), stockValue(0) {

}//Default constructor

/*
 stocksPortfolio: Parameterized constructor to intialize private member
 varaibles: priceOne, priceTwo, and priceThree and initialize private 
 member object of other class
 parameters: None. 
 return value: None.
*/
stocksPortfolio::stocksPortfolio(double pOne, double pTwo, double pThree, investorType invTemp):
priceOne(pOne), priceTwo(pTwo), priceThree(pThree), invTypeObj(invTemp){ 

}

/*
 setPortfolio: Mutator function to set member variables 
 priceThree, and stockValue, and to set the private member object
 of the other class.
 parameters: double price one, double price two, double price three, 
 member object. 
 return value: None.
*/
void stocksPortfolio::setPortfolio(double pOne, double pTwo, double pThree, investorType invTemp){
    priceOne=pOne; 
    priceTwo=pTwo; 
    priceThree=pThree; 
    invTypeObj=invTemp; 

}

/*
printPriceChanges: To print three price changes
 parameters: ostream output object 
 return value: None.
*/
void stocksPortfolio::printPriceChanges(ostream &output) const{
    output << "Price Changes: \t"<<priceOne<<"\t"<<priceTwo<< "\t"<<priceThree<<endl; 
    
}

/*
calculateStockValue: Multiply stockCount with each new price and print
 statements accordingly. Finally print stockValue and Show Loss/Profite
 according to the difference between intial stock price and final stock
 price change. Information is printed to terminal or file accoring to
 ostream object paramter.
 parameters: investorType object, ostream output object  
 return value: None.
*/
void stocksPortfolio::calculateStockValue(investorType invTemp, ostream &output){
   double ip=invTemp.getStockPrice()*invTemp.getStockCount();
   double p1=invTemp.getStockCount()* priceOne;
   double p2=invTemp.getStockCount()*priceTwo;
   double p3= invTemp.getStockCount()*priceThree;

if (invTemp.getStockPrice()<0 || invTemp.getStockCount()<0||
             !invTypeObj.checkInvestorID(invTemp.getID())){
     ip= 0;
     p1= 0;
     p2= 0;
     p3= 0;
}

output<< "Stock Value with investor Price: "<< ip<<endl
     << "Stock Value with a price One change: "<< p1<<endl
     << "Stock value with a price Two change: "<<  p2<<endl
     << "Stock Value with a price Three change: "<<  p3<<endl;
   
     if ((p3-ip)>=0){
         output << "Final Stock Value: "<< p3<<endl
                << "Profit on an Investment: "<< p3-ip<<endl;
               stockValue=p3;
     }else if ((p3-ip)<0){
         output << "Final Stock Value: "<<p3-ip<<endl
                << "Loss on an investment: "<< abs(p3-ip)<<endl;
               stockValue=p3-ip;
     }
     printPriceChanges(output);
     string stars; 
    stars.append(65, '*');
    output <<endl<< stars << endl;

}
/*Calculate stockValue- multiply stockPrice with stockCount 
                         (both from investor type)*/




/*
 writePriceChangesToFile: Write priceOne, priceTwo, and priceThree to 
 the investorsData.txt .
 parameters: ostream output object 
 return value: None.
*/
void stocksPortfolio::writePriceChangesToFile(ostream &output) const{
     output<< priceOne<< setw(10)<< priceTwo<< setw(8)<<priceThree<<endl; 

}

/*
 getInvestorPrice: Getter function to return investor price from investorType.
 parameters: None.
 return value: None.
*/
double stocksPortfolio::getInvestorPrice() const{
    return invTypeObj.getStockPrice()*invTypeObj.getStockCount();
} 

/*
 getPriceOne: Getter function to return priceOne. 
 parameters: None.
 return value: None.
*/
double stocksPortfolio::getPriceOne() const{
    return priceOne;
}

/*
 getPriceTwo: Getter function to return priceTwo.
 parameters: None.
 return value: None.
*/
double stocksPortfolio::getPriceTwo() const{
    return priceTwo;
}

/*
 getPriceThree: Getter function to return priceThree.
 parameters: None.
 return value: None.
*/
double stocksPortfolio::getPriceThree() const{
    return priceThree;
}

/*
 getStockValue: Getter function to return stockValue.
 parameters: None.
 return value: None.
*/
double stocksPortfolio::getStockValue() const{
    return stockValue;
}
