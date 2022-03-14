#ifndef TEXTNODE_H
#define TEXTNODE_H
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <string>
#include "SceneNode.h"
#include "ResourceIdentifier.h"
#include "ResourceHolder.h"
class TextNode : public SceneNode
{
public:
	TextNode(const FontHolder_t& fonts, const std::string& text);
	void setString(const std::string& text);

private:
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Text text;
};
#endif