#pragma once
#include <iostream>
#include "engine/z_GameObjectManager.h"
#include "engine/input/z_InputManager.h"
#undef main

using namespace std;

class Game
{
public:
	Game(); // Constructor
	~Game(); // Destructor

	// Init function for starting game engine
	void init(string title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handle(); // Function to handle events like keypress, etc.
	void update(); // Function which updates every tick
	void render(); // Renderer function
	void destroy();  // Cleaning renderer
	
	bool isRunning(); // Return private bool isRunning

private:
	bool running; // Private bool with current state of game running
	
	GameObjectManager* objManager; // Game object manager (updating, rendering, etc.)
	InputManager* inputManager; // Input manager (keydown, keyup, mouseclick, etc.)
	
	GameObject* player;

	SDL_Window* window; // Private window object
	SDL_Renderer* renderer; // Private renderer object
};

