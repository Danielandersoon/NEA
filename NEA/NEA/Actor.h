#ifndef ACTOR_H
#define ACTOR_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML\System\Clock.hpp>
#include "Entity.h"
#include "ResourceHolder.h"
#include "ResourceIdentifier.h"
#include "Animation2.h"
#include "TextNode.h"
#include "Category.h"
#include "AudioPlayer.h"

using namespace sf;
class Actor : public Entity
{
public:
    enum class Type {
        Hero1,
        Hero2,
        Hero3,
        Platform,

    };
    enum class State {
        Dead, Idle, Jump,
        Attack1, Attack2, Fall, Run, TakeHit, Static, count
    };
    enum class Direction
    {
        Left, Right, Up, Down, Static
    };
public:

    bool isJumping;
    bool isFalling;
    bool isGrounded;
    const int gravitySpeed;
    const int groundHeight;
    float TimeThisJump;
    bool JustJumped = false;
    float JumpDuration;
    bool isBlocking = false;
    float shieldTimer;

    Sprite shield;
    Actor(Type type, const TextureHolder_t& textures, const FontHolder_t& fonts, Category::Type player);
    ~Actor() = default;
    unsigned int getCategory() const override;
    FloatRect getBoundingRect() const override;
    float getMaxSpeed() const;
    bool isMarkedForRemoval() const override;
    void setState(State state);
    Actor::State getState() const;
    Actor::Type getType() const;

    void playAudio(EffectID effectType);

    void setIsJumping(bool jump);
    bool getIsJumping();

    void setDirection(Actor::Direction direction);
    Actor::Direction getDirection();

    bool isCurrentAnimationFinished();
    //will need function to deactivate shield.
    void deactivateShield();
    //function will activate shield for player in update states x amount of seconds  
    void activateShield();

private:
    void updateStates();
    void updateCurrent(Time dt, CommandQueue& commands) override;
    void drawCurrent(RenderTarget& target, RenderStates states) const override;
    void updateMovementPattern(Time dt);
    void updateAudios();

private:
    Type type_;
    State state_;
    mutable Sprite sprite_;
    std::map<Actor::State, Animation2> animations_;
    Direction direction_;
    TextNode* healthDisplay_;
    float travelDistance_;
    std::size_t directionIndex_;

    float worldBounderiesWidth;
    Category::Type category;

    float countdown;
    Time elapsedTime;
    Clock clock;

    AudioPlayer audioPlayer;

    bool canPlayDamageAudio;

    Texture shieldTexture;
};
#endif