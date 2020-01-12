/*
 * Demonstrates reading and writing from ESP8266/NodeMCU EEPROM (actually flash).
 * 
 * Uses EEPROM class.
 * 
 * See: https://arduino-esp8266.readthedocs.io/en/latest/libraries.html
 *      https://arduino.stackexchange.com/questions/25945/how-to-read-and-write-eeprom-in-esp8266
 *      https://github.com/esp8266/Arduino/tree/master/libraries/EEPROM
 *      
 * This program reads the existing values in flash, and then writes "Hello World!" 
 * and an incrementing integer value to flash.  Hit reset on ESP8266/NodeMCU to re-read
 * from flash (currently stored contents) and write a new value to flash.
 * 
 * Tested on:
 * https://www.amazon.com/gp/product/B01IK9GEQG/ref=ppx_yo_dt_b_search_asin_title?ie=UTF8&th=1
 * 
 * Depending on the application, consider using ESP_EEPROM to save write cycles:
 * https://github.com/jwrw/ESP_EEPROM/blob/master/examples/ESP_EEPROM_Use/ESP_EEPROM_Use.ino
 * 
 * W. Newhall (original) 1/2020
 */

#include <EEPROM.h>

#define   EEPROM_SIZE_BYTES   64    // Amount of memory allocate for "EEPROM" (flash)
#define   STR_SIZE_BYTES      32    // Size of string to store

void setup() {
  // Use a structure instead of char array so that EEPROM.get and .put can figure 
  // out sizeof the data to be read.
  struct {
    char str_val[STR_SIZE_BYTES];   // A string to store and read from EEPROM
    unsigned int un_val; 
  } val_struct;
  
  unsigned int eeprom_addr = 0;     // Address to start reading

  // Startup of serial and startup message
  Serial.begin(115200);
  Serial.println(" ");
  Serial.println("Starting");
  
  // Commits EEPROM_SIZE_BYTES of flash and reads contents of flash into 
  // into array cache in RAM.
  EEPROM.begin(EEPROM_SIZE_BYTES);

  // Show some info on the sizes of struct and struct fields
  Serial.println("sizeof(val_struct): " + String(sizeof(val_struct)));
  Serial.println("Allocated for val_struct.str_val char array: " + String(STR_SIZE_BYTES));
  Serial.println("sizeof(val_struct.un_val): " + String(sizeof(val_struct.un_val)));
  Serial.println("Allocated for EEPROM: " + String(EEPROM_SIZE_BYTES));

  // Read EEPROM as-is
  EEPROM.get(eeprom_addr, val_struct);
  Serial.println("EEPROM was: " + String(val_struct.str_val) + " " + String(val_struct.un_val));

  // Create new integer value for EEPROM
  strcpy(val_struct.str_val, "Hello World!"); // Put in a string
  if(val_struct.un_val > 100)   // If the read value is greater than 100
    val_struct.un_val = 0;      //    then set it to zero.
  else
    val_struct.un_val++;        // If not > 100, increment it.

  // Store the values in the EEPROM
  EEPROM.put(eeprom_addr, val_struct);  // Put the values in the RAM cache
  EEPROM.commit();                      // Write to EEPROM

}

void loop() {
  // Don't do anything, just wait
  delay(1000);
}
