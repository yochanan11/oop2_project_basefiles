#pragma once
#include "Command.h"
#include <map>
#include <fstream>
#include <SFML/Graphics.hpp>

/* ----------------------------------------------------------
 * class for records button and screen (inherited from button class).
 */

const size_t RECORDS_WINDOW_WIDTH = 900;
const size_t RECORDS_WINDOW_HEIGHT = 675;

class Records : public Command
{
public:
    Records();
    ~Records();

    void execute() override;

private:
    void loadRecords();
    void drawRecords(sf::RenderWindow& window) const;
    void backToStart();

    sf::Sprite m_background;
    sf::RectangleShape m_rec;
    std::fstream& m_file_records;
    std::multimap<size_t, std::string> m_records;
    sf::Text m_txt_title, m_txt_records;
};
