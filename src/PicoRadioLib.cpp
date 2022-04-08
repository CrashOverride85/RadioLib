#include "PicoRadioLib.h"

#include "pico/stdlib.h"

uint8_t digitalPinToInterrupt(uint8_t pin)
{
  return pin;
}

int digitalRead(uint8_t pin)
{
  return gpio_get(pin);
}

void pinMode(uint8_t pin, uint8_t mode)
{
    gpio_init(pin);
    gpio_set_dir(pin, mode == OUTPUT ? GPIO_OUT : GPIO_IN);
}

void digitalWrite(uint8_t pin, uint8_t value)
{
  gpio_put(pin, value);
}

void attachInterrupt(uint8_t pin, void (*UserFunc)(void), int mode)
{

}

void detachInterrupt(uint8_t pin)
{

}

void delay(unsigned long ms)
{
  sleep_ms(ms);
}

void delayMicroseconds(unsigned int us)
{
  sleep_us(us);
}

unsigned long millis()
{
  return to_ms_since_boot(get_absolute_time());
}

unsigned long micros()
{
  return to_us_since_boot(get_absolute_time());
}
