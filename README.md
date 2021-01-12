"# BDN9-macropad" 

***DISCLAIMER, if the file looks to be unreadable, press the button on the top right that says "raw". ***

I built this macro pad to solve a lot of minor inconveniences in my day to day computer experience.
Because it is only 9 keys, I had to brainstorm so that I could itilize those keys to do more than one
task. I wanted each set of macros to be used when I am using a corresponding program. For instance,
during the pandemic, all of my classes are on Zoom. I take notes in Microsoft OneNote. I use Adobe 
Photoshop, Discord, and Microsoft VS Code regularly. I decided to make 5 different profiles that can be
accessed at any time.

Starting with the top left, reading left to right the keys are numbered 1-8

The way it is made now, upon flashing is a layer with a yellow background color. Key 3 is White, Key 4 is Purple,

for nowcert way when I b It is indeed tricky to remember which key is on what layer since there are such limitless 
options, and because of this I have it so that when the layer is changed, the background has its own 
designated color. It is also coded so that the bottom right key is Discord mute/unmute, and the RGB 
is green when the mic is open, and red when it is muted. I managed to locate the memory address that
indicates the change in value when the app is muted or unmuted, but I ended up realizing that the memory
address changes every time the computer restarts. Since this attempt was unsuccessful, I changed the
logic so that each time the button is pressed, it is counted, and then if it is divisible by two, the 
color is green, and if it isn't the color is red.

To set the Discord mute, go to the discord app after flashing, and set the keybind to do "Toggle Mute", 
then tap the key once.

To toggle the rotary encoder to deafen on press, do the same as line 10, but "Toggle Deafen."


