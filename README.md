# Dance-Maniax-DIY-Controller
A DIY solution for creating a Dance Maniax controller, I wound up spending less than $40-50 on the whole thing.

# Requirements:

-Teensy 2.0 (This is what I used, but any microcontroller/arduino could theoretically be used for this)

-Four Sharp GP2Y0A21YK0F sensors (can also be used with other IR sensors from Sharp but this one has the farthest range)

-Soldering iron and solder

-A computer to program the microcontroller, but if you're using Stepmania you probably already have this!

# Optional, but always great to have:

-The Teensy 2.0 board uses a mini usb cable to connect to a computer but doesn't include one in the box. Other controllers may require different cable types so do your research!

-I wound up deciding to get Male to Female jumper cables to extend the sensors further out than the provided cables do. I used the ones here: https://www.amazon.com/gp/product/B06XRV92ZB/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1

-Respirator, no solder fumes for me!

-Helping Hands to hold the board while soldering (and while it was still in the DIY phase this doubled as my controller stand for a while)

-I'm working on a 3D-printable enclosure to make everything look nice and neat. No more wires! Will update with the model and printing instructions as soon as it's available.

# Hardware Setup

1. Once you've got all your materials, you'll want to begin by taking a look at the board you're using and the wiring diagram for the sensor. In this case if you're using a Teensy 2.0 and Sharp GP2Y0A21YK0F, you'll want to view these documents:

https://www.pololu.com/file/0J85/gp2y0a21yk0f.pdf
https://www.pjrc.com/teensy/card2b_rev5_web.pdf

Notice how the motion sensors have three wires- one for ground, one for power (vcc), and one for the actual data connection. Note which ones they are on the sensors as we don't want to solder the wrong wires into the wrong place. On our Teensy board, these will be going into the Ground, VCC, and A1-4 holes. Our sensors will all be sharing a single Ground and VCC hole, but we'll be soldering them one by one to the data holes.

2. We'll begin by heating up the soldering iron and readying the solder. Begin by getting all four ground cables into the Ground hole and creating a solder joint going out the bottom. I won't go too into detail about the soldering process but definitely view some soldering tutorials on YouTube if you have not soldered before. These should be pretty easy joints to do, so no stress!

Of course, once you're all done you'll want to do the same for the VCC/Power cables, all in one hole and soldered in nice and easy. We'll want to finish by soldering in A1, followed by A2-4. Make sure you don't combine two wires into the A holes. Just one hole per wire for this one. Once you're done, you should have six joints in total.

3. Once you're all done soldering, you're going to want to pick two sensors that will make up the left part of your controller, and two sensors that will make up the right part. They'll be back-to-back on top of each other with one sensor facing up toward the ceiling and the other facing down toward the floor. For now, I secured mine with just a bit of tape, and then used my helping hands to hold the combined sensors upright for play. However, I'm working on a 3D printable model that can be used to screw the sensors into a secure arcade-inspired enclosure that can be attached to a tripod mount. I figure it should make everything a lot easier going forward. For now, do what works best for you and find a good way to keep those sensors together and in a place where you can use them.

# Software Setup

Woot! You made it to the software side of things! This is where things get even easier! 

1. Once you've got your soldering out of the way, plug your usb connector into the microcontroller and your computer. We'll want to download the Arduino software (or if using a Teensy, Teensyduino). You can find the software here: https://www.pjrc.com/teensy/td_download.html. Users on Windows and Linux will have to download the official Arduno software and install Teensyduino on top of it, while Mac users will be able to just install Teensyduino.

2. Since the code is already premade, download the zip file for this repository. You can go ahead and open the Sharp_IR_DMX.ino file in the Arduino software. 
 
3. Select your board type in the Tools menu under Tools -> USB Type. If using a Teensy 2.0, we'll use Teensyduino -> Teensy 2.0. Set the USB type to "Keyboard + Mouse + Joystick", and make sure your Teensy is selected under the section called "Port".

4. We'll want to install the SharpIR library, because it tells our Teensy how to communicate back and forth with the motion sensors. To do this, we can go to Tools -> Manage Libraries, and make sure SharpIR is installed. If not, search for and install it.

5. Once that's all installed, we can go ahead and click verify on our code. It shouldn't produce any errors here, but if it does definitely post an issue on the github and I'll see what I can do to help! If all passes, go ahead and click the upload button. You may be asked to click the button once on the teensy to put it into programming mode. 

Note: The values used in this file are based on my play, but may not be accurate to your situation. If you notice that the sensors are too sensitive or not sensitive enough during play, adjust the lines that say "if average(number of sensor) > 100" and change that number to something higher or lower to adjust the sensitivity. Lower than 100 will typically trigger game button presses more often in response to motion, while higher will typically trigger game button presses less.

 
6. Once it has programmed and restarted, your controller is now off to the races! You can test it using build in utilities like Windows joystick testing settings, or you can go right into stepmania's input test and see what it turns up. From here, you can map the controller as you usually would. Congrats, you're up and running with a Dance Maniax controller!

