#pragma once

#include "ofMain.h"
#include "Actor.h"

class Timer;

// World
// Manages and draws the scene
//
class World {
public:
	World();
	~World();

	// Called every frame, draws all objects in the scene
	void draw();

	void updateCollision();

	// Adds an object to the scene for rendering
	Actor* addObject(Actor*);

	// Removes an object from the scene and deletes it
	void deleteObject(Actor*);

	// Get time between frames
	float getDeltaTime();

	// Log scene contents to console
	void logScene();

	Timer* timer;

	// Score actions
	void incrementScore();
	int getScore();

private:
	// Holds all the objects we need to render
	vector<Actor*> scene;

	// Objects scheduled for addition
	vector<Actor*> toAdd;

	// Objects scheduled for deletion
	vector<Actor*> toDelete;

	// Immediately adds an object from the scene
	Actor* unsafeAddObject(Actor*);

	// Immediately removes an object from the scene
	bool unsafeDeleteObject(Actor*);

	// Time between frames
	float deltaTime;

	// How many players were killed
	int score;
};