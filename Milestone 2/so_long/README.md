*This project has been created as part of the 42 curriculum by kzhu.*

# So_long

## Description

The goal was to build a small 2D game built in C using the MiniLibx graphics Library, the goal of the project is to learn how to parise the map, complete game loop, handle window management, player movement and render .xpm textures.

## Instructions

Maps are parsed from a .ber file. The file must strictly contain the following characters:
    0 - Empty space (Floor)
    1 - Wall
    C - Collectible
    E - Map Exit
    P - Player Starting Position.

1. it requires the MiniLibX library and need to rename the folder to xlm;
2. after use the make command, excuese the game in this exact form "./so_long <map>.ber";
3. after the gamp is loaded, the player has to navigate the map with "WASD" keys, and collect every single item, then reach the exit.
4. after completing the game, the total steps will be shown.


## Resources & AI Usage

References

*MiniLibX introduction (to kick off and understand the meaning of the Library) https://harm-smits.github.io/42docs/libs/minilibx
*Introduction to the minilibX : a simple X-Window programming API in C (see how those function in use) https://www.youtube.com/watch?v=bYS93r6U0zg&t=1878s
AI Usage

I used AI assistance (Gemini) during this project for the following specific tasks:
*Conceptual Breakdown: Clarifying complex C concepts, such as double pointer memory layouts and X11 event hooks.
*Troubleshooting: Pinpointing infinite loops, resolving Makefile relinking issues, and explaining strict Norminette formatting rules (like control structure assignments).