#include <iostream>
#include <fstream>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

//global variables
int windowWidth = 1440;
int windowHeight = 900;
int frameRate = 60;
float G = 1.8f;
float maxG = 19.f;
float jumpHeight = windowHeight * 0.045f;
int playerIdleCount = 0;
int playerWalkCount = 0;
int playerIdleFrames = 2;
int playerWalkFrames = 6;
int playerIdleSpeed = 9;
int playerWalkSpeed = 7;

class playerClass
{
public:
	bool onGround;
	bool playerDirectionRight;
	float xCoordinate;
	float yCoordinate;
	float xVel = 0; 
	float yVel = 0;
	float groundHeight = 550;
	

	playerClass()
	{
		playerDirectionRight = true;
		xCoordinate = windowWidth * 0.033f;
		yCoordinate = windowHeight * 0.61f;
	
		sf::Vector2f FrameSize, frameCount;
		std::vector<sf::IntRect> frames;
	}

	void update(bool playerDown, bool playerLeft, bool playerRight, bool playerJump, bool playerPunch1, bool playerPunch2, bool playerKick1, bool playerKick2, bool playerBlock)
	{
		//std::cout << playerPunch1;
		
		if (playerRight)
		{
			playerDirectionRight = true;
			xVel = windowWidth * 0.0035f;
		}

		if (playerLeft)
		{
			playerDirectionRight = false;
			xVel = -0.0035f * windowWidth;
		}

		if (playerJump && onGround)
		{
			yVel = jumpHeight * -1;
		}

		if (onGround == false)
		{
			yVel += G;
				if (yVel > maxG) yVel = maxG;
		}


		if (!(playerRight || playerLeft))
		{
			xVel = 0;
		}

		xCoordinate += xVel;
		yCoordinate += yVel;
	};

	void collide()
	{
		if (yCoordinate > groundHeight)
		{
			onGround = true;
			yVel = 0;
		}
		else
		{
			onGround = false;
		}

		if (xCoordinate < 0)
		{
			xVel = 0;
		}

		if (yCoordinate > (windowWidth - 70)) 
		{
			xVel = 0;
		}
	}
	
};


using namespace sf;
int main()
{
	//create render window
	RenderWindow app(VideoMode(windowWidth, windowHeight), "game window");
	app.setFramerateLimit(frameRate);

	bool playerDown, playerLeft, playerRight, playerJump, playerPunch1, playerPunch2, playerKick1, playerKick2, playerBlock = false;
	playerClass playerOBB;

	Texture playerTexture;
	playerTexture.loadFromFile("data/sprites/player 1 characters/fighter 1 spritesheet.png");
	Sprite playerSprite(playerTexture);
	IntRect spriteRect(0, 0, 64, 64);
	playerSprite.setTextureRect(spriteRect);

	Clock gamesClock;

	//initiate game loop
	while (app.isOpen()) {

		//process events
		Event event;
		while (app.pollEvent(event))
		{
			// close the window 
			if (event.type == Event::Closed)
				app.close();
		}

		//check for key inputs
		if (Keyboard::isKeyPressed(Keyboard::Right))
			playerRight = true;
		if (Keyboard::isKeyPressed(Keyboard::Left))
			playerLeft = true;
		if (Keyboard::isKeyPressed(Keyboard::Up))
			playerJump = true;
		if (Keyboard::isKeyPressed(Keyboard::Down))
			playerDown = true;
		if (Keyboard::isKeyPressed(Keyboard::A))
			playerPunch1 = true;
		if (Keyboard::isKeyPressed(Keyboard::S))
			playerKick1 = true;
		if (Keyboard::isKeyPressed(Keyboard::Q))
			playerPunch2 = true;
		if (Keyboard::isKeyPressed(Keyboard::W))
			playerKick2 = true;
		if (Keyboard::isKeyPressed(Keyboard::LShift))
			playerBlock = true;

		//check for lack of inputs
		if (!(Keyboard::isKeyPressed(Keyboard::Right)))
			playerRight = false;
		if (!(Keyboard::isKeyPressed(Keyboard::Left)))
			playerLeft = false;
		if (!(Keyboard::isKeyPressed(Keyboard::Up)))
			playerJump = false;
		if (!(Keyboard::isKeyPressed(Keyboard::Down)))
			playerDown = false;
		if (!(Keyboard::isKeyPressed(Keyboard::A)))
			playerPunch1 = false;
		if (!(Keyboard::isKeyPressed(Keyboard::S)))
			playerKick1 = false;
		if (!(Keyboard::isKeyPressed(Keyboard::Q)))
			playerPunch2 = false;
		if (!(Keyboard::isKeyPressed(Keyboard::W)))
			playerKick2 = false;
		//idle animations
		if (playerOBB.onGround && !((Keyboard::isKeyPressed(Keyboard::Right)) || (Keyboard::isKeyPressed(Keyboard::Left)) || (Keyboard::isKeyPressed(Keyboard::Up)) || (Keyboard::isKeyPressed(Keyboard::Down)) || (Keyboard::isKeyPressed(Keyboard::A)) || (Keyboard::isKeyPressed(Keyboard::S)) || (Keyboard::isKeyPressed(Keyboard::Q)) || (Keyboard::isKeyPressed(Keyboard::W))) )
		{
			if (gamesClock.getElapsedTime().asMilliseconds() > 500.f)
			{
				if (spriteRect.left == 0)
				{
					spriteRect.left = 64;
				}
				else
					spriteRect.left = 0;
		 		playerSprite.setTextureRect(spriteRect);
				gamesClock.restart();
			}
		}
		
		playerOBB.update(playerDown, playerLeft, playerRight, playerJump, playerPunch1, playerPunch2, playerKick1, playerKick2, playerBlock);

		playerOBB.onGround = false;
		playerOBB.collide();

		//cls
		app.clear();

		//drawing
		
		// update window
		app.draw(playerSprite);
		playerSprite.setPosition(playerOBB.xCoordinate, playerOBB.yCoordinate);
		playerSprite.setScale(5.f, 5.f);
		
		app.display();


	}
	return 0;
};
