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
    m_controller->runGame(); 
}
//------------------------------------
std::string NewGame::getPlayerName() {
    sf::RenderWindow inputWindow(sf::VideoMode(400, 200), "Enter Your Name");

    sf::Text prompt("Enter your name - and then press enter:",
        Resources::instance().getFont(), 24);
    prompt.setPosition(10, 10);
    prompt.setFillColor(sf::Color::White);

    sf::Text userInputText("", Resources::instance().getFont(), 24);
    userInputText.setPosition(10, 60);
    userInputText.setFillColor(sf::Color::White);

    sf::Text errorMessage("Name cannot be empty!", Resources::instance().getFont(), 18);
    errorMessage.setPosition(10, 120);
    errorMessage.setFillColor(sf::Color::Red);
    bool showError = false;

    std::string userInput;
    while (inputWindow.isOpen()) {
        sf::Event event;
        while (inputWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                // Do not allow window to close if name is empty
                if (!userInput.empty()) {
                    inputWindow.close();
                }
                showError = true;
            }

            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\b') { // Handle backspace
                    if (!userInput.empty())
                        userInput.pop_back();
                }
                else if (event.text.unicode == '\r' || event.text.unicode == '\n') { // Handle enter key
                    if (!userInput.empty()) {
                        inputWindow.close();
                    }
                    else {
                        showError = true;
                    }
                }
                else if (event.text.unicode < 128) { // Only ASCII characters
                    userInput += static_cast<char>(event.text.unicode);
                    showError = false; // Hide error message when user types
                }
            }
        }
        userInputText.setString(userInput);
        inputWindow.clear(sf::Color::Blue);
        inputWindow.draw(prompt);
        inputWindow.draw(userInputText);
        if (showError) {
            inputWindow.draw(errorMessage);
        }
        inputWindow.display();
    }

    return userInput;
}



