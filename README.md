## Arduino RC Car Project

# Bluetooth Protocol Format:
	{deviceLetter}{deviceID}*{deviceValue}*
  
# Part List:
*	Arduino Uno
*	Arduino 5V sensor shield
*	Arduino bluetooth module (HC-06)
*	2 x 3.7V 900mAh Li-ion rechargeable batteries with holder/power switch
*	Arduino DC Motor Controller L298N
*	4 x reduction motors from kuman smart car kit
*	3d printed mounting frame
*	4 x 3d printed motor brackets
*	4 x wheels

# Car Build Process:
Building my car was a long process that consisted of programming, testing, fixing, designing, printing, reprinting, assembly, and even more testing and fixing. The first thing I did was gather my electronic parts and made a mock version with a breadboard so I could develop and test the code on it. I used my old arduino code as a basis for how the bluetooth string parsing would work and improved on it and made is cleaner. After I did that I uploaded it to my arduino and tested it using a testing app that will send a bluetooth string to the arduino and than fixed the few minor errors that I had. After that I Made my first model for my car frame, this model had a slot for a servo motor and large circles fo bearing for the front two motor mounts but due to the inaccuracy of my 3d printer the large circles were not perfect enough for the bearing and the size of the servo slot was too small, I then redesigned the car frame to work without it and moved a few things around on it to make everything fit on it much nicer, the motor brackets were not designed because the first design I printed was perfect for them. After that I started to work on a new controller app using MIT app inventor 2, the app uses the orientation sensors in an android phone to control the speed of each set of motors to drive it forward and backwards and to steer by sending a bluetooth string to my arduino. After the app was working I assembled, wired, and tested the car and after some fixing of the app the car drove well.

# Car Functionality:
The car is able to receive a bluetooth string from the app that uses orientation sensors to set the speed and direction of the motors. The car has a motor for each of its 4 wheels and each set is wired in parallel to the my L299N motor controller which changes the directions and speed depending on the input from the arduino.

# Design Choices:
Compared to my last semester car I completely redesigned the frame and how everything was put together. For the frame I decided to put all my components on stands and attach it to a thin plate body that was 3d printed instead of making the parts nested into the frame, this makes it look much nicer and organized and allowed for things to be wired and fixed much more easily. My next design change was to use 4 motors with wheels instead of 2 motors with 3d printed wheels, this was done because unlike last time I now have proper motors and wheels for a project like this, this allowed it to drive much better and more consistently. I also mounted the motors onto the “plate” frame to give everything more height and accessibility, this allowed for my motors to be easily wired and fixed if needed. The battery was also changed from 1 - 2 9V batteries to 2 x 3.7V Li-ion batteries that came with the kit I used to get my parts from, this allowed me to easily turn my car on and off and have a more reliable power source that could be recharged. I also added a sensor shield to make interfacing with the arduino much easier and cleaner. The final major change was to the app, instead of it being controlled by 3 buttons and a direction slider I had it so the app could look at the phones orientation and use that to set the speed of each set of motors. 
