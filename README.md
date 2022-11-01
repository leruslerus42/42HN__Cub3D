# 42__Cub3D

## DESCRIPTION
Cub3d is a game in 3D implemented by using the ray-casting algorithm.
The goal of this project is to display a dynamic first-person view of a player, moving on a map.





## GRAPHIC 
![Screen Shot 2022-11-01 at 8 00 39 AM](https://user-images.githubusercontent.com/85942176/199177908-620b65ee-7652-4d7c-a9c7-3534583d6666.png)





## RULES
- The management of the window (changing to another window, minimizing, etc.) must remain smooth.
- Depending on which geographic direction a wall is facing (N, S, E, W), it must display a diffeen wall texture.
- Pressing ESC or clicking on the red cross on the window's frame must close the window and quit the program cleanly.
- The map must be composed of only 6 possible characters: 0 for an empty space, 1 for a wall, and N,S,E or W for the player’s start position and spawning orientation.
- The map must be surrounded by walls.
- The map must be parsed as it looks in the file. Spaces are a valid part of the map and are up to you to handle. You must be able to parse any kind of map, as long as it respects the rules of the map.


## CONTROLS
- W - Move forwards
- A - Move left
- S - Move backwards
- D - Move right
- ARROW LEFT - Turn left
- ARROW RIGHT - Turn right
- ESC - Exit game


## NORMINETTE

As all other C projects at the 42 school, the code has to written in accordance with the norm:
- only 25 lines per function
- only 5 functions per file
- the only predefined functions allowed for this project are: open, close, read, write, printf, malloc, free, perror, strerror, exit plus all the functions of the math and miniLibx Library.


## RESULT

<img width="846" alt="Screenshot 2022-11-01 at 07 39 32" src="https://user-images.githubusercontent.com/85942176/199187516-05b3fe47-b28a-4b8d-b292-291c1763b2b8.png">





