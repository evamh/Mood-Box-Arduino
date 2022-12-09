## Inspiration and Ideation

I wasn't sure where to begin when coming up with an idea for my final project. As I've always enjoyed playing games, I was initially drawn to creating a game of some kind - for example something similar to the popular game *Bop It!* where the machine instructs the user to perform some action (such as pulling a lever or pushing a button) and the user has to react accordingly. However, after giving it some more thought and discussing potential ideas with others, I thought it would be more interesting to explore how our senses can affect our moods; more specifically the sensory input of sound, light and scent. 

I decided to delve into this idea by creating a 'Mood Box', whereby the user chooses a mood and the box lights up/plays music/emits scent associated with that choice. I'll focus on three moods in particular that already have strong associatons with different types of sensory input: sleeping, focusing and a mood boost.

I did some research to see which colors/sounds/scents were typically associated with these three moods, and drew out the output per choice:

<img src="https://git.arts.ac.uk/storage/user/650/files/0f2bf66b-55c0-4633-8bff-8d41fff90f85" width="30%"> <img src="https://git.arts.ac.uk/storage/user/650/files/688010ee-f506-4014-9d3f-bfc4942ee688" width="27%"> <img src="https://git.arts.ac.uk/storage/user/650/files/9ff20d2a-fb4d-45b9-8e80-1a24888ed631" width="25%">

From this, I was able to hone in on my electronic inputs and outputs:

**Inputs**
1. Push buttons to select a mood (x3)
2. Potentiometer to change the response

**Outputs**
1. Audio (via a speaker and mp3 files)
2. Scent (initial idea was to use a servo motor to control a spray bottle)
3. Lights (via neopixels)

I also quickly drew a sketch of what I pictured the housing to look like:

<img src="https://git.arts.ac.uk/storage/user/650/files/f2b5e6d1-a49c-4e90-b59b-6fad0ba85579" width="30%">



## Week 1 (Nov. 7 - 11)

My aim for this week is to clarify which components I need, gather them, and then draw the circuit in Tinkercad. 

For the audio, I researched potential options on the CCI wiki. The two I found were the Sparkfun MP3 Player or the DFPlayer Mini. It seems the DFPlayer Mini is easier to set up and a little more low-fuss; given I just need to output a few mp3 files this seems like the easier option. I collected the part and a headphone jack from the hack lab. 

When wiring the circuit on Tinkercad, I started off small with simple circuits and built up to something resembling my final idea. I began with three buttons/three LEDs. Once I got that to work, I moved on to three buttons and an RGB LED (given I was going use a neopixel and the RGB LED is more similar in nature), then a circuit for three buttons, a potentiometer and an RGB LED. Finally, I added three servos which are going to serve as the scent output. Unfortunately, Tinkercad didn’t have a DFPlayerMini so I couldn’t add that to the circuit.

Finally, I drew a few more sketches for the housing of my project in order to get a better sense of what I envisaged the final product to look like. 



## Week 2 (Nov. 14 - 18)

My objectives for this week are to get the DFPlayer Mini working on the breadboard and work on the spray bottles with a servo concept for the scent component. 

### DFPlayer Mini

In order to test the DFPlayer Mini, I loaded a test audio file onto an SD card (music from the original *The Sims*, one of my favourites!). I then followed the CCI wiki instructions, as well as a couple of examples online, in order to wire the player on the breadboard. I used a headphone output and a pair of headphones for the sound.  

<img src="https://git.arts.ac.uk/storage/user/650/files/7ef5797f-5fd5-4c0b-a2a5-e035d5a26665" width="50%">

Surprisingly, it didn’t take too many attempts before I was able to get it working. It was a great feeling to hear the upbeat *Sims* music playing out through the headphones! Once that was done, I decided to upgrade to an actual speaker. I soldered two wires to a small speaker from the hack lab, and plugged that into the breadboard. A few minutes later, the song was playing out loud.

<img src="https://git.arts.ac.uk/storage/user/650/files/32daace2-42e4-4a8b-9fa5-d58837a61457" width="25%">  <img src="https://git.arts.ac.uk/storage/user/650/files/c878d819-4b2c-4d7a-b6f9-bc6e98fa547f" width="25%">

### Neopixel and circuit

The next step was to add light that would change colour depending on a button pressed. I soldered wires onto an 8 pixel neopixel, added 3 buttons to the breadboard and combined the circuit together with code. I initially programmed simple RGB colours for each button - red for button 1, green for button 2 and blue for button 3. I also added a condition to make the DFPlayer Mini play music if button 1 was pressed.

<img src="https://git.arts.ac.uk/storage/user/650/files/3647c472-2b13-47f4-b2d3-3f6456e76fad" width="25%"><img src="https://git.arts.ac.uk/storage/user/650/files/e7527803-7bd4-4813-aa44-8564a1d7d713" width="25%"><img src="https://git.arts.ac.uk/storage/user/650/files/b96c5bed-1e25-4500-9979-758b655e783b" width="25%"><img src="https://git.arts.ac.uk/storage/user/650/files/d92b905e-48f8-4041-b4d9-b213f36076fd" width="25%">


### Scent output

Another goal this week is to prototype the scent output. My initial idea was to follow this guide (https://srituhobby.com/how-to-make-a-simple-automatic-control-diy-hand-sanitizer-bottle-using-arduino/), and use a servo motor to spray a bottle which will release scent. I ordered a set of mini spray bottles, got some servo motors, and started prototyping.

I first attached the servo sideways to the top of the bottle cap, securing it using strong tape. I then began to test with string and wire to try and get the motor to control the spray mechanism.

<img src="https://git.arts.ac.uk/storage/user/650/files/bfa314d4-1c90-4022-81dc-3e0574257d25" width="25%"> <img src="https://git.arts.ac.uk/storage/user/650/files/fe23954d-4125-4edb-bd30-e55e2a86cf0c" width="25%">

String seemed like it would be too flimsy to properly pull the spray mechanism back and forth. I spoke to Pete who suggested I use strong wire instead, as that could potentially be robust enough to do the trick. However, I quickly realised that this idea wouldn’t work out as easily as I had anticipated. To actually get the cap to spray water required some level of power from me, and the servo motor would clearly not be strong enough to do it by itself. I decided to start looking for alternative approaches to release scent. 

I ordered some atomisers that diffuse water when placed on a humid surface, and made it a goal for the following week to get it to work.

### Code
This week I also started writing my main code, adding functionality each time I introduced a component to the circuit. 

## Week 3 (Nov. 21 - 25)

My main goal for this week is to get the atomiser working, add a potentiometer to my circuit, and connect all the pieces together on a breadboard. 

### Scent output

The 3 atomisers arrived, each with its own separate circuit board. I started off by trying to figure out how the circuit board was working. The board itself has a USB input, a button, and a +/- header to place the atomiser component. I plugged the USB and atomiser in, and pressed the button. Sure enough, the blue LED on the circuit board switched on, and the atomiser started to buzz. 

The next step was to connect the circuit board’s power to the breadboard rather than the USB. This was surprisingly easy to figure out - under the USB port are spaces for a positive and negative connection. I quickly stuck two wires through these, connected the other ends to my breadboard, and the connection was made. I then soldered these wires in place, and did the same for the other two boards. 

The challenge remained to toggle the atomiser on/off using my Arduino rather than having to press the button on the atomiser’s circuit board. The first thing I tried was to disconnect the atomiser from the circuit completely, and plug the positive end into a digital pin on the Arduino. The aim was to be able to supply voltage to the atomiser using digitalWrite() instead of having to press the button.

<img src="https://git.arts.ac.uk/storage/user/650/files/a8e3413a-e1b8-4d65-bddb-7d985d0ff28c" width="25%">

This didn’t work. Looking more closely at the atomiser’s circuit board, I realised that there seems to be a capacitor on the board itself, which suggests that the atomiser needs more power in order to work. 

My next approach was to keep the atomiser connected to its circuit board, but somehow keep the button pressed down and supply voltage via a digital pin. I taped the button down with tape, connected ground to ground and power to a pin. This produced interesting behaviour - the blue light on the circuit board would flash on and off for extremely short intervals when power was supplied via the digital pin. The atomiser wasn’t staying on for long enough, but at least something was happening.

To experiment, I connected the circuit board (still with the power pressed down) directly to 5V rather than a digital pin. This worked fine, which confirmed that 5V is enough power for the atomiser to work in connection with the circuit board. In fact, 3.3V is enough - this connection also worked just fine.

This made me think the digital pins have some resistance to them. To test this theory, I connected the circuit board to a breadboard, and added a 220 Ohms resistor from the circuit board to 5V (no digital pins). The blue light started flashing on and off very quickly, in a very similar fashion to when the board was connected to a digital pin. 

<img src="https://git.arts.ac.uk/storage/user/650/files/4db2462a-911a-41ff-808c-9d20829e045e" width="25%"> <img src="https://git.arts.ac.uk/storage/user/650/files/e9afd6ba-4b36-4e0b-a615-2a144c952691" width="40%"> <img src="https://git.arts.ac.uk/storage/user/650/files/e41c27d2-50d2-412c-a41a-28abd9b8c91f" width="25%">

A fellow student and I started looking more closely at the circuitry of the board. We tested what happened when we connected a wire to a digital pin, and put the other end of the wire onto one of the soldered pins of the button (on the circuit board). This would actually switch the blue LED on and off as needed. To test more concretely, I soldered the wire onto the pin, plugged the end into a digital pin, connected the atomiser and gave it a try by writing code that did a digitalWrite() to the pin. Thankfully it worked! To celebrate, I soldered on wires to the two remaining circuit boards. 

### Adding a potentiometer

My second goal of this week is to add a potentiometer to the circuit and use it to control the brightness of the neopixel. This was pretty straightforward to add to my existing circuit. 

In order to translate the potentiometer input values to RGB values, I used the map() function to translate the upper and lower bounds of the potentiometer into valid RGB values. 

The brightness only changes after rotating the potentiometer right after a button is pressed, rather than dynamically after rotation. I made a note to change this functionality later on so that it’s more interactive. 

<img src="https://git.arts.ac.uk/storage/user/650/files/d6e10f66-b3e7-4f59-b1e2-c59c67869af2" width="25%">

### Neopixel

To make the light component of the project more interesting, I soldered a neopixel ring of 16 pixels to the neopixel strand, using the out connections of the strand to connect to the in connections of the ring.

<img src="https://git.arts.ac.uk/storage/user/650/files/38b39154-b81a-41bf-a472-b0a167f01daf" width="25%">

### Entire circuit

Now that each of my individual components work, it’s time to put everything together and test that the main functionality is functioning.

I made sure to test four things:
1. Pressing button 1 turns the neopixel to blue, switches on the first atomiser circuit board, and plays a song on the DFPlayer Mini
2. Pressing button 2 turns the music off, switches off the first atomiser circuit board, turns the neopixel to green, and switches on the second atomiser circuit board 
3. Pressing button 3 switches off the second atomiser circuit board, turns the neopixel to red, and switches on the third atomiser circuit board
4. Changing the potentiometer and pressing a button changes the brightness of the neopixel

Everything works as expected. The next step is to solder everything onto a board.

<img src="https://git.arts.ac.uk/storage/user/650/files/c6503c76-b799-4f3c-8f4f-9bbe68e741e2" width="25%">

<img src="https://git.arts.ac.uk/storage/user/650/files/4cdb76b4-bbd1-4aae-8a75-5a9e37ce9fa0" width="50%">

## Week 4 (Nov. 28 - Dec. 2)

My aim this week is to get everything soldered, design and laser cut the final housing, and wrap up the code. 

I set up a tutorial with Matt to clarify a few things before beginning the soldering process, and he suggested to look into the INPUT_PULLUP functionality of the digital pins for the buttons. This would allow me to bypass the resistors and the need for individual power and digital pin connections. I did some more research and tested this on my circuit. It worked! This will simplify my final circuit quite a bit given I have three separate buttons. 

### Soldering 

Since the buttons are part of the user experience of the box, I first need to solder them to individual button breakout boards so they can be separated from the stripboard. This was pretty straightforward - I first soldered the button pins to the board, and then soldered a ground wire and a pin wire.

<img src="https://git.arts.ac.uk/storage/user/650/files/05c1f789-71d3-4466-a321-a8935f4510c9" width="25%"> <img src="https://git.arts.ac.uk/storage/user/650/files/58f7b015-0b23-420d-b803-d5173e89c769" width="25%">

Since this is my first time translating a circuit from a breadboard to a stripboard, I tried to create the circuit on a stripboard in Fritzing in order to make sure I understood the basic concept. 

<img width="50%" alt="board_sketch" src="https://git.arts.ac.uk/storage/user/650/files/727ac6ce-4fa0-4c5d-889d-459d57e9e42a">

To begin soldering, I figured out where the header pins should go to connect the board to the Arduino. I had to use two separate boards to connect into the Arduino, one that connected the first half of the board together (Analog pins and first set of digital pins) and one that connected the second half (power and rest of the pins). This is because the two sides of the Arduino aren’t balanced. I soldered the header pins onto the two boards.

<img src="https://git.arts.ac.uk/storage/user/650/files/6f0c6354-ba09-45bb-87ec-7835094f0a8b" width="25%">

Maybe foolishly, I began by soldering the most complicated part of my circuit onto the stripboard, the DFPlayer Mini. I first soldered the header pins to connect the player to, and then one by one added each connection - power, ground, RX with a resistor, TX, and the two speaker cables. 

I tested this with my Arduino and the DFPlayer Mini example, but it didn’t work. I triple checked that I didn’t mess up the wiring somehow (especially TX and RX!) but no issue there. I restarted the Arduino IDE, plugged the Arduino back in, but no luck. It wasn’t working.

At this point I wasn’t sure if I had just completely misunderstood how a stripboard works. To test, I added one button to the board, and checked that it worked by just printing to the Serial monitor if pressed. This worked, so I added both buttons in, testing each one at a time. I then added the neopixels and tested. Finally, I added all three atomiser circuit boards and tested.

Apart from the DFPlayer Mini, the rest of the components worked. I decided to count this as a win and call it a day, as I had already been soldering for several hours at that point.

<img src="https://git.arts.ac.uk/storage/user/650/files/f7104deb-79dd-4c32-b7aa-e37a95ec721e" width="50%">


The next day, my goal was to solder the potentiometer onto a separate board and connect this board to the main stripboard, as well as try to figure out why the DFPlayer Mini wasn’t working. 

I soldered the potentiometer into a three piece screw terminal, and connected that to a small stripboard. From there I added three wires (power, ground and input) and connected it all to the main circuit board. Time to test! I plugged my Arduino in, made sure I had code that was printing out the potentiometer values and uploaded.

At first, everything was just 0, even when I rotated the potentiometer. I checked my wiring (making sure I had gotten the right side for power and for ground), plugged the potentiometer in and out of the three piece screw terminal, used a screwdriver to properly fix the potentiometer in the terminal, but nothing worked. I analysed the board more closely, and saw that a small piece of solder had made its way between two rows on the stripboard. I cleared this off and the serial monitor started printing values.

I was initially relieved, but that feeling didn’t last long. I realised that the values coming in were random, as they would increase and decrease in no particular order and certainly not in connection to me rotating the dial. I asked Agnes who helped me use a multi-meter to test out the connections on my strip board. We made sure that each row was connected and adjacent rows weren’t, as well as making sure that the potentiometer board was connected to the main board. By using the multimeter I was able to figure out that the soldering of the three piece screw terminal onto the smaller stripboard was insufficient, as there was no connection between the potentiometer to the main board. I added more solder to the terminal, as well as for my other components (DFPlayer Mini included) and trimmed wires with a wire cutter to clean everything up. I plugged it in and like magic - everything worked, even the player. 


<img src="https://git.arts.ac.uk/storage/user/650/files/e771a13c-cd42-4643-b0be-8cc2a03ec7b0" width="25%"> <img src="https://git.arts.ac.uk/storage/user/650/files/d51195f6-5abb-4724-9c9c-6e07dc9ab4ce" width="25%">


### Code

Since my entire circuit is now correctly soldered, I decided to fine-tune the code itself. First I did some research for some audio files to play - a lullaby for sleep, classical music for focus and upbeat music for boost. While searching for the files, I had the idea to include several songs for each mood and randomise the selection. In the end, I found three songs for each and wrote code to randomly select which song gets played when the button is pressed.

**Music (in order on SD card)**
1. Serenade (Megan Wofford) -> sleep
2. Sleeping Kittens (Lil.Y) -> sleep 
3. Mr. Otter's Rainy Day (Lil.Y) -> sleep
4. Minuet From String Quintet In E Major, Op. 13, No. 5 Version 1 -> focus
5. String Quartet No. 5 in F Major, K. 158: Tempo Di Menuetto Part 2 -> focus
6. Waltz for the Emotional (Arylide Fields) -> focus
7. Call Me Up (Isola James) -> boost
8. Left Hand (Lofive) -> boost
9. U & Me (SLCT) -> boost


I also decided to adjust the neopixels colours and change the potentiometer functionality so that it would change the shade of the neopixels, not the brightness. For sleep, I decided to use shades between blue and purple, so I used a color picker to figure out the boundaries of R, G and B. Using map(), I translated the potentiometer values into these boundaries for sleep. I did the same for focus (green and blue shades) and boost (orange and pink shades).

Finally, I decided to improve the potentiometer functionality so that it changes the neopixel shade dynamically, rather than waiting for a button to be pressed. Because the Arduino loops so frequently, I added a threshold to check for before changing the color. If the potentiometer change is above the threshold, then the code would set the shade accordingly.

The next day, the DFPlayer Mini suddenly stopped working. Using a multimeter, I repeated the exercise from the day before and checked connections in the same row and adjacent rows. Everything seemed fine, so I tested that the 5V connection was connected to the 5V row (it was) and that the ground row was connected to the ground row (it wasn’t). Looking more closely at the ground row, I realised that part of the copper strip had peeled off, taking the DFPlayer Mini connection with it. I added solder to connect it back to the rest of the row, and it was working again. 

### Video demonstration of soldered circuit

Below is a video demonstrating the soldered circuit working. I tested that all three moods are working, rotating the potentiometer changes the lights and pressing the same mood twice can result in a different song selection. 

https://git.arts.ac.uk/storage/user/650/files/47342680-77d5-4c02-b2b5-653c6249b294


### Laser cutting

My second goal this week is to design and cut the main housing for my project. I knew I wanted the base of the house to be a box, with holes cut out for the different components:

1. Three square holes for the buttons, side by side
2. One square hole for the potentiometer on the end 
3. One circle hole at the bottom for the speaker
4. Three circle holes at the top for the scent diffusers
5. Holes on the side to connect power to the Arduino.

I found a template for a box on MakerCase, and measured out my different components to try and determine the overall size of the box. Once I figured this out, I downloaded the template and imported it into Adobe Illustrator.

In Adobe Illustrator, I calculated what the measurements should be for the holes and added those in, as well as engravings of SLEEP/FOCUS/BOOST above the respective buttons. I decided to customise the box a bit more, and played around with the shape builder tool to create clouds that I placed around the edges of the box.

Before cutting the design onto acrylic, I tested with cardboard to create a prototype. The box cut smoothly, but when I tried to place the buttons and potentiometers, I realised the sizes were a little too large.

<img src="https://git.arts.ac.uk/storage/user/650/files/05388d21-7e10-489b-a628-93c4f9f05752" width="25%">

I adjusted these accordingly and printed the final design on a clear, 3mm acrylic board.

<img src="https://git.arts.ac.uk/storage/user/650/files/f18a0545-8774-443f-a20a-3e1671d14a6e" width="25%">  <img src="https://git.arts.ac.uk/storage/user/650/files/cb9cfdd3-a0c7-47c3-a1c8-747fc21496e0" width="25%">

### Scent
For the actual diffusers, I decided to use the small spray bottles I had ordered since the top of the caps matched the size of the atomisers surprisingly well. I took apart the spray mechanism so I was left with just the cap and a hole for the atomiser.

<img src="https://git.arts.ac.uk/storage/user/650/files/2cb8dc39-f0e3-4050-be7c-d2fb6bd97ad3" width="25%">  <img src="https://git.arts.ac.uk/storage/user/650/files/580f8a25-a403-4c32-bb2c-348ebeaabee5" width="25%">


## Week 5 (Dec. 5 - 9)

For the final week, my goal is to put everything together and make sure it all works.

### Building the box

Building the box was surprisingly trickier than I expected. I bought plastic glue to glue the sides of the box together, but the glue unfortunately didn't stick. I decided to use tape instead to put the box together which kept it in place. 

<img src="https://git.arts.ac.uk/storage/user/650/files/7d4626ac-05c9-4003-a8d0-2f21544f44ca" width="25%"> <img src="https://git.arts.ac.uk/storage/user/650/files/5d3c964b-2dc6-4052-9f06-a4fc27c38ce5" width="25%">

I then placed my circuit inside the box and taped the buttons, potentiometer and speaker to their respective spots. I also taped the LEDs to the front of the box and wired the USB to the Arduino. I plugged it in to check that all the components worked as expected. Thankfully, almost everything did, but I noticed that when I pressed both button 1 and button 2, the sleep mood was enabled (rather than sleep and focus). I couldn't immediately see anything incorrect with how I put the circuit in the box, so I used a multimeter to check.

<img src="https://git.arts.ac.uk/storage/user/650/files/2a20f213-ee6c-47eb-a790-cdc36ba8c797" width="25%">

The power connection on button 1 and button 2 were connected, so I checked the stripboard and found a tiny sliver of copper wire connecting the two rows. I cleaned it off, and the board (and box!) was working again.

<img src="https://git.arts.ac.uk/storage/user/650/files/09ffa7e2-28c2-4810-a601-e7f33fbe9075" width="25%"> <img src="https://git.arts.ac.uk/storage/user/650/files/cd2a2565-990f-4a5b-b935-05b9c171ead1" width="25%">! <img src="https://git.arts.ac.uk/storage/user/650/files/59a620db-f172-4a35-957c-6e21e79f04bc" width="25%">

The next step was to fill the bottles with the correct essential oils, and attach the scent bottles to the top of the box. The oils were added as follows:
1. Sleep - blue bottle - lavender scent
2. Focus - yellow bottle - peppermint scent
3. Boost - pink bottle - citrus scent

<img src="https://git.arts.ac.uk/storage/user/650/files/71bbb0c5-40f4-4a40-ac5b-101d9f28798c" width="25%"> <img src="https://git.arts.ac.uk/storage/user/650/files/0121feec-fddc-40bb-bdd1-d4499928d6f8" width="25%">

The final step was to attach the atomisers to their corresponding circuit boards and close the box.

<img src="https://git.arts.ac.uk/storage/user/650/files/680c241f-ea3a-4e73-b5e5-3b1b13f9c413" width="25%">

After plugging power into the Arduino, I checked that each component worked as expected, and it all did!

SLEEP

<img src="https://git.arts.ac.uk/storage/user/650/files/4b188dc5-0dd1-47b3-8682-72cd0da02f4f" width="25%">


FOCUS

<img src="https://git.arts.ac.uk/storage/user/650/files/9f5b14d2-bc77-4088-8f6a-a8c89460b675" width="25%">


BOOST

<img src="https://git.arts.ac.uk/storage/user/650/files/8cfd8b69-397d-4f51-97be-d29e98defb8f" width="25%">

### More images of the final product
<img src="https://git.arts.ac.uk/storage/user/650/files/3db5d36b-4149-46c4-b5cc-fe9188b6db25" width="25%"> <img src="https://git.arts.ac.uk/storage/user/650/files/d665c0a8-c4b7-46a3-b8d1-46fc58daf568" width="25%"> <img src="https://git.arts.ac.uk/storage/user/650/files/64531818-5c4d-4385-b306-622707d72f3e" width="25%">

<img src="https://git.arts.ac.uk/storage/user/650/files/be5f3bca-45f0-4847-8109-615ce43efff6" width="25%"> <img src="https://git.arts.ac.uk/storage/user/650/files/f30d1481-142a-4afe-b5a2-4a3cee160812" width="25%"> <img src="https://git.arts.ac.uk/storage/user/650/files/137cfabb-479a-496d-9322-70e81f2bd146" width="25%">

<img src="https://git.arts.ac.uk/storage/user/650/files/38917d5d-81e4-45ea-87df-8b382ecc2653" width="25%"> <img src="https://git.arts.ac.uk/storage/user/650/files/67ea95ab-3c2d-41df-82b6-7aeba9452ee2" width="30%"> <img src="https://git.arts.ac.uk/storage/user/650/files/2a0b75e1-edc2-4bc8-9a45-ffe6c2c0a453" width="40%">

### Video demonstration of entire box
https://git.arts.ac.uk/storage/user/650/files/75c02928-4f8d-442a-84a1-0147061a26c0

### Things I would do differently

This project was a first for me in almost every respect: going through the ideation process, designing a product, discovering various electronic components, wiring a circuit, soldering, laser cutting, etc. As such, there were a few things I was unfamiliar with and would now do differently given the experience.

The main one would be the soldering process. I would first try to get a board that's the correct size rather than a larger one. The larger board took up more space in the final box and ended up confusing my brain every time I would try to check the circuitry on my board. In addition, paying careful attention to the length of the wires on the soldered circuit is important. Since many of my components required branching away from the board, I needed longer wires. I tried to measure these out to be the same, and in the end I made them a little longer to be safe. However, it would have simplified the final soldered circuit if the wires were not too much longer than they needed to be. In addition, making sure to properly solder wires onto components and fixing everything with hot glue is crucial (and saves a lot of time re-soldering wires!).

Every time I added a component to the soldered circuit, I would test it using the Arduino code and printing to the Serial monitor. In the future it'll be useful to also test with a multimeter in parallel to double check everything is connected as expected. 

One thing I wouldn't do differently but will definitely remember to do again is to test any laser cutting design with cardboard before the actual material. It was by doing this that I realised the holes on my box were not the correct size and I was able to adjust before cutting acrylic, saving a lot of time and resources. 

### Future possibilities

If I had more time, it would be interesting to continue this project by doing the following:

1. I'd like to add more moods to the box, specifically options for feeling calm and increasing creativity.
2. It would be interesting to explore how sensors measuring the user could be used as input instead of buttons. The output of these sensors would determine which mood to emulate. For example, a galvanic skin response sensor could determine if the user is nervous and if so, react with focus or sleep to help them relax.
3. Making the neopixels update according to the mood, such as dimming for sleep and moving to the music for boost
4. Adding additional patterns onto the laser cut box (such as flowers) and experimenting with different materials 

## Final project video

https://git.arts.ac.uk/storage/user/650/files/28003eae-3e33-4367-a1b0-d38ffbd3a700



### Huge thank you to everyone at the CCI who advised and helped me along the way! 
