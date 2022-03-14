#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics.hpp>
#include "SceneNode.h"

using namespace sf;
class SpriteNode : public SceneNode
{
public:
	explicit SpriteNode(const Texture& texture);
	SpriteNode(const Texture& texture, const IntRect& textureRect);
	Sprite getSprite();

private:
	virtual void drawCurrent(RenderTarget& target, RenderStates states) const override;

private:
	Sprite sprite;
};