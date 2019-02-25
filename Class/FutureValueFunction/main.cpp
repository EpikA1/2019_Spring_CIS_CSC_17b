/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 25th, 2019, 12:10 AM
 * Purpose:  Equivalent Functions
 */

//System Libraries
#include <iostream> //I/O Library -> cout,endl
#include <iomanip>  //Format Library
#include <cmath>    //Math Library
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants
//Math, Physics, Science, Conversions, 2-D Array Columns

//Function Prototypes
float fValue1(float,float,int);
float fValue2(float,float,int);
float fValue3(float,float,int);
float fValue4(float,float,int);
float fValue5(float,float,int=12);
void  fValue6(float &,float,int);
int  fValue7(float &,float,int);
float fValue4(float,float,short);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    float pv,intRate;
    int nCmp;

    //Initial Variables
    intRate=6;       //Interest Rate
    nCmp=72/intRate; //Number of Years
    pv=100;          //$100
    
    //Map/Process Inputs to Outputs
    intRate/=100;//From percentage to decimal
    cout<<fixed<<setprecision(2)<<showpoint;
    cout<<"Function Power     -> FV("<<pv<<","<<intRate<<","<<nCmp<<") = $"
            <<fValue1(pv,intRate,nCmp)<<endl;
    cout<<"Function Exp Log   -> FV("<<pv<<","<<intRate<<","<<nCmp<<") = $"
            <<fValue2(pv,intRate,nCmp)<<endl;
    cout<<"Function For Loop  -> FV("<<pv<<","<<intRate<<","<<nCmp<<") = $"
            <<fValue3(pv,intRate,nCmp)<<endl;
    cout<<"Function Recursion -> FV("<<pv<<","<<intRate<<","<<nCmp<<") = $"
            <<fValue4(pv,intRate,nCmp)<<endl;
    cout<<"Function Defaulted -> FV("<<pv<<","<<intRate<<","<<"12"<<") = $"
            <<fValue5(pv,intRate)<<endl;
    float fv=pv;
    fValue6(fv,intRate,nCmp);
    cout<<"Function Reference -> FV("<<pv<<","<<intRate<<","<<nCmp<<") = $"
            <<fv<<endl;
    cout<<"Function Overload  -> FV("<<pv<<","<<intRate<<","<<nCmp<<") = $"
            <<fValue4(pv,intRate,static_cast<short>(nCmp))<<endl;
    for(int i=1;i<=4;i++){
        fv=pv;
        fValue7(fv,intRate,nCmp);
    }
    cout<<"Function Static    -> FV("<<pv<<","<<intRate<<","<<nCmp<<") = $"
            <<fv<<endl;
    fv=pv;
    cout<<"The static function got called "<<fValue7(fv,intRate,nCmp)<<" times"<<endl;

    //Exit program!
    return 0;
}

int  fValue7(float &fvpv,float i,int n){
    static int count;
    for(int year=1;year<=n;year++){
        fvpv*=(1+i);
    }
    return ++count;
}

float fValue4(float pv,float i,short n){
    for(int year=1;year<=n;year++){
        pv*=(1+i);
    }
    return pv;
}

void fValue6(float &fvpv,float i,int n){
    for(int year=1;year<=n;year++){
        fvpv*=(1+i);
    }
}

float fValue5(float pv,float i,int n){
    for(int year=1;year<=n;year++){
        pv*=(1+i);
    }
    return pv;
}

float fValue4(float pv,float i,int n){
    if(n<=0)return pv;
    return fValue4(pv,i,n-1)*(1+i);
}

float fValue3(float pv,float i,int n){
    for(int year=1;year<=n;year++){
        pv*=(1+i);
    }
    return pv;
}

float fValue2(float pv,float i,int n){
    return pv*exp(n*log(1+i));
}

float fValue1(float pv,float i,int n){
    return pv*pow((1+i),n);
}