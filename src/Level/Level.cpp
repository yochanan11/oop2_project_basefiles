#include "Level/Level.h"
//----------------------------------------------
Level::Level(Player& Player,sf::Texture& texture) :m_player(&Player),m_bec_level(texture),
m_text_score("SCORE: " + std::to_string(m_player->getScore())
	, Resources::instance().getFont())
{
	m_text_score.setFillColor(sf::Color::Yellow);
    m_game_over_rec.setSize(sf::Vector2f(400, 200));
    m_game_over_rec.setFillColor(sf::Color(0, 0, 0, 150)); // שחור עם שקיפות
    m_game_over_rec.setOrigin(m_game_over_rec.getSize().x / 2, m_game_over_rec.getSize().y / 2);
    m_game_over_rec.setPosition(700, 450); // מרכז החלון

    // הגדרת טקסט ל-"Game Over"
    m_gameOverText.setFont(Resources::instance().getFont()); // נניח שיש פונקציה כזו
    m_gameOverText.setString("Game Over");
    m_gameOverText.setCharacterSize(50);
    m_gameOverText.setFillColor(sf::Color::White);
    m_gameOverText.setOrigin(m_gameOverText.getLocalBounds().width / 2, m_gameOverText.getLocalBounds().height / 2);
    m_gameOverText.setPosition(700, 450); // מרכז החלון
}
//----------------------------------------------
Level::Level(){}
//----------------------------------------------