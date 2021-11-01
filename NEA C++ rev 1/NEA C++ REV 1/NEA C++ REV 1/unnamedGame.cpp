#include <iostream>
#include <fstream>
#include <vector>
#include <complex>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

//global variables
//window settings
int windowWidth = 1440;
int windowHeight = 900;
int frameRate = 60;
int AA = 0;
bool vsync = false;
bool quality = false;

//game constants
float G = 1.8f;
float maxG = 19.f;
float jumpHeight = windowHeight * 0.045f;
float groundHeight = 0.389f * windowHeight;
int playerIdleCount = 0;
int playerWalkCount = 0;
int playerIdleFrames = 2;
int playerWalkFrames = 6;
int playerIdleSpeed = 9;
int playerWalkSpeed = 7;
int spriteWidth = 64;
int spriteHeight = 64;
int damageThreshold = 15;


//create render window
sf::RenderWindow app(sf::VideoMode(windowWidth, windowHeight), "game window");

class characterClass
{
public:
	bool onGround;
	bool directionRight;
	float xCoordinate;
	float yCoordinate;
	int hitboxWidth;
	int hitboxHeight;
	float xVel;
	float yVel;
	float hitboxLeft;
	float hurtboxLeft;
	float collisionboxLeft;
	int HP;

	sf::Sprite sprite;
	//std::string spriteDirectory;
	//sf::Texture spriteTexture;
	sf::IntRect spriteRect;
	sf::IntRect hitbox;
	sf::IntRect hurtbox;

	void obtainSprite();
	void inputPolling();
	void update();
	void collide();
	void initiateCharacterClass();
};

using namespace sf;
void characterClass::initiateCharacterClass()
{
	HP = 100;
	xVel = 0;
	yVel = 0;
	directionRight = true;
	xCoordinate;
	yCoordinate;
	onGround = false;	
	hitboxHeight = 5;
	hitboxWidth = 10;

	IntRect hitbox(0, 0, hitboxWidth, hitboxHeight);
	IntRect hurtbox(0, 0, spriteWidth, spriteHeight);
};

using namespace sf;
void characterClass::obtainSprite()
{
	Texture texture;
	texture.loadFromFile("data/sprites/player 1 characters/fighter 1 spritesheet.png");
	Sprite sprite(texture);
	IntRect spriteRect(0, 0, spriteWidth, spriteHeight);
	sprite.setTextureRect(spriteRect);
};

using namespace sf;
void characterClass::inputPolling()
{
	Clock gamesClock;

	bool down = false;
	bool left = false;
	bool right = false;
	bool jump = false;
	bool punch1 = false;
	bool punch2 = false;
	bool kick1 = false;
	bool kick2 = false;
	bool block = false;

	//check for key inputs
	if (Keyboard::isKeyPressed(Keyboard::Right))
		right = true;
	if (Keyboard::isKeyPressed(Keyboard::Left))
		left = true;
	if (Keyboard::isKeyPressed(Keyboard::Up))
		jump = true;
	if (Keyboard::isKeyPressed(Keyboard::Down))
		down = true;
	if (Keyboard::isKeyPressed(Keyboard::A))
		punch1 = true;
	if (Keyboard::isKeyPressed(Keyboard::S))
		kick1 = true;
	if (Keyboard::isKeyPressed(Keyboard::Q))
		punch2 = true;
	if (Keyboard::isKeyPressed(Keyboard::W))
		kick2 = true;
	if (Keyboard::isKeyPressed(Keyboard::LShift))
		block = true;

	//check for lack of inputs
	if (!(Keyboard::isKeyPressed(Keyboard::Right)))
		right = false;
	if (!(Keyboard::isKeyPressed(Keyboard::Left)))
		left = false;
	if (!(Keyboard::isKeyPressed(Keyboard::Up)))
		jump = false;
	if (!(Keyboard::isKeyPressed(Keyboard::Down)))
		down = false;
	if (!(Keyboard::isKeyPressed(Keyboard::A)))
		punch1 = false;
	if (!(Keyboard::isKeyPressed(Keyboard::S)))
		kick1 = false;
	if (!(Keyboard::isKeyPressed(Keyboard::Q)))
		punch2 = false;
	if (!(Keyboard::isKeyPressed(Keyboard::W)))
		kick2 = false;

	//idle animations
	if (onGround && !(right || left || jump || down || kick1 || kick2 || punch1 || punch2))
	{
		if (gamesClock.getElapsedTime().asMilliseconds() > 500.f)
		{
			if (spriteRect.left == 0)
			{
				spriteRect.left = 64;
			}
			else
				spriteRect.left = 0;
			sprite.setTextureRect(spriteRect);
			gamesClock.restart();
		}
	}

	if (right)
	{
		directionRight = true;
		xVel = windowWidth * 0.0035f;
	}

	if (left)
	{
		directionRight = false;
		xVel = -0.0035f * windowWidth;
	}

	if (jump && onGround)
	{
		yVel = jumpHeight * -1;
	}

	if (onGround == false)
	{
		yVel += G;
		if (yVel > maxG) yVel = maxG;
	}


	if (!(right || left))
	{
		xVel = 0;
	}
};

void characterClass::update()
{
	xCoordinate += xVel;
	yCoordinate += yVel;
};

void characterClass::collide()
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
};

using namespace sf;
void game()
{
	//creating player and enemy 
	characterClass playerOBB;
	characterClass enemyOBB;
	sf::Sprite playerSprite(playerOBB.sprite);
	playerOBB.initiateCharacterClass();
	int enemyInput;

	//initiate game loop
	while (app.isOpen()){

		//close app
		Event event;
		while (app.pollEvent(event))
		{
			if (event.type == Event::Closed)
			app.close();
		}

		//move player
		playerOBB.inputPolling();
		playerOBB.update();	

		//find distance
		float displacement = playerOBB.xCoordinate - enemyOBB.xCoordinate;
		float distance = std::abs(displacement);
		

		//AI
		if ((distance <= enemyOBB.hitboxWidth) && (enemyOBB.HP > damageThreshold))
		{
			enemyInput = rand() % 5;
		}
		if ((distance <= enemyOBB.hitboxWidth) && (enemyOBB.HP <= damageThreshold))
		{
			enemyInput = rand() % 2;
		}
		if ((distance > enemyOBB.hitboxWidth) && (enemyOBB.HP <= damageThreshold))
		{
			enemyInput = rand() % 2;
		}
		if ((distance > enemyOBB.hitboxWidth) && (enemyOBB.HP > damageThreshold))
		{
			enemyInput = rand() % 2;
		}
		if (!(playerOBB.onGround))
		{
			enemyInput = rand() % 7;
		}
		
		playerOBB.onGround = false;
		playerOBB.characterClass::collide();

		//cls
		app.clear();

		//drawing
		app.draw(playerOBB.sprite);

		// update window
		playerOBB.sprite.setPosition(playerOBB.xCoordinate, playerOBB.yCoordinate);
		playerOBB.sprite.setScale(1, 1);

		//display
		app.display();
	};
	//clear screen after gameplay
	app.clear();
};

void menu()
{

};

//network functions
void clientHandshaking()
{

};

void serverHandshake()
{

};

void multiplayer()
{

};

void signIn()
{

};

void leaderboard()
{

};

//main function
int main()
{
	game();

	return 0;
};