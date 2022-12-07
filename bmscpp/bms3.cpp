#include<iostream>
#include "battery.cpp"
using namespace std ;
float UV=0;    
float OV=0;
float UT=0;
float OT=0;
float UC=0;
float OC=0;
float  SOC{0};
float  SOH{0};
int commflag=0;


 const float uvmin=14;
 const float uvmax=16;
//const float defaultUndervoltage=14.5;

 const float ovmin=22;
const float ovmax=24;
//const float defautOvervoltage=22.5;

const float utmin=13;
const float utmax=15;
//const float defaultUndertemperature=13.5;

const float otmin=37;
const float otmax=40;
//const float defaultOvertemperature=37.5;

const float ucmin=20;
const float ucmax=23;
//const float defaultUndercurrent=20.5;

const float ocmin=34;
const float ocmax=36;
//const float defaultOvercurrent=34.5;


bool checkfunc(float input ,float min,float max){
    if(input>=min && input<=max)
    {
       // cout<<"true"<<endl;
        return 1;
    }
    else{
       // cout<<"false"<<endl;
        return 0;
    }
}

class BMS
{
    private:
     const float defaultUndervoltage=14.5;
     const float defaultOvervoltage=22.5;
     const float defaultUndertemperature=13.5;
     const float defaultOvertemperature=37.5;
     const float defaultUndercurrent=20.5;
     const float defaultOvercurrent=34.5;
     const float defaultstateOfCharge=0.0;
     const float defaultstateOfHealth=0.0;

     public:
     BMS()
     {
        UV=defaultUndervoltage;
        OV=defaultOvervoltage;

        UT=defaultUndertemperature;
        OT=defaultOvertemperature;

        UC=defaultUndercurrent;
        OC=defaultOvercurrent;

        SOC=defaultstateOfCharge;
        SOH=defaultstateOfHealth;

        
     }
     // uint8_t and cout dont work together, use int
     float readVoltage()
     {
          float V = Voltage(); 
          return V;

     };

     float readCurrent(void)
     {
        float C = Current();
        return C;
     };

     float readTemp(void)
     {
        float T = Temperature();
        return T;
     }

     int stateOfCharge()
     {
         // SOC=inputSOC;
         return SOC;
     }
     int stateOfHealth()
     {
        // SOH=inputSOH;
        return SOH;
     }
     
     bool setUndervoltage(float uv)
     {
        if(checkfunc(uv,uvmin,uvmax))
        {
            UV=uv;
          //  cout<<"true"<<endl;
            return 1;
        }
        else
        {
            UV=defaultUndervoltage;
           // cout<<"false"<<endl;
            return 0;
        }
     }
     float getUndervoltage(){
        return UV;
     }
     bool setOvervoltage(float ov)
     {
        if(checkfunc(ov,ovmin,ovmax))
        {
            OV=ov;
            //cout<<"true"<<endl;
            return 1;
        }
        else 
        {
            OV=defaultOvervoltage;
            //cout<<"false"<<endl;
            return 0;
        }
     }
     float getOvervoltage()
     {
        return OV;
     }
     bool setUndertemperature(float ut)
     {
        if (checkfunc(ut,utmin,utmax))
        {
            UT=ut;
           // cout<<"true"<<endl;
            return 1;
        }
        else 
        {
            UT=defaultUndertemperature;
           // cout<<"true"<<endl;
            return 0;
        }
     }
     float getUndertemperature()
     {
        return UT;
     }
     bool setOvertemperature(float ot)
     {
        if(checkfunc(ot,otmin,otmax))
        {
            OT=ot;
            //cout<<"true"<<endl;
            return 1;

        }
        else 
        {
            OT=defaultOvertemperature;
            //cout<<"false"<<endl;
            return 0;
        }
     }
     float getOvertemperature()
     {
        return OT;
     }
     
     bool setUndercurrent(float uc)
     {
        if(checkfunc(uc,ucmin,ucmax))
        {
            UC=uc;
            //cout<<"true"<<endl;
            return 1;
        }
        else{
            UC=defaultUndercurrent;
            //cout<<"false"<<endl;
            return 0;
        }
     }
     float getUndercurrent()
     {
        return UC;
     }
     
     bool setOvercurrent(float oc)
     {
        if (checkfunc(oc,ocmin,ocmax))
        {
            OC=oc;
            //cout<<"true"<<endl;
            return 1;
        }
        else{
            OC=defaultOvercurrent;
           // cout<<"false"<<endl;
            return 0;
        }
     }
     float getOvercurrent()
     {
        return OC;
     }
     uint8_t Initialiser()
     {
        return commflag;
     }
     
};
int main()
{
    BMS battery;
   
     cout<<battery.readVoltage()<<endl;
     cout<<battery.readCurrent()<<endl;
     cout<<battery.readTemp()<<endl;
     cout<<battery.setUndervoltage(15)<<endl;
     cout<<battery.getUndervoltage()<<endl;
     cout<<battery.setOvervoltage(230)<<endl;
     cout<<battery.getOvervoltage()<<endl;
     cout<<battery.setUndertemperature(15)<<endl;
     cout<<battery.getUndertemperature()<<endl;
     /*cout<<battery.setOvertemperature(38)<<endl;
     cout<<battery.setUndercurrent(22)<<endl;
     cout<<battery .setOvercurrent(35)<<endl; */
}
