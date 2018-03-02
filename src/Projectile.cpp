#include "Projectile.h"
#include "World.h"
#include "Config.h"


Projectile::Projectile() {
	setImage("textures/projectile.png");
	name = "Projectile";
	hasCollision = true;

	setVelocity(0, -1 * Config::playerProjectileSpeed);
}


Projectile::~Projectile() {
}

void Projectile::update() {
	Actor::update();

	if (location.y < 50) {
		world->deleteObject(this);
	}
}

void Projectile::collide(Actor* obj) {
	if (obj && world && obj->getName() == "Enemy") {
		world->deleteObject(this);
	}
}