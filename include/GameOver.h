#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>

class GameOver {
public:
    GameOver(float, float);
    void run(sf::RenderWindow&, size_t);

private:
    void buildGameOver(float, float);
    void drawGameOver(sf::RenderWindow&, size_t);
    void checkIfNewRecord(size_t);
    void getSmallRecord();
    void saveNewRecord(size_t);
    void backToStart();

    std::fstream m_file_records;
    std::string m_player_name = "";
    bool m_new_record = false;
    size_t m_small_score = 0;
    sf::Text m_game_over_txt, m_score_msg;
};
