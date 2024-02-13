# So long

This project introduces us to MiniLibx. This library will be used in future projects as well.

[MiniLibX](https://github.com/42Paris/minilibx-linux) is a simple X-Window programming API created by 42.

We have to create a basic computer graphics project.

## Rules

The goal of the game is to collect all collectibles, and exit using the shortest path to the exit.

The arrow keys are used to move around. The four directions can be used, but of course, the player cannot move into walls.

At every move, the current number of movements is displayed in the shell.

To exit, the user can either press ESC or click on the cross on the window’s frame.

## Map validation

The first step was to validate the map given by the user.

Here are the rules that the map needs to follow:

• The map has to be constructed with 3 components: walls, collectibles, and free space.

• The map can be composed of only these 5 characters:
0 for an empty space,
1 for a wall,
C for a collectible,
E for a map exit,
P for the player’s starting position.

• The map must contain 1 exit, at least 1 collectible, and 1 starting position to
be valid.

• There must be a valid pass that allows the user to get all collectibles and then exit.

If one of the conditions is not met, an error message will be displayed.

You will find maps in the maps folder.

## How to play

• make

• ./so_long maps/map.ber

