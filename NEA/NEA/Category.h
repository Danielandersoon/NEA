#ifndef CATAGORY_H
#define CATAGORY_H
namespace Category
{
	enum Type
	{
		None = 0,
		SceneAirLayer = 1 << 0,
		SoundEffect = 1 << 1,

		Hero1 = 1 << 2,
		Hero2 = 1 << 3,
		Hero3 = 1 << 4,
		Platform = 1 << 5,
		//add player 1 and 2 category so when assigning hero to character you can use player 1 or 2
		Player1 = 1 << 6,
		Player2 = 1 << 7,

		Actor = Hero1 | Hero2 | Hero3
		//Player = Player1 | Player2 
	};
}
#endif