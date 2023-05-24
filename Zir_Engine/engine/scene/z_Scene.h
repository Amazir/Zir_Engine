#pragma once
class Scene {
public:
	// Constructor takes argument with path to texture and SDL_Renderer object
	Scene();
	~Scene() {} // Destructor

	void render(); // Function for rendering scene
	void handle(); // Function for handling key events (unique for each scene)

	int id; // Unique ID number

private:

};