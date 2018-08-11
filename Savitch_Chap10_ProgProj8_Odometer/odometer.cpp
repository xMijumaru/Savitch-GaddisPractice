#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "odometer.h"

using namespace std;

odom::odom(){
    GalCsm=0.0; //the Gallons that were consumed
    MilPGal=0.0;//the miles per gallon
    Driven=0.0; //the amount that was driven
}
odom::odom(float x, float y, float z){
    GalCsm=x;
    MilPGal=y;
    Driven=z;
 
}
void odom::CoutMilage()const{
    //declare the variables here
    float GasAdd=1/MilPGal/10;//divides gas by how much will be used every
    //.1 miles
    float GasUsed=0.0;//adds the total gas used
    float limit=0.1;//limit to the odometer
    float time=0.0;//the odometer itself
    //runs the limits for the variables
        cout << fixed << showpoint << setprecision (1);
        cout << "Odometer will start in about 5 seconds " << endl;
        cout << setw(1) << "Miles Driven " << setw(30) << "Gasoline Used(Gallons)" 
             << endl;
        
        pause(5);
        cout << fixed << showpoint << setprecision(1);
            while (limit<Driven){
                //runs the odometer
                time+=.1;// adds milage to the odometer
                GasUsed+=GasAdd;//adds the gasoline used for the distance traveled
                limit+=.1;//calculates the limit for miles
                 cout << setw(1) << time << 
                        setw(30) << GasUsed << endl;
            }
        
            cout << "----------------------Results-----------------------"
                    "---------" << endl;
            cout << setw(1) << "Miles Driven: " << time << endl;
            cout << setw(1) << "Gallons Consumed: " << GasUsed << endl;
    }

void pause(int x){
    
        int standby = time(NULL) + x;
        
        while (standby>time(NULL));
}