#include "z_KeyEvent.h"

KeyEvent::KeyEvent(SDL_Keycode key, int t, void(*func)()) {
	keycode = key; // Set keycode
	fun = func; // Set function
	type = t; // Set type

}

void KeyEvent::exec() {(*fun)();} // Execute saved function

SDL_Keycode KeyEvent::getKeyCode() {return keycode;} // Getter for keycode