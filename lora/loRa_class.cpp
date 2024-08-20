#include <stdint.h>
#include "loRa.h"
#include "loRa_class.h"


loRa_class::loRa_class(int 		frequency,
        uint8_t		spredingFactor,
        uint8_t		bandWidth,
        uint8_t		crcRate,
        uint16_t	preamble,
        uint8_t		power,
        uint8_t		overCurrentProtection
        ):
        frequency(frequency),
        spredingFactor(spredingFactor),
        bandWidth(bandWidth),
        crcRate(crcRate),
        preamble(preamble),
        power(power),
        overCurrentProtection(overCurrentProtection)
        {

            loRa_class_struct = {

            frequency,                
            spredingFactor,               
            bandWidth,                
            crcRate,                  
            preamble,                 
            power,                
            overCurrentProtection            

            };
        }

loRa_class* loRa_class::getInstance(){
    return loRaInstance;

}

void loRa_class::reset(){
    LoRa_reset(&loRa_class_struct);
}

void loRa_class::readReg(uint8_t* address, uint16_t r_length, uint8_t* output, uint16_t w_length){
    LoRa_readReg(&loRa_class_struct, address, r_length, output, w_length);
}

void writeReg(uint8_t* address, uint16_t r_length, uint8_t* values, uint16_t w_length){
    writeReg(&loRa_class_struct, address, r_length, values, w_length);
}

void gotoMode( int mode){
    gotoMode(&loRa_class_struct, int mode);
}



void loRa_class::set_frequency(int frequency){    
    loRa_class_struct.frequency = frequency;

}
void loRa_class::set_spredingFactor(uint8_t spredingFactor){
        loRa_class_struct.spredingFactor = spredingFactor;

}
void loRa_class::set_bandWidth(uint8_t bandWidth){
        loRa_class_struct.bandWidth = bandWidth;


}
void loRa_class::set_crcRate(uint8_t crcRate){
    loRa_class_struct.crcRate = crcRate;

}
void loRa_class::set_preamble(uint16_t preamble){
    loRa_class_struct.preamble = preamble;

}
void loRa_class::set_power(uint8_t power){
    loRa_class_struct.power = power;

}
void loRa_class::set_overCurrentProtection(uint8_t overCurrentProtection){
    loRa_class_struct.overCurrentProtection = overCurrentProtection;

}