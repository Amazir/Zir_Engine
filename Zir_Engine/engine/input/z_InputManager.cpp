#include "z_InputManager.h"
#include <iostream>

InputManager::InputManager() {
	// Create array with keyboard events
	keyEvents = new KeyEvent * [1];
	
	// Init array size variable
	currentKeySize = 0;
}

InputManager::~InputManager() {
	// Clear RAM
	delete keyEvents;
}

void InputManager::addKeyPressEvent(KeyEvent* obj) {
	/* Function for adding new key press(key down) event
	 
	   Setting type for key down*/
	obj->type = 0; 

	// Adding new object into our array
	keyEvents[currentKeySize] = obj; 

	// Increasing amount of current handled keydown events
	currentKeySize++; 
}

void InputManager::handle(SDL_Keycode e, int type) {
	// Update function for handling events
	switch (type) {
		// If type equals keydown type
		case 0: 
			// Loop for all key events
			for (int i = 0; i < currentKeySize; i++) 
				// Check if type of analyzed object is keydown
				if (!keyEvents[i]->type) 
					// Check if keycode is matching
					if(keyEvents[i]->getKeyCode() == e) 
						// Execute key function
						keyEvents[i]->exec(); 
		break;

		// Default option
		default:
			/* Empty function because we want use
			it only when handler for it is declared */
			break;
	}
}