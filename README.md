# Hack Piano

A macropad, in the form of a piano!

It can serve as a normal macropad too.

Made through [Hackpad](https://hackpad.hackclub.com/) and Stardance, hosted by [Hackclub](https://hackclub.com/)!

[Showcase](https://youtu.be/vqTRjgcmdTU)

<img src=assets\FINAL.jpg width="500" />

## Motivation

I've wanted a MIDI keyboard for a while, and I thought this would be a decent substitute (and a fun challenge!).

This is my first ever hardware project I've made from start to finish, with my own design, so It's very exciting!

I'm hoping to use the skills from this project in others, like my WIP 3d camera (shameless plug)

## Features

 - 12 MX-style keys arranged like a piano
 -  programmable rotary encoder
 - 0.91" OLED screen

## Schematic & PCB

<img src=assets\schem_done_actually.png alt="Schematic" width="500"/>

It was difficult to align everything so the traces are nice, especially since I was forced to wire the keys in a 4x3 grid because of the number of pins

Another BIG problem was that the pcb was too wide. I decided to split the pcb in half and stack the two halves together to get the size requirements, then add breakpoints so I could assemble and solder the pcb together. Thanks to Anicetus in the hackclub slack for the idea!

[![View PCB on KiCanvas](https://hack.club/pcb-badge)](https://kicanvas.org/?repo=https%3A%2F%2Fgithub.com%2FAlex-SJuice%2FHack-Piano%2Ftree%2Fmain%2Fpcb%2FHackpiano_pcb)

<img src=assets\pcb_done_frfr.png alt="PCB" width="500" />

Final Shape:

<img src=assets\pcb_after_soldering.png width="500" />

## Case

Oh my goodness, the case was actually horrible to work on. It mostly stems from the fact that I decided to make a bunch of small details that would be really annoying to change if say, the lid and base were different shapes the entire time. Also someone's got to burn the Onshape splines on a stake.

<img src=assets\case_only.png width="500" />

## BOM:
 - 12x Cherry MX Switches
 - 12x DSA Keycaps (optional but you can get 2u keys for the bottoms 7)
 - 4x M3x5x4 Heatset inserts
 - 4x M3x16mm screws
 - 12x 1N4148 DO-35 Diodes
 - 1x 0.91" 128x32 OLED Display
 - 1x EC11 Rotary Encoder
 - 1x XIAO RP2040
 - 1x Case (2 printed parts)


