#ifndef TEXTUREHOLDER_H
#define TEXTUREHOLDER_H
#include <memory>
#include <map>
#include <string>
#include "SFML/Graphics.hpp"

enum class TextureID { Landscape, Airplane, Missile };

class TextureHolder
{
public:
	void load(TextureID id, const std::string& filename);
	const sf::Texture& get(TextureID id)const;

private:
	std::map <TextureID, std::unique_ptr<sf::Texture>> textureMap;
};
#endif