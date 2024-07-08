#include "Menu/NewGame.h"
#include "Resources.h"

NewGame::NewGame(Controller* controller)
    : Command(Resources::instance().getTexture(ObjIndex::NEW_GAME_B), sf::Vector2f(200, 475)), m_controller(controller) // העברת המצביע
{
    m_sprite_menu.setScale(0.35f, 0.35f);
}
//------------------------------------
NewGame::~NewGame() {}
//------------------------------------
void NewGame::execute() {
    std::string playerName = getPlayerName();
    m_controller->getPlayer().setName(playerName);
    m_controller->runGame(); // קריאה לפונקציה להפעיל את המשחק
}
//------------------------------------
std::string NewGame::getPlayerName() {
    sf::RenderWindow inputWindow(sf::VideoMode(400, 200), "Enter Your Name");

    sf::Text prompt("Enter your name:",
        Resources::instance().getFont(), 24);
    prompt.setPosition(10, 10);
    prompt.setFillColor(sf::Color::White);

    sf::Text userInputText("", Resources::instance().getFont(), 24);
    userInputText.setPosition(10, 60);
    userInputText.setFillColor(sf::Color::White);

    std::string userInput;
    while (inputWindow.isOpen()) {
        sf::Event event;
        while (inputWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                inputWindow.close();

            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\b') { // Handle backspace
                    if (!userInput.empty())
                        userInput.pop_back();
                }
                else if (event.text.unicode == '\r' || event.text.unicode == '\n') { // Handle enter key
                    inputWindow.close();
                }
                else if (event.text.unicode < 128) { // Only ASCII characters
                    userInput += static_cast<char>(event.text.unicode);
                }
            }
        }

        userInputText.setString(userInput);
        inputWindow.clear(sf::Color::Blue);
        inputWindow.draw(prompt);
        inputWindow.draw(userInputText);
        inputWindow.display();
    }

    return userInput;
}

