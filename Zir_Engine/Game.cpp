#include "Game.h"

using namespace std;

Game::Game() {}
Game::~Game(){}

bool Game::isRunning() {return running;}

void moveLeft() {
	cout << "moving left" << endl;
}


void Game::init(string title, int x, int y, int width, int height, bool fullscreen) {
	/*

		INITIALIZE
		Function for initializing objects for our engine to handle

	*/

	// Default we are using no flags
	int flags = 0;
	
	// If fullscreen enabled in config, set flags for fullscreen
	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;

	// Init SDL and check if it's sucessfull
	if (!SDL_Init(SDL_INIT_EVERYTHING)) {
		cout << "ZirEngine initializing..." << endl;

		// Create window
		window = SDL_CreateWindow(title.c_str(), x, y, width, height, flags);
		if (window)
			cout << "Window created." << endl;

		// Create renderer for window
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
			cout << "Renderer created." << endl;
		
		// Synchronize bool with state
		running = true;
	
		// Initialize game object manager and input manager
		objManager = new GameObjectManager();
		inputManager = new InputManager();

		KeyEvent* e = new KeyEvent(SDLK_0, 0, &moveLeft);
		inputManager->addKeyPressEvent(e);
		//delete e;

		player = new GameObject("assets/player/player.png", renderer);
		objManager->add(player);
	}
	else
		// Synchronize bool with state
		running = false;
}

void Game::handle() {
	/*
	
		EVENT HANDLING
		Handling keypresses, mouse presses and windows events

	*/

	// Create SDL handler object
	SDL_Event e;
	
	// Initialize 
	SDL_PollEvent(&e);

	switch (e.type) {
		// Check if SDL quits with error
	case SDL_QUIT:
		// Synchronize bool with state
		running = false;
		break;

	case SDL_KEYDOWN:
		inputManager->handle(e.key.keysym.sym, 0);
		break;

		// Default option
	default:
		/* Empty function because we want use
		it only when handler for it is declared */
		break;
	}
}

void Game::update() {
	/*

		UPDATE
		Function for some stuff witch needs to be handled every tick

	*/

	objManager->update();
}

void Game::render() {
	/*

		RENDERER
		Function for rendering objects on screen

	*/

	// Clear renderer
	SDL_RenderClear(renderer);

	objManager->render();

	// Render current renderer
	SDL_RenderPresent(renderer);
}

void Game::destroy() {
	/*

		DESTROY / CLEAR
		Function for freeing up some RAM space after quiting program.

	*/

	// Destroy window object
	SDL_DestroyWindow(window);

	// Destroy renderer object
	SDL_DestroyRenderer(renderer);

	// Quit SDL
	SDL_Quit();
}