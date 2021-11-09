#include <iostream>
#include <fstream>
#include <vector>
#include <complex>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

//window settings
int windowWidth = 1440;
int windowHeight = 900;
int frameRate = 60;
int AA = 0;
bool vsync = false;
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
sf::Clock gamesClock;
sf::RenderWindow app(sf::VideoMode(windowWidth, windowHeight), "game window");

using namespace sf;
class characterClass
{
public:
	bool onGround;
	bool directionRight;
	bool down;
	bool left;
	bool right;
	bool jump;
	bool punch1;
	bool punch2;
	bool kick1;
	bool kick2;
	bool block;
	int hitboxWidth;
	int hitboxHeight;
	int HP;
	int characterSelection;
	float xCoordinate;
	float yCoordinate;
	float xVel;
	float yVel;
	float hitboxLeft;
	float hurtboxLeft;
	float collisionboxLeft;
	IntRect spriteRect;
	IntRect hitbox;
	IntRect hurtbox;
	Sprite sprite;


	Sprite obtainSprite(int characterNumber)
	{
		Texture texture;
		texture.loadFromFile("data/sprites/player 1 characters/fighter 1 spritesheet.png");
		Sprite sprite(texture);
		IntRect spriteRect(0, 0, spriteWidth, spriteHeight);
		sprite.setTextureRect(spriteRect);

		return sprite;
	};
	void initiateCharacterClass()
	{
		HP = 100;
		xVel = 0;
		yVel = 0;
		directionRight = true;
		xCoordinate;
		yCoordinate;
		onGround = false;
		down = false;
		left = false;
		right = false;
		jump = false;
		punch1 = false;
		punch2 = false;
		kick1 = false;
		kick2 = false;
		block = false;
		hitboxHeight = 5;
		hitboxWidth = 10;
		IntRect hitbox(0, 0, hitboxWidth, hitboxHeight);
		IntRect hurtbox(0, 0, spriteWidth, spriteHeight);
		
	};
	void movement(bool onGround, bool directionRight, bool right, bool left, bool jump, bool down, bool punch1, bool punch2, bool kick1, bool kick2)
	{
		//move right
		if (right)
		{
			directionRight = true;
			xVel = windowWidth * 0.0035f;
		}

		//move left
		if (left)
		{
			directionRight = false;
			xVel = windowWidth * -0.0035f;
		}

		//jump
		if (jump && onGround)
		{
			yVel = jumpHeight * -1;
		}
		if (onGround = false)
		{
			yVel += G;
			if (yVel > maxG) yVel = maxG;
		}

		//stationaty
		if (!(right || left))
		{
			xVel = 0;
		}
		if (onGround && !(right || left || jump || down || kick1 || kick2 || punch1 || punch2))
		{
			if (gamesClock.getElapsedTime().asMilliseconds() > 500.f)
			{
				if (spriteRect.left = 0)
				{
					spriteRect.left = 64;
				}
				else
					spriteRect.left = 0;
				sprite.setTextureRect(spriteRect);
				gamesClock.restart();
			}
		}

		//send the values to update 
		this->update();
	};
	void inputPolling()
	{
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
		
		this->movement(onGround, directionRight, right, left, jump, down, punch1, punch2, kick1, kick2);
	};
	void update()
	{
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
	};
};

using namespace sf;
void menu()
{
	while (app.isOpen())
	{

		int point = 1;

		//close app
		Event event;
		while (app.pollEvent(event))
		{
			if (event.type == Event::Closed)
				app.close();
		};

		int menuIndex[5] = { 1, 2, 3, 4, 5 };

		if (Keyboard::isKeyPressed(Keyboard::Down))
			if (point < 5)
				point++;
		if (Keyboard::isKeyPressed(Keyboard::Up))
			if (point > 1)
				point = point - 1;

		//option 1: start game
		if ((menuIndex[point] == 1) && (Keyboard::isKeyPressed(Keyboard::Return)))
		{
			app.clear();
			int characterSelect();
			void game();
		}
		if ((menuIndex[point] == 1) && (Keyboard::isKeyPressed(Keyboard::Return)))
		{
			app.clear();
			int characterSelect();
			void multiplayer();
		}
		//option 3: further options
		if ((menuIndex[point] == 3) && (Keyboard::isKeyPressed(Keyboard::Return)))
		{
			app.clear();
			point = 1;

		}
		//option 4: view leaderoard
		if ((menuIndex[point] == 4) && (Keyboard::isKeyPressed(Keyboard::Return)))
		{
			app.clear();
			void leaderboard();
		}
		//option 5: login/sign up
		if ((menuIndex[point] == 5) && (Keyboard::isKeyPressed(Keyboard::Return)))
		{
			app.clear();
			void signIn();
		}
	};
};

using namespace sf;
int characterSelect()
{
	while (app.isOpen())
	{

		int pointx = 1;
		int pointy = 1;
		bool selected = false;

		while (selected != true)
		{
			//close app
			Event event;
			while (app.pollEvent(event))
			{
				if (event.type == Event::Closed)
					app.close();
			};
			int menuIndex[3][3][1] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			//array visualised
			////////////////////////////////
			//{1}{2}{3}	three rows across //
			//{4}{5}{6} and down          //
			//{7}{8}{9}	of single values  //
			////////////////////////////////

			if (Keyboard::isKeyPressed(Keyboard::Right))
				if (pointx < 3)
					pointx++;
			if (Keyboard::isKeyPressed(Keyboard::Left))
				if (pointx > 1)
					pointx = pointx - 1;
			if (Keyboard::isKeyPressed(Keyboard::Down))
				if (pointy < 3)
					pointy++;
			if (Keyboard::isKeyPressed(Keyboard::Up))
				if (pointy > 1)
					pointy = pointy - 1;
			if (Keyboard::isKeyPressed(Keyboard::Return))
				selected = true;
			return menuIndex[pointx][pointy][1];
		}
	}	
};

using namespace sf;
void game()
{
	

	//creating player and enemy
	characterClass playerOBB;
	characterClass enemyOBB;
	playerOBB.characterSelection =  characterSelect();
	playerOBB.obtainSprite(playerOBB.characterSelection);
	playerOBB.initiateCharacterClass();
	enemyOBB.initiateCharacterClass();


	//initiate game loop
	while (app.isOpen())
	{
		//close app
		Event event;
		while (app.pollEvent(event))
		{
			if (event.type == Event::Closed)
				app.close();
		}

		//move player
		playerOBB.inputPolling();
		playerOBB.movement(playerOBB.onGround, playerOBB.directionRight, playerOBB.right, playerOBB.left, playerOBB.jump, playerOBB.down, playerOBB.punch1, playerOBB.punch2, playerOBB.kick1, playerOBB.kick2);
		playerOBB.update();

		//find distance
		float displacement = playerOBB.xCoordinate - enemyOBB.xCoordinate;
		float distance = std::abs(displacement);

		//AI
		int enemyInput;
		if ((distance <= enemyOBB.hitboxWidth) && (enemyOBB.HP > damageThreshold))
		{
			enemyInput = rand() % 5;
			if (enemyInput == 0)
				enemyOBB.punch1 = true;
			if (enemyInput == 1)
				enemyOBB.punch2 = true;
			if (enemyInput == 2)
				enemyOBB.kick1 = true;
			if (enemyInput == 3)
				enemyOBB.kick2 = true;
			if (enemyInput == 4)
				//enemyOBB.combo move
				if (enemyInput == 5)
					enemyOBB.right, enemyOBB.left, enemyOBB.jump, enemyOBB.down, enemyOBB.kick1, enemyOBB.kick2, enemyOBB.punch1, enemyOBB.punch2 = false;
		}
		if ((distance <= enemyOBB.hitboxWidth) && (enemyOBB.HP <= damageThreshold))
		{
			enemyInput = rand() % 2;
			if (enemyInput == 0)
				enemyOBB.right = true;
			if (enemyInput == 1)
				enemyOBB.left = true;
			if (enemyInput == 2)
				enemyOBB.block = true;
		}
		if ((distance > enemyOBB.hitboxWidth) && (enemyOBB.HP <= damageThreshold))
		{
			enemyInput = rand() % 3;
			if (enemyInput == 0)
				enemyOBB.right = true;
			if (enemyInput == 1)
				enemyOBB.left = true;
			if (enemyInput == 2)
				//enemyOBB.combo move 
				enemyOBB.right, enemyOBB.left, enemyOBB.jump, enemyOBB.down, enemyOBB.kick1, enemyOBB.kick2, enemyOBB.punch1, enemyOBB.punch2 = false;
			if (enemyInput == 3)
				enemyOBB.right, enemyOBB.left, enemyOBB.jump, enemyOBB.down, enemyOBB.kick1, enemyOBB.kick2, enemyOBB.punch1, enemyOBB.punch2 = false;
		}
		if ((distance > enemyOBB.hitboxWidth) && (enemyOBB.HP > damageThreshold))
		{
			enemyInput = rand() % 2;
			if (enemyInput == 0)
				enemyOBB.left = true;
			if (enemyInput == 1)
				enemyOBB.right = true;
			if (enemyInput == 2)
				//enemyOBB.combo move;
				enemyOBB.right, enemyOBB.left, enemyOBB.jump, enemyOBB.down, enemyOBB.kick1, enemyOBB.kick2, enemyOBB.punch1, enemyOBB.punch2 = false;
		}
		if (!(playerOBB.onGround))
		{
			enemyInput = rand() % 7;
			if (enemyInput == 0)
				enemyOBB.punch1 = true;
			if (enemyInput == 1)
				enemyOBB.punch2 = true;
			if (enemyInput == 2)
				enemyOBB.kick1 = true;
			if (enemyInput == 3)
				enemyOBB.kick2 = true;
			if (enemyInput == 4)
				enemyOBB.jump = true;
			if (enemyInput == 5)
				enemyOBB.right = true;
			if (enemyInput == 6)
				enemyOBB.left = true;
			if (enemyInput == 7)
				//enemyOBB.combo move;
				enemyOBB.right, enemyOBB.left, enemyOBB.jump, enemyOBB.down, enemyOBB.kick1, enemyOBB.kick2, enemyOBB.punch1, enemyOBB.punch2 = false;
		}

		//movement
		playerOBB.onGround = false;
		enemyOBB.onGround = false;
		playerOBB.inputPolling();
		enemyOBB.movement(onGround, directionRight, right, left, jump, down, punch1, punch2, kick1, kick2);
		//playerOBB.update();
		//enemyOBB.update();
		playerOBB.collide();
		enemyOBB.collide();
		
		//cls
		app.clear();

		//drawing
		app.draw(playerOBB.sprite);
		app.draw(enemyOBB.sprite);

		// update window
		playerOBB.sprite.setPosition(playerOBB.xCoordinate, playerOBB.yCoordinate);
		playerOBB.sprite.setScale(7, 7);

		//display
		app.display();
	};
	
	//clear screen after gameplay
	app.clear();
};

//network functions
using namespace sf;
void socketComunication()
{
	TcpSocket socket;
	Socket::Status connectionStatus = socket.connect("", 53000);
	if (connectionStatus != Socket::Done)
	{
		app.clear();
		menu();
	}
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
	menu();
	app.clear();
	//characterSelect();
	//game();
	return 0;
};
