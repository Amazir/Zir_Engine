#include "z_KeyEvent.h"

class InputManager {
public:
	InputManager(); // Constructor
	~InputManager(); // Destructor

	void handle(SDL_Keycode, int type); // Function for handling events

	void addKeyPressEvent(KeyEvent*); // Function for adding new keyDown event
	void delKeyPressEvent(KeyEvent*); // Function for deleting keyDown event

private:
	int currentKeySize; // Current size of array keyEvents
	KeyEvent** keyEvents; // Array with all keyEvents to handle
};
/*
	TODO: del function, mouse click handling
*/