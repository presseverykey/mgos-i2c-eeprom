
#include "i2ceeprom.h"

i2c_eeprom * i2c_eeprom_get_global() {
  global_eeprom.i2c = mgos_i2c_get_global();
  global_eeprom.addr = mgos_sys_config_get_i2ceeprom_addr();
  global_eeprom.size = mgos_sys_config_get_i2ceeprom_size();
  global_eeprom.pgsize = mgos_sys_config_get_i2ceeprom_pgsize();
  
  return &global_eeprom;
}


static uint16_t bswap16 (uint16_t a) {
  return ((a & 0x00FF) << 8) | ((a & 0xFF00) >> 8);
}

#define I2C_READ 0x01

bool i2c_eeprom_read(i2c_eeprom * eeprom, i2c_eeprom_addr addr, uint8_t * data, size_t n) {
  addr = bswap16(addr);
  return mgos_i2c_write(eeprom->i2c, eeprom->addr, &addr, 2, false) &&
    mgos_i2c_read(eeprom->i2c, eeprom->addr, data, n, true);
}

bool i2c_eeprom_write(i2c_eeprom * eeprom, i2c_eeprom_addr addr, uint8_t * data, size_t n) {
  addr = bswap16(addr);
  return mgos_i2c_write(eeprom->i2c, eeprom->addr, &addr, 2, false) &&
    mgos_i2c_write(eeprom->i2c, eeprom->addr, data, n, true);
};

bool mgos_i2c_eeprom_init(void) {
  return true;
}

// vim: et:sw=2:ts=2
