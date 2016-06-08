So you want to build your Gameboy Zero Gamepad?

- *Helder, from Sudomod.com, is working on a PCB for the Gamepad*

# I) Flashing the bootloader
  As soon as you have your board fully populated, you will need to install the Arduino bootloader on it so that it will be considered as an Arduino Leonardo (or Pro micro).
  The chip comes empty so you will need to burn on it what's called a bootloader. It's a simple piece of software that will allows you to update the program on the chip without need to flash it through a special adapter like the Pickit2.
  Here is the tutorial on how to do it:
  http://electronut.in/bootloader-atmega32u4/

# II) Getting the libraries needed & flashing the code
  I have written a little bit of code in order to make the board appear as a Joystick on the computer. Though in order to do that, I needed to use the library from [GAMELASTER](https://github.com/GAMELASTER/ArduinoGamepad) that I have slightly modified.
  So now, you will need to download the Github folder, either by click on the green button "Clone or download".
  
  Once it is done, start the Arduino program and go to "Sketch -> Include Library -> Add .ZIP Library..." and select the file that you just downloaded.
  Then it is just a matter of opening the example file I made: File -> Examples -> BoyduinoGamepad -> GameboyPCB
  It should show you the code of the Gamepad.
  Then you need to go to the Tools menu, in Board select "Arduino Leonardo", and in the Serial Port, choose the one that correspond to your board.

  Once you are ready, just clic the arrow on the top-left of the screen and wait for the sketch to upload.
  As soon as it is finished, you can go to Windows' peripheral list and choose the gamepad and test it.
