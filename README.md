# PICO-ESP-CLOCK-ST7789-NO-RTC
A basic clock module for the Pico/ESP MCU's for the ST7789 display driver. 

![Snapchat-1865240728_2](https://user-images.githubusercontent.com/93004427/202897489-4d13ee83-ccac-40f1-9950-46377bc48065.jpg)
![Snapchat-1530852281_2](https://user-images.githubusercontent.com/93004427/202897498-20dc2186-48fb-4b88-95c0-caf60db98b8e.jpg)

This clock does not use RTC or WiFi to get the current time so it must be set manually each time.

It is a very early WIP design for a clock module I am currently making. For now this design only works with the Pico-Display Pack from Pimoroni but it's easy enough to change the pins to use any ST77XX SPI display! (I also have a i2c LCD version for esp8266 that I will upload eventually)

This is also my very first C project, I've done my best to make sure everything is working correctly although there is still a lot more work to be done and I don't expect the code to be perfect. So if you have any feedback/criticism feel free to let me know! :)

BTW you will need this library installed: https://github.com/3tawi/PicoEspTime (YOU WILL ALSO NEED ST7789 & ADAFRUIT GFX LIBRARIES! I HAVE INCLUDED THEM IN THE REPO BUT YOU STILL MIGHT NEED TO DOWNLOAD THEM YOURSELF!)
