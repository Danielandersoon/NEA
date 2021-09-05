#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include "Entity.hpp"

class Player : public Entity
{
private: 
	float m_xVel;
	float m_yVel;
public:
	Player(const std::string& textureFile, i_x, i_y, i_w, i_h);
};