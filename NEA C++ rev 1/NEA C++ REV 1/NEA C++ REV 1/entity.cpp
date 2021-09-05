#include <SFML/Graphics.hpp>
#include "Entity.hpp"

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform = m_transform;
	states.texture = &m_texture;

	target.draw(m_verticies, states);
};