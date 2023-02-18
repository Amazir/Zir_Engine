#include "Game.h"

using namespace std;

int main(int argc, char** args[]) {
	// Create new game in engine API
	Game * game = new Game();

	// Init game with data from config 
	game->init("Okienko", 300, 300, 800, 600, false);

	// TODO: Init -> constructor and getting config.

	// Main game loop
	while (game->isRunning()) {
		game->handle(); // Event handling
		game->update(); // Update function
		game->render(); // Rendering
	}
	game->destroy(); // Free up RAM

	return 0;
}