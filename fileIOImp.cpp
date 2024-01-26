/*
Name: Rahel Siefe, NSHE: 5007247591, 1001, ASSIGNMENT: 3
Description: This class has only one member function. The member function
returns the number of entries read the data from (investorsData.txt) 
file; use constructors, setters, member functions to calculate the
portfolio of each investor. Finally, write the investors' portfolios 
(reports) to an outputfile (investorsPortfolio.txt). 
Input: Information from investorsData.txt file
Output: investors' Portfolios containing IDs, names, stock price 
changes, and more (investorsPortfolio.txt).
*/

#include "fileIO.h"

/*
 readWriteDataFile: Reads entries from investorsData.txt and calls 
 investorType paramterized constructor, print, setPortfolio, and calculateStockValue 
 functions respectively to construct investorPortfolio.txt profiles. 
 parameters: ifstream inFile object, ofstream outData object 
 return value: unsinged int number of entries
*/
unsigned int fileIO::readWriteDataFile(ifstream &inFile, ofstream &outData){
stocksPortfolio spObj; 
string id=" " ;
string fName=" "; 
string lName=" "; 
string tyName=" "; 
string skName=" "; 
double skCount= 0;
double skPrice=0;
double p1=0;
double p2=0;
double p3=0;
unsigned int cnt=0;
getline(inFile, id);

while (inFile>>id>> fName>>lName>> tyName>> skName>>skCount>> skPrice>>p1>> p2>> p3){
    cnt ++;
    
    investorType itObj(id, fName, lName, tyName, skName, static_cast<int>(skCount), skPrice,outData);
    itObj.print(outData);
    spObj.setPortfolio(p1,p2,p3,itObj);
    spObj.calculateStockValue(itObj, outData);
}
 string stars; 
stars.append(65, '*');
outData <<endl<<endl<< stars << endl;
outData<< "Total Entries: "<< cnt;
cout<< "Total Entries: "<< fixed << setprecision(2)<<cnt;
    return cnt;
}