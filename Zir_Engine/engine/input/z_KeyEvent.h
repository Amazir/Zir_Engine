#include <SDL.h>
#pragma once

class KeyEvent {
public:
	// Constructor takes KeyCode, type (definition below), and function to exec
	KeyEvent(SDL_Keycode, int, void(*func)());
	~KeyEvent(); // Destructor

	void exec(); // Function to execute when event occures

	SDL_Keycode getKeyCode(); // Getter for keycode

	/*
		type definition:
		0 - press (keydown)
		1 - release (keyup)
	*/
	int type;

private:
	SDL_Keycode keycode; // Code of our key
	typedef void (*function)(); // Type of function to execute with event
	function fun; // Function to execute with event
};