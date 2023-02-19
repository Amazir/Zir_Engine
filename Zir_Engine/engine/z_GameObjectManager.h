#include "z_GameObject.h"
#pragma once

class GameObjectManager {
public:
	GameObjectManager();
	~GameObjectManager();

	void render();
	void update();

	void add(GameObject*); // Function for adding GameObjects into the loop
	void del(GameObject*); // Function for deleting GameObjects from loop

	void updateObjectArray(GameObject**); // Function for re-creating game object array
private:
	int currentSize;
	GameObject** objects; // Array with all game objects
};