"# BDN9-macropad" 

I built this macro pad to solve a lot of minor inconveniences in my day to day computer experience.
Because it is only 9 keys, I had to brainstorm so that I could utilize those keys to do more than one
task. I wanted each set of macros to be used when I am using a corresponding program. For instance,
during the pandemic, all of my classes are on Zoom. I take notes in Microsoft OneNote. I use Adobe 
Photoshop, Discord, and Microsoft VS Code regularly. I decided to make 5 different profiles that can be
accessed at any time.

Starting with the top left, reading left to right the keys are numbered 1-8

It is indeed tricky to remember which key is on what layer since there are several different options,
and because of this I have it so that when the layer is changed, the background changes to its own 
designated color. 

The way it is made now, upon flashing is a layer with a yellow background color. Key 3 is White, Key 4 is Purple,
Key 5 is teal, Key 6 is dark blue, and Key 7 is orange. Key 8 is its own special case.

Key 8 always bound to mute and unmute on Discord. Assuming that Discord boots as unmuted, Key 8 is green 
indicating the mic is open, and when it is pressed again (to mute) the LED turns red. I bound it to the F24 
key, and set that as the keybind in Discord. (Used an incrementor and used % 2 ).

      I had actually tried to use the memory location in Discord to indicate where the mic was on 
      or off, but I came to realize that the memory location that I found from Discord changes each 
      time the computer turns on, so I had to scrap that work.

It is indeed tricky to remember which key is on what layer since there are several different options,
and because of this I have it so that when the layer is changed, the background changes to its own 
designated color. 


To set the Discord mute, go to the discord app after flashing, and set the keybind to do "Toggle Mute", 
then tap the key once.

To toggle the rotary encoder to deafen on press, do the same as line 34, but "Toggle Deafen."

Keys 0, 1, 2, 8 are constant.

The rotary encoder on key 0 is:
      Turn left for previous media.
      Turn right for next media.
      Press in for media Play/Pause.
      
Key 1:
      Go to the "Menu" layer.

The rotary encoder on key 2 is:
      Turn left for Discord output decrease.
      Turn right for Discord output increase.
      Press in for media Play/Pause.
      
I will only list keys 3,4,5,6,7 for each layer since the remaining are constant.
Layer 1:
            3:
            4:
            5:
            6:
            7:


