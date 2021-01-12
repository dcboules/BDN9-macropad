"# BDN9-macropad" 

I am working on this macro pad to solve a lot of minor inconveniences in my day to day experience.
Because it is only 9 keys, I made it so that there can be an infinite amount of options with the use 
of layers. It is indeed tricky to remember which key is on what layer since there are such limitless 
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


Here 
