#include "Level/Level.h"
//----------------------------------------------
Level::Level(Player& Player,sf::Texture& texture) :m_player(&Player),m_bec_level(texture),
m_text_score("SCORE: " + std::to_string(m_player->getScore())
	, Resources::instance().getFont())
{
	m_text_score.setFillColor(sf::Color::Yellow);
}
//----------------------------------------------
Level::Level(){}
//----------------------------------------------