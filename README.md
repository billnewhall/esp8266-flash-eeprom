# Using EEPROM/Flash on ESP8266 / NodeMCU

## Overview
 This program reads the existing values in flash, and then writes "Hello World!" and an incrementing integer value to flash.  Hit reset on ESP8266/NodeMCU to re-read from flash (currently stored contents) and write a new value to flash.

 On the first run, the program will display (using print) the currently stored values in Flash (probably appears as garbage).  After the first reset, readable values should be retrieved.

 Tested on this hardware:
 * https://www.amazon.com/gp/product/B01IK9GEQG/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&th=1

## Example Output

Note that the integer value after "Hello World!" increments after each reset.

``` 
Starting
sizeof(val_struct): 36
Allocated for val_struct.str_val char array: 32
sizeof(val_struct.un_val): 4
Allocated for EEPROM: 64
EEPROM was: Hello World! 7

<Press reset, and get some garage text here due to reset>

Starting
sizeof(val_struct): 36
Allocated for val_struct.str_val char array: 32
sizeof(val_struct.un_val): 4
Allocated for EEPROM: 64
EEPROM was: Hello World! 8

<Press reset, and get some garage text here due to reset>

Starting
sizeof(val_struct): 36
Allocated for val_struct.str_val char array: 32
sizeof(val_struct.un_val): 4
Allocated for EEPROM: 64
EEPROM was: Hello World! 9
```
Sizes of the variables are output to demonstrate the number of bytes allocated to the structure.

## References 
 Uses EEPROM class.  For references, see:
 
 * https://arduino-esp8266.readthedocs.io/en/latest/libraries.html
 * https://arduino.stackexchange.com/questions/25945/how-to-read-and-write-eeprom-in-esp8266
 * https://github.com/esp8266/Arduino/tree/master/libraries/EEPROM

## Other Notes
 Depending on the application, consider using ESP_EEPROM to save write cycles:
 * https://github.com/jwrw/ESP_EEPROM
 
