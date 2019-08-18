#ifndef POWER_H
#define POWER_H
#include "UnitAbstract.h"
// all calculation of water levels will be done on sensor unit
// first portion of structure are data from unit, second is configuration (seperated by space)
class Power : public UnitAbstract{
  public:
    
    struct Data{
      bool connectionToPowerOutlet;
      double batteryState;
      double currentDrawn;
     
      
    };
    
    static Data data;
    Power(){
      
    }
    void updateDataOnOlimex(Olimex olimex){
      
    }
    void fetchNewConfigFromOlimex(){
      
    }
    // clone whole structure, must ensure that new config is sent to sensor before it sends its data to prevent missmatch across what is shown at nextion and what has sensor unit
    // check how flow works
    void updateYourData(uint8_t newData);
    uint8_t getDataToBeSend(){
      uint8_t bs[sizeof(data)]; 
      memcpy(bs, &data, sizeof(data));
      return *bs;
    }

    // geters for variables in scructure for testing purpouse 
    double getLitersRemaining(){
      return litersRemaining;
    }
    boolean getConnectionToWaterSource(){
      return connectionToWaterSource;  
    }
    double getTemperature(){
      return temperature;
    }
};
#endif POWER_H
