#ifndef ENTITY_H
#define ENTITY_H
#include "SceneNode.h"

using namespace sf;
class Entity : public SceneNode
{
public:
	Entity(int hitPoints);
	void setVelocity(Vector2f v);
	void setVelocity(float xv, float yv);

	void accelerate(Vector2f v);
	void accelerate(float xv, float yv);


	Vector2f getVelocity() const;

	int	getHitpoints() const;
	void repair(int points);
	void damage(int points);
	void destroy();
	virtual bool isDestroyed() const;

protected:
	virtual void updateCurrent(Time dt, CommandQueue& commands) override;

private:
	Vector2f velocity;
	int hitPoints;
};
#endif