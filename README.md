# Pong

## Description :smile:
This is a Capstone project for the Udacity C++ Nanodegree Program.

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

The game was designed using C++ language and the Raylib library. 

Pong is a table tennis–themed twitch arcade sports video game, featuring simple two-dimensional graphics, manufactured by Atari and originally released in 1972. It was one of the earliest arcade video games; it was created by Allan Alcorn as a training exercise assigned to him by Atari co-founder Nolan Bushnell, but Bushnell and Atari co-founder Ted Dabney were surprised by the quality of Alcorn's work and decided to manufacture the game

![GIF](/pong.gif)

## Project Rubric Satisfaction  	:open_book:
This Galaga project addresses the following rubric points for the Udacity capstone project.

1. This README file.

2. Code compiles and runs using the the process specified below.

3. Satisfies at least 5 total criteria from the rest of the rubric, specifically:

	(1). Project demonstrates an understanding of C++ functions and control structures:			
          
	* There are numerous function and control examples, including method functions in Game.cpp at lines 50, 84, etc.

	(2). All class data members are explicitly specified as public, protected, or private:
	
	* All header files have private and public class data members. Example in Game.h starting at line 14.

	(3). The project accepts user input and processes the input:
	
	* Pong uses keyboard inputs to control the different player's paddle in Game.cpp at lines 149 - 180.

	(4). The project uses Object Oriented Programming techniques:
	* There are many examples of OOP techniques, including the padlle & ball classes and methods in Game.h.

	(5). The project uses destructors appropriately:
	* There is an example of this in Game.cpp at line 3.


## Dependencies for Running Locally :paperclips:
You will need to download raylib to run this game.

### installing and building raylib via vcpkg
  git clone https://github.com/Microsoft/vcpkg.git
  cd vcpkg
  bootstrap-vcpkg.bat
  vcpkg integrate install
  vcpkg install raylib

  ### or
  
  use the link below to find videos showing you how to download raylib.
  https://www.bing.com/videos/riverview/relatedvideo?&q=install%20raylib%20windows&mid=8A4E4F902D78255510BE8A4E4F902D78255510BE&ajaxhist=0

## Basic Build Instructions :page_facing_up:
1. Clone this repo
2. Ensure raylib is installed and added
3. debug Capstone.vcxproj using DebugWin32
![debug](/Screenshots/debug.jpg) 
### or

1. Clone this repo
2. Ensure raylib is installed and added

3. Build  <mark> Capstone.vcxproj </mark>

![build](/Screenshots/build.jpg) 

4. cd into <mark> .\Capstone\Debug\ </mark>

![cd](/Screenshots/cd.jpg) 

5. Run it: <mark> .\Capstone.exe </mark>

![exe](/Screenshots/exe.jpg) 

## Controls :joystick:
### How to Play? :game_die:

![Play](/Screenshots/Play.jpg) 

### Action Keys!  :trophy:

![Action](/Screenshots/Action.jpg)

## Screenshots
### Start :game_die:
![START](/Screenshots/Start.jpg)

### Red Wins! 	:upside_down_face:
![Red](/Screenshots/Start.jpg)

### Green Wins! 		:grin:
![Red](/Screenshots/Start.jpg)