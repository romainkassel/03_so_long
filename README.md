# 03_so_long

## Project overview

This project is a small 2D game and one of the first graphic project of 42 school.

Its purpose is to work with:
- textures,
- sprites,
- colors,
- window management,
- event handling,
- algorithms (pathfinding),
- and some other gameplay elements.

The main constraint was to use the MiniLibX, the 42 school graphical library.

This library was developed internally and includes basic necessary tools to open a window, create images and deal with keyboard and mouse events.

This is a 42 school project, the last one of the core curriculum.

This project focuses on the design, development and organisation of a complete web application.

## How to use this repository?

### Recommended Operating System (OS)

I recommand to use a Linux distribution such as:

- Latest stable version (LTS) of Ubuntu
- Latest stable version (LTS) of Debian

### Prerequisites

This project is using the MiniLibX, a graphical library mentionned above.<br/>
To build this project, you will have to clone and install it.<br/>
The steps will be described a little further.

### Steps to follow

1. Go to the directory where you want to clone the directory: `cd path/of/repository/`
2. Clone this repository: `git clone git@github.com:romainkassel/03_so_long.git`
3. Enter into cloned repository: `cd 03_so_long`
4. Clone the MiniLibX repository for Linux: `git clone https://github.com/42paris/minilibx-linux.git`
5. Enter into cloned repository: `cd minilibx-linux`
6. Build the MiniLibX: `make`
7. Return to the repository index: `cd ..`
8. Build the project: `make`
9. Run executable with a map as argument: `./so_long maps/map1.ber`
10. Here you go! If everything went smoothly, the following window handled by the MiniLibX should open:

<img width="1046" height="429" alt="so-long-2d-video-game" src="https://github.com/user-attachments/assets/93cd784d-5a7d-49ca-b50a-8ec2fb1280f9" />

## I tested the game and it's cool! Now I'd like to clean it up. What do I do?

1. Close the window by clicking on the cross at top right or by clicking on `CTRL + D` in your terminal
4. Go outside of the repository: `cd ..`
5. Remove the repository: `rm -rf 03_so_long`
