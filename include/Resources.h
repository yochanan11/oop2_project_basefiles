#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <fstream>

const size_t OBJECTS = 19;
const size_t SOUND_BUFFER = 4;

enum class ObjIndex
{
	BACKGROUND, HELP, F_PLAYER, F_PLAYER1,MENU,FISH_E1, FISH_E2, FISH_E3, FISH_E4, F_PLAYER_S
	, NEW_GAME_B, HELP_B, RECORDS_B, OBSTACLE_F, MEDIUM_FISH, OBSTACLE, GIFT, RED_GIFT, RECORDS_BEC
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
	std::fstream& getRecordsFile();

private:
	Resources();
	~Resources();

	std::string m_textures_name[OBJECTS] =
	{
		"background.png", "help.jpeg", "Fish_player.png","Fish_player1.png","Menu.png","Fish_Eaten1.png",
		"Fish_Eaten2.png","Fish_Eaten3.png","Fish_Eaten4.png","Fish_player_sprite.png",
		"new-game.png", "help.png", "records.png", "ObstacleFish.png","MediumFish.png","Obstacle.png","Gift.png",
		"Red_Gift.png","records_b.png"
	};
	sf::Texture m_objects_texture[OBJECTS];
	std::string m_font_name = "BubblegumSans-Regular.ttf" ,m_music_name = "sound.wav";
	std::string	m_soundBuffer_name[SOUND_BUFFER] = {
		"eat.wav" ,
		"gameover.wav",
		"GiftEffect.wav","growth.wav"
	};
	std::string m_records_file_name = "Records.txt";
	sf::Font m_font;
	sf::SoundBuffer m_sound_buffer[SOUND_BUFFER];
	sf::Music m_music;
	sf::Sound m_sound;
	std::fstream m_records_file;
};
