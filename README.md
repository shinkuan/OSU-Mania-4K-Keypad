# OSU-Mania-4K-Keypad

A small keypad for playing OSU!Mania 4K

## Guide
### 1.Print out the PCB
You can take the Garber, BOM, PickAndPlace files in PCB Design folder.
And go to JLCPCB or PCBWay, or any other company that helps you print out your board.
It's my first time design a PCB, so it might not looking good. (._.)
### 2.Get the parts
| Parts  | Quantity |
| ------------- |:-------------:|
| Arduino Pro Micro      | 1     |
| 8P connector      | 2     |
| Switch      | 8     |
| 104 Capasitor      | 8     |
| SK6812MINI-E      | 8     |
| 471 Resistor      | 1     |
| Hotswap Sockets      | 8     |
### 3.Solder
Should be pretty easy, there are plenty YouTube tutorials.
### 4.Upload the code
You need Arduino IDE here, or you can use [Arduino Web Editor](https://create.arduino.cc/editor).
Just copy my code if you don't know coding. And of course you can edit it for your own purpose.
### 5.Done
Congrats! You now have a 4+4 kaypad for you to play mania 4K!

## Known Bugs
* Sometimes when you press a button, Arduino reads another one pressed while it is not pressed.
* RGB LED is cauing some short. Reason is unknown. I desolder the SK6812 to solve this.

## TODO List
* 3D Printable Case
* Fix the bugs so keypress is more consistant.
* Fix the bugs so LED is possible.
* Move from Arduino to STM32. Remove the Pro Micro and place STM32 chip right on PCB.
* USB Type-C Connector
* A better solution to 8P connector, maybe FFC/FPC connectors?

![Keypad](https://i.imgur.com/l4t3Bad.jpg) ![Keypad](https://i.imgur.com/4NjcQ7m.jpg) ![Keypad](https://i.imgur.com/uRJIo9K.png)


