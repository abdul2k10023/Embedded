#include <stdint.h>
#include "loRa.h"

class loRa_class{
    public:

    int 		frequency;
    uint8_t		spredingFactor;
    uint8_t		bandWidth;
    uint8_t		crcRate;
    uint16_t	preamble;
    uint8_t		power;
    uint8_t		overCurrentProtection;


    loRa_class(int 		frequency =433,
                uint8_t		spredingFactor =SF_7,      
                uint8_t		bandWidth =BW_125KHz,
                uint8_t		crcRate =CR_4_5,
                uint16_t	preamble =POWER_20db,
                uint8_t		power =100,
                uint8_t		overCurrentProtection = 8);

    LoRa_setting loRa_class_struct;
    
    loRa_class* getInstance();

    void reset();
    void readReg(uint8_t* address, uint16_t r_length, uint8_t* output, uint16_t w_length);
    void writeReg(uint8_t* address, uint16_t r_length, uint8_t* values, uint16_t w_length);
    void gotoMode( int mode);
    uint8_t read( uint8_t address);
    void write( uint8_t address, uint8_t value);
    void BurstWrite( uint8_t address, uint8_t *value, uint8_t length);
    uint8_t isvalid();
    
    void setLowDaraRateOptimization( uint8_t value);
    void setAutoLDO();
    void setFrequency( int freq);
    void setSpreadingFactor( int SP);
    void setPower( uint8_t power);
    void setOCP( uint8_t current);
    void setTOMsb_setCRCon();
    void setSyncWord( uint8_t syncword);
    uint8_t transmit( uint8_t* data, uint8_t length, uint16_t timeout);
    void startReceiving();
    uint8_t receive( uint8_t* data, uint8_t length);
    void receive_IT( uint8_t* data, uint8_t length);
    int getRSSI();

    void set_frequency(int frequency);
    void set_spredingFactor(uint8_t spredingFactor);
    void set_bandWidth(uint8_t bandWidth);
    void set_crcRate(uint8_t crcRate);
    void set_preamble(uint16_t preamble);
    void set_power(uint8_t power);
    void set_overCurrentProtection(uint8_t overCurrentProtection);

    private:

    static loRa_class* loRaInstance;

};