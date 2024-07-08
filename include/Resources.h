#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

const size_t OBJECTS = 15;
const size_t SOUND_BUFFER = 4;

enum class ObjIndex
{
	BACKGROUND,F_PLAYER, F_PLAYER1,MENU,FISH_E1, FISH_E2, FISH_E3, FISH_E4, F_PLAYER_S
	, NEW_GAME_B, OBSTACLE_F, MEDIUM_FISH, OBSTACLE, GIFT, RED_GIFT
};
enum class SoundIndex
{
	EAT,GAME_OVER, GIFT, GROWTH
};

class Resources
{
public:
	static Resources& instance() {
		static auto resources = Resources(); // static in function!
		return resources;
	}
	sf::Texture& getTexture(ObjIndex);
	sf::Font& getFont();
	void playSound(SoundIndex);
	sf::Music& getMusic();

private:
	Resources();
	~Resources();

	std::string m_textures_name[OBJECTS] =
	{
		"background.png","Fish_player.png","Fish_player1.png","Menu.png","Fish_Eaten1.png",
		"Fish_Eaten2.png","Fish_Eaten3.png","Fish_Eaten4.png","Fish_player_sprite.png",
		"NEW GAME B1.png","ObstacleFish.png","MediumFish.png","Obstacle.png","Gift.png",
		"Red_Gift.png"
	};
	sf::Texture m_objects_texture[OBJECTS];
	std::string m_font_name = "BubblegumSans-Regular.ttf" ,m_music_name = "sound.wav";
	std::string	m_soundBuffer_name[SOUND_BUFFER] = {
		"eat.wav" ,
		"gameover.wav",
		"GiftEffect.wav","growth.wav"
		/*,"GiftEffect.wav"*/
	};
	sf::Font m_font;
	sf::SoundBuffer m_sound_buffer[SOUND_BUFFER];
	sf::Music m_music;
	sf::Sound m_sound;
};
