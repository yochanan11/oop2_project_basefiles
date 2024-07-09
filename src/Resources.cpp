#include "Resources.h"
#include "Macrose.h"
#include <iostream>

Resources::Resources()
{
	for (auto i = size_t(0); i < OBJECTS; ++i)
		m_objects_texture[i].loadFromFile(m_textures_name[i]);

	for (auto i = size_t(0); i < SOUND_BUFFER; ++i)
		m_sound_buffer[i].loadFromFile(m_soundBuffer_name[i]);
	m_font.loadFromFile(m_font_name);
	m_music.openFromFile(m_music_name);
	m_records_file = std::fstream(m_records_file_name, std::ios_base::in | std::ios_base::out);
	if (!m_records_file.is_open()) {
		std::cerr << "Failed to open the records file: " << m_records_file_name << std::endl;
	}
}

//--------------------------------------
sf::Texture& Resources::getTexture(ObjIndex type) { return m_objects_texture[size_t(type)]; }
//--------------------------------------
sf::Font& Resources::getFont() { return m_font; }
//-----------------------------------------------
void Resources::playSound(SoundIndex type) {
	m_sound = sf::Sound(m_sound_buffer[size_t(type)]);
	m_sound.play();
	m_sound.setVolume(90);
}
//-----------------------------------------------
sf::Music& Resources::getMusic() { return m_music; }
std::fstream& Resources::getRecordsFile() { return m_records_file; }
//--------------------------------------
Resources::~Resources(){}