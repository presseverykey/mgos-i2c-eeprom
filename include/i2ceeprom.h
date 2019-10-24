#pragma once

#include <stdint.h> 

#include "mgos_i2c.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

// struct

typedef uint16_t i2c_eeprom_addr ;

typedef struct i2c_eeprom {
  struct mgos_i2c * i2c;
  uint8_t addr;
  uint16_t size;
  uint16_t pgsize;
//  i2c_eeprom_addr current_addr;
} i2c_eeprom;

static i2c_eeprom global_eeprom;

i2c_eeprom * i2c_eeprom_get_global();
bool i2c_eeprom_read(i2c_eeprom * eeprom, i2c_eeprom_addr addr, uint8_t * data, size_t n);
bool i2c_eeprom_write(i2c_eeprom * eeprom, i2c_eeprom_addr addr, uint8_t * data, size_t n);

// cfg_struct

#ifdef __cplusplus
}
#endif /* __cplusplus */

// vim: et:sw=2:ts=2
