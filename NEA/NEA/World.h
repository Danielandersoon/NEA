#ifndef WORLD_H
#define WORLD_H
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <array>
#include <SFML/Graphics/CircleShape.hpp>
#include "ResourceHolder.h"
#include "ResourceIdentifier.h"
#include "SceneNode.h"
#include "SpriteNode.h"
#include "Actor.h"
#include "CommandQueue.h"
#include "Command.h"
#include "AudioPlayer.h"

// Forward declaration
namespace sf
{
	class RenderWindow;
	class RenderTarget;
}

using namespace sf;
class World : private NonCopyable
{
public:
	explicit World(RenderTarget& outputTarget, FontHolder_t& fonts, AudioPlayer& audioQueues, Actor::Type p1Char, Actor::Type p2Char, std::string backGroundFilePath, std::string platformFilePath, std::string hudLeftFilePath, std::string hudRightFilePath);
	void update(Time dt);
	void draw();

	CommandQueue& getCommands();
	bool isRoundOver;
	int	p1Rounds;
	int	p2Rounds;
	void resetRound();
private: 
	void addEnemy(Actor::Type type, float relX, float relY);
	void spawnEnemies();
	void adaptPlayerVelocity();
	void adaptPlayerPosition();
	void updateSounds();
	void setRoundText(size_t score);
	void setTimerText(float time);
	void dealDamage(std::string toWhom);
	FloatRect getViewBounds() const;
	void handleCollisions();
	bool matchesCategories(SceneNode::Pair& colliders, Category::Type type1, Category::Type type2);
	void loadTextures();
	void buildScene();
	void addEnemies();
	void resetHealthBars();
private:
	enum Layer
	{
		Background,
		LowerAir,
		UpperAir,
		LayerCount
	};

	struct SpawnPoint {
		SpawnPoint(Actor::Type type, float x, float y):type(type), x(x), y(y) {}
		Actor::Type type;
		float x, y;
	};

private:
	RenderTarget& target;
	RenderTexture sceneTexture;
	View worldView;
	TextureHolder_t textures;
	const FontHolder_t& fonts;
	AudioPlayer& audioQueues;
	Actor::Type& p1Char;
	Actor::Type& p2Char;
	std::string& backGroundFilePath;
	std::string& platformFilePath;
	std::string& hudLeftFilePath;
	std::string& hudRightFilePath;

	SceneNode sceneGraph;
	std::array<SceneNode*, LayerCount>	sceneLayers;
	CommandQueue commandQueue;

	FloatRect worldBounds;
	Vector2f spawnPosition;
	Vector2f p1StartingPos;
	Vector2f p2StartingPos;

	Actor* playerActor;
	Actor* player2Actor;
	Actor* platformActor;
	std::vector<SpawnPoint> enemySpawnPoints;
	std::vector<Actor*>	activeEnemies;
	std::vector<Sprite>	playerLives;


	Text roundHud;
	Text timerText;

	RectangleShape leftHealthBar;
	RectangleShape	rightHealthBar;

	CircleShape	leftLight1;
	CircleShape	leftLight2;
	CircleShape	leftLight3;

	CircleShape	rightLight1;
	CircleShape	rightLight2;
	CircleShape	rightLight3;

	float roundTimer;
	SpriteNode* blockShield;
};
#endif