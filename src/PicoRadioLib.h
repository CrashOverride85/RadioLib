#include "../../../config.h"
#include <inttypes.h>
#include <math.h>
#include "hardware/gpio.h"
#include "hardware/spi.h"
#include "pico/stdlib.h"

#define SPI_BAUD_RATE 2000000


#define MSBFIRST 1

#define SPI_MODE0 0x00
#define SPI_MODE1 0x04
#define SPI_MODE2 0x08
#define SPI_MODE3 0x0C

#define HIGH 1
#define LOW  0

#define INPUT           (0x0ul)
#define OUTPUT          (0x1ul)

#define CHANGE 1
#define FALLING 2
#define RISING 3

uint8_t digitalPinToInterrupt(uint8_t pin);
int digitalRead(uint8_t pin);
void digitalWrite(uint8_t pin, uint8_t value);
void pinMode(uint8_t pin, uint8_t mode);
void attachInterrupt(uint8_t interupt, void (*UserFunc)(void), int mode);
void detachInterrupt(uint8_t interupt);
void delay(unsigned long ms);
void delayMicroseconds(unsigned int us);
unsigned long millis();
unsigned long micros();

// Mostly copied from https://github.com/arduino/ArduinoCore-avr/blob/master/libraries/SPI/src/SPI.h

class SPISettings 
{
public:
  SPISettings(uint32_t clock, uint8_t bitOrder, uint8_t dataMode) 
  {
    
  }
  SPISettings() 
  {
    
  }
};


class SPIClass {
public:
  
  static void begin()
  {
    gpio_set_function(PIN_MISO, GPIO_FUNC_SPI);
    gpio_set_function(PIN_SCK , GPIO_FUNC_SPI);
    gpio_set_function(PIN_MOSI, GPIO_FUNC_SPI);
  //gpio_set_function(PIN_CS  , GPIO_FUNC_SPI); don't let the Pico play with the CS line, RadioLib manages that pin itself
    
    spi_init(spi0, SPI_BAUD_RATE);
    spi_set_format(spi0, 8, SPI_CPOL_0, SPI_CPHA_0, SPI_MSB_FIRST);
  }

  inline static void beginTransaction(SPISettings settings) 
  {

  }

  // Write to the SPI bus (MOSI pin) and also receive (MISO pin)
  inline static uint8_t transfer(uint8_t data) 
  {
    uint8_t rx[1] = {0};
    uint8_t tx[1] = {0};

    tx[0] = data;

    spi_write_read_blocking(spi0, tx, rx, 1);

    return rx[0];
  }

  inline static void endTransaction(void) 
  {
  
  }

  // Disable the SPI bus
  static void end()
  {
    spi_deinit(spi0);
  }
};
