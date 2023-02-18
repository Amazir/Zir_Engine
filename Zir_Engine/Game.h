#pragma once
#include <iostream>
#include <SDL.h>
#undef main

using namespace std;

class Game
{
public:
	Game(); // Constructor
	~Game(); // Deconstructor

	// Init function for starting game engine
	void init(string title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handle(); // Function to handle events like keypress, etc.
	void update(); // Function which updates every tick
	void render(); // Renderer function
	void destroy();  // Cleaning renderer
	
	bool isRunning(); // Return private bool isRunning

private:
	bool running; // Private bool with current state of game running
	SDL_Window* window; // Private window object
	SDL_Renderer* renderer; // Private renderer object
};

