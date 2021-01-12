"# BDN9-macropad" 

***DISCLAIMER, if the file looks to be unreadable, press the button on the top right that says "raw". ***

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

Here is how the macro pad works:

First layer: (MENU LAYER)
///-------------------------+-------------------------+-------------------------\
//|  <- turn knob left      |                         |   <- turn knob left     |
//|    (Previous Media)     |                         |(Decrease Discord Output)|
//|                         |     Press this for      |                         |
//|    + Press on knob      |       MENU LAYER        |    + Press on knob      |
//|    (Play/Pause Media)   |     (MULTICOLORED)      |(Deafen/Undeafen Discord)|
//|                         |                         |                         |
//|  -> turn knob right     |                         |  -> turn knob right     |
//|      (Next Media)       |                         |(Increase Discord Output)|
//|-------------------------+-------------------------+-------------------------|
//|                         |                         |                         |
//|                         |                         |                         |
//|      Press this for     |     Press this for      |     Press this for      |
//|        ZOOM Layer       |      ONENOTE Layer      |      CODING Layer       |
//|         (WHITE)         |         (PURPLE)        |         (TEAL)          |
//|                         |                         |                         |
//|                         |                         |                         |
//|                         |                         |                         |
//|-------------------------+-------------------------+-------------------------|
//|                         |                         |                         |
//|                         |                         |                         |
//|     Press this for      |      Press this for     |   Press to mute (Red)   |
//|     PHOTOSHOP Layer     |       STREAM Layer      |    And press again to   |
//|          (BLUE)         |         (ORANGE)        |      Unmute (Green)     |
//|                         |                         |                         |
//|                         |                         |                         |
//|                         |                         |                         |
//\-----------------------------------------------------------------------------/
Second layer: (ZOOM LAYER)
///-------------------------+-------------------------+-------------------------\
//|  <- turn knob left      |                         |   <- turn knob left     |
//|    (Previous Media)     |                         |(Decrease Discord Output)|
//|                         |     Press this for      |                         |
//|    + Press on knob      |       MENU LAYER        |    + Press on knob      |
//|    (Play/Pause Media)   |     (MULTICOLORED)      |(Deafen/Undeafen Discord)|
//|                         |                         |                         |
//|  -> turn knob right     |                         |  -> turn knob right     |
//|      (Next Media)       |                         |(Increase Discord Output)|
//|-------------------------+-------------------------+-------------------------|
//|                         |                         |                         |
//|                         |                         |                         |
//|   Press to mute/unmute  |     Press to toggle     |                         |
//|   ZOOM mic (GREEN/RED)  |   ZOOM cam (GREEN/RED)  |     ZOOM CHAT ON/OFF    |
//|         (ALT-A)         |         (ALT-V)         |         (ALT-H)         |
//|                         |                         |                         |
//|                         |                         |                         |
//|                         |                         |                         |
//|-------------------------+-------------------------+-------------------------|
//|                         |                         |                         |
//|                         |                         |                         |
//|                         |                         |   Press to mute (Red)   |
//|       OPEN WEBSITE      |      OPEN ONENOTE       |    And press again to   |
//|                         |                         |      Unmute (Green)     |
//|                         |                         |                         |
//|                         |                         |                         |
//|                         |                         |                         |
//\-----------------------------------------------------------------------------/
Third layer: (ONENOTE LAYER)
///-------------------------+-------------------------+-------------------------\
//|  <- turn knob left      |                         |   <- turn knob left     |
//|    (Previous Media)     |                         |(Decrease Discord Output)|
//|                         |     Press this for      |                         |
//|    + Press on knob      |       MENU LAYER        |    + Press on knob      |
//|    (Play/Pause Media)   |     (MULTICOLORED)      |(Deafen/Undeafen Discord)|
//|                         |                         |                         |
//|  -> turn knob right     |                         |  -> turn knob right     |
//|      (Next Media)       |                         |(Increase Discord Output)|
//|-------------------------+-------------------------+-------------------------|
//|                         |                         |                         |
//|                         |                         |                         |
//|                         |                         |                         |
//|    ONENOTE LASSO TOOL   |          UNDO           |    ZOOM VIDEO ON/OFF    |
//|     (ALT-D, L, ENTER)   |         (CTR-Z)         |         (PG-DN)         |
//|                         |                         |                         |
//|                         |                         |                         |
//|                         |                         |                         |
//|-------------------------+-------------------------+-------------------------|
//|                         |                         |                         |
//|                         |                         |                         |
//|                         |                         |   Press to mute (Red)   |
//|    ONENOTE PEN TOOL     |   ONENOTE ERASER TOOL   |    And press again to   |
//|    (ALT-D, P, ENTER)    |      (ALT-D, E, M)      |      Unmute (Green)     |
//|                         |                         |                         |
//|                         |                         |                         |
//|                         |                         |                         |
//\-----------------------------------------------------------------------------/
Fourth layer: (CODING LAYER)
///-------------------------+-------------------------+-------------------------\
//|  <- turn knob left      |                         |   <- turn knob left     |
//|    (Previous Media)     |                         |(Decrease Discord Output)|
//|                         |     Press this for      |                         |
//|    + Press on knob      |       MENU LAYER        |    + Press on knob      |
//|    (Play/Pause Media)   |     (MULTICOLORED)      |(Deafen/Undeafen Discord)|
//|                         |                         |                         |
//|  -> turn knob right     |                         |  -> turn knob right     |
//|      (Next Media)       |                         |(Increase Discord Output)|
//|-------------------------+-------------------------+-------------------------|
//|                         |                         |                         |
//|                         |                         |                         |
//|                         |                         |                         |
//|          Types          |          Types          |          Types          |
//|        "git push"       |        "git pull"       |       "#include <>"     |
//|                         |                         |                         |
//|                         |                         |                         |
//|                         |                         |                         |
//|-------------------------+-------------------------+-------------------------|
//|                         |                         |                         |
//|                         |                         |                         |
//|   Copies a screenshot   |        Prints my        |   Press to mute (Red)   |
//|     to a clipboard      |         USERNAME        |    And press again to   |
//|      (WIN+SHFT+S)       |                         |      Unmute (Green)     |
//|                         |                         |                         |
//|                         |                         |                         |
//|                         |                         |                         |
//\-----------------------------------------------------------------------------/
Fifth layer: (PHOTSHOP LAYER)
///-------------------------+-------------------------+-------------------------\
//|  <- turn knob left      |                         |   <- turn knob left     |
//|    (Previous Media)     |                         |(Decrease Discord Output)|
//|                         |     Press this for      |                         |
//|    + Press on knob      |       MENU LAYER        |    + Press on knob      |
//|    (Play/Pause Media)   |     (MULTICOLORED)      |(Deafen/Undeafen Discord)|
//|                         |                         |                         |
//|  -> turn knob right     |                         |  -> turn knob right     |
//|      (Next Media)       |                         |(Increase Discord Output)|
//|-------------------------+-------------------------+-------------------------|
//|                         |                         |                         |
//|                         |                         |                         |
//|                         |                         |                         |
//|   Decreases tool size   |   Decreases tool size   |     Step backwards      |
//|      (Left Bracket)     |     (Right Bracket)     |      (CTRL+ALT+Z)       |
//|                         |                         |                         |
//|                         |                         |                         |
//|                         |                         |                         |
//|-------------------------+-------------------------+-------------------------|
//|                         |                         |                         |
//|                         |                         |                         |
//|   Activates Brush Tool  |  Activates Eraser Tool  |   Press to mute (Red)   |
//|           (B)           |            (E)          |    And press again to   |
//|                         |                         |      Unmute (Green)     |
//|                         |                         |                         |
//|                         |                         |                         |
//|                         |                         |                         |
//\-----------------------------------------------------------------------------/
