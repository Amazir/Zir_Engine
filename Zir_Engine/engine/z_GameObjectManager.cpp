#include "z_GameObjectManager.h"
#include <iostream>

GameObjectManager::GameObjectManager() {
	objects = new GameObject * [1];
	currentSize = 0;
}

GameObjectManager::~GameObjectManager() {
	delete objects;
}

void GameObjectManager::render() {
	for (int i = 0; i < currentSize; i++)
		objects[i]->render();
}

void GameObjectManager::update() {
	for (int i = 0; i < currentSize; i++)
		objects[i]->update();
}

void GameObjectManager::add(GameObject * obj) {
	obj->id = currentSize;
	objects[currentSize] = obj;
	std::cout << "adding " << currentSize << std::endl;
	currentSize++;
}

void GameObjectManager::del(GameObject* obj) {
	for (int i = 0; i < currentSize; i++)
		if (obj->id == objects[i]->id)
			delete objects[i];
}