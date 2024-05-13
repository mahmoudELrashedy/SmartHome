# Smart_Home
Smart doorlock and temperature control\
3 ATmega32 microcontrollers communicate over the I2C , SPI , and UART protocols. In this project multiple modules have been used like: 24C02C, LM35, and L298.\
First MCU is the entry MCU it communicate with EEPROM using I2C protocol to set a password then store it in the EEPROM, then each time the user enters a password the MCU will check if it's the same as password stored in the EEPROM.\
if the first stage completed well then it's control MCU time the entry MCU will send signal to the control MCU via UART to tell it if the password is correct or not.\
if wrong there are 8 leds that will blink for 20sec.\
if correct then it's time for sensors MCU to read temperature sensors reading and send it to the control MCU via SPI to control the fans speed.\ 


