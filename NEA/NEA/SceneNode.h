#ifndef SCENENODE_H
#define SCENENODE_H
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>
#include <vector>
#include <memory>
#include <set>
#include "Category.h"
#include "Command.h"
#include  "tempSettings.h"

//forward declaration
class CommandQueue;

using namespace sf;
class SceneNode : public Transformable, public Drawable, private NonCopyable
{
public:
	using Ptr = std::unique_ptr<SceneNode>;
	using Pair = std::pair<SceneNode*, SceneNode*>;

public:
	SceneNode(Category::Type c = Category::Type::None);
	void attachChild(Ptr child);
	Ptr	detachChild(const SceneNode& node);
	virtual FloatRect getBoundingRect() const;
	void update(Time dt, CommandQueue& commands);
	Vector2f getWorldPosition() const;
	Transform getWorldTransform() const;
	void onCommand(const Command& command, Time dt);
	virtual unsigned int getCategory() const;
	virtual bool isDestroyed() const;
	virtual bool isMarkedForRemoval()const;
	void checkNodeCollision(SceneNode& node, std::set<Pair>& collisionPairs);
	void checkSceneCollision(SceneNode& sceneGraph, std::set<Pair>& collisionPairs);
	void removeWrecks();

private:
	virtual void updateCurrent(Time dt, CommandQueue& commands);
	void updateChildren(Time dt, CommandQueue& commands);
	virtual void draw(RenderTarget& target, RenderStates states) const;
	virtual void drawCurrent(RenderTarget& target, RenderStates states) const;
	void drawChildren(RenderTarget& target, RenderStates states) const;
	void drawBoundingRect(RenderTarget& target, RenderStates states)const;

private:
	std::vector<Ptr> children;
	SceneNode* parent;
	Category::Type defaultCategory;

};
float calculateDistance(const SceneNode& lhs, const SceneNode& rhs);
bool IsColliding(const SceneNode& lhs, const SceneNode& rhs);
#endif