#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

const size_t OBJECTS = 3;
const size_t SOUND_BUFFER = 0;

enum class ObjIndex
{
	BACKGROUND,F_PLAYER,MENU
};
enum class SoundIndex
{
	
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
	/*void playSound(SoundIndex);
	sf::Music& getMusic();*/

private:
	Resources();
	~Resources();

	std::string m_textures_name[OBJECTS] =
	{
		"background.png","Fish_player.png","Menu.png"
	};
	sf::Texture m_objects_texture[OBJECTS];
	//std::string m_font_name = "ARIAL.TTF", //m_music_name = "MUSIC.wav";
	//std::string	m_soundBuffer_name[SOUND_BUFFER] = {
	//	/*"EatenAfect.wav" ,
	//	"BoomEfect.wav",
	//	"GiftEffect.wav"*/
	//};
	sf::Font m_font;
	//sf::SoundBuffer m_sound_buffer[SOUND_BUFFER];
	/*sf::Music m_music;
	sf::Sound m_sound;*/
};
