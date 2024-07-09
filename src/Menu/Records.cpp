#include "Menu/Records.h"
#include "Resources.h"
#include <sstream>
#include "Macrose.h"
#include <iostream>

//----------------------------------------------------------
Records::Records() : Command(Resources::instance().getTexture(ObjIndex::RECORDS_B), sf::Vector2f(810, 560)),
m_txt_title(sf::Text("RECORDS", Resources::instance().getFont(), 100)),
m_file_records(Resources::instance().getRecordsFile()),
m_txt_records("", Resources::instance().getFont(), 50),
m_background(Resources::instance().getTexture(ObjIndex::RECORDS_BEC)),
m_rec(sf::RectangleShape(sf::Vector2f(RECORDS_WINDOW_WIDTH - 200, RECORDS_WINDOW_HEIGHT - 100))) 

{
    m_sprite_menu.setScale(0.35f, 0.35f);

    m_txt_title.setFillColor(sf::Color::Black);
    m_txt_title.setPosition(RECORDS_WINDOW_WIDTH / 2, RECORDS_WINDOW_WIDTH / 7);
    m_txt_title.setOrigin(m_txt_title.getGlobalBounds().width / 2, m_txt_title.getGlobalBounds().height / 2);
    m_txt_title.setStyle(sf::Text::Underlined);

    m_txt_records.setPosition(RECORDS_WINDOW_WIDTH / 2, RECORDS_WINDOW_HEIGHT / 2);
    m_txt_records.setFillColor(sf::Color::Blue);
    m_background.setScale(
        float(RECORDS_WINDOW_WIDTH) / m_background.getTexture()->getSize().x,
        float(RECORDS_WINDOW_HEIGHT) / m_background.getTexture()->getSize().y
    );
    m_rec.setPosition( 100,  100);
    m_rec.setFillColor(sf::Color(255, 255, 255, 200));
}

//----------------------------------------------------------
Records::~Records() { }

//----------------------------------------------------------
void Records::execute()
{
    sf::RenderWindow recordsWindow(sf::VideoMode(RECORDS_WINDOW_WIDTH, RECORDS_WINDOW_HEIGHT), "Records");

    loadRecords();

    while (recordsWindow.isOpen())
    {
        sf::Event event;
        while (recordsWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                recordsWindow.close();
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            {
                recordsWindow.close();
            }
        }
        recordsWindow.clear();
        recordsWindow.draw(m_background);
        recordsWindow.draw(m_rec);
        drawRecords(recordsWindow);
        recordsWindow.display();
    }
}

//----------------------------------------------------------
void Records::drawRecords(sf::RenderWindow& window) const
{
    window.draw(m_txt_title);
    window.draw(m_txt_records);
}

//----------------------------------------------------------
void Records::loadRecords()
{
    m_records.clear();
    backToStart();
    std::string line, name, records = "";
    auto space = std::string("\t..................\t");
    size_t score;

    for (auto i = size_t(0); i < MAX_NUM_OF_RECORDS; ++i)
    {
        if (m_file_records.eof()) break;

        std::getline(m_file_records, line);
        if (line.empty() || line == "\n") break; // last line

        auto one_record = std::istringstream(line);
        one_record.exceptions(std::ios::failbit | std::ios::badbit);
        one_record >> name >> score;

        if (name.size() < MAX_PLAYER_NAME) // fill the end of name with spaces
            for (auto j = name.size(); j < MAX_PLAYER_NAME; ++j) name += " ";

        m_records.emplace(score, name);
    }

    std::for_each(m_records.rbegin(), m_records.rend(), [&records, &space](auto& rec) {
        records += (rec.second + space + std::to_string(rec.first) + "\n");
        });

    m_txt_records.setString(records);
    m_txt_records.setOrigin(m_txt_records.getGlobalBounds().width / 2, m_txt_records.getGlobalBounds().height / 2);
}

//-------------------------------------------------------------------
void Records::backToStart()
{
    if (m_file_records.fail()) m_file_records.clear();
    m_file_records.seekg(0, m_file_records.beg);
}
