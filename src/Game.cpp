#include "Game.hpp"

#include "Logger.hpp"

namespace ChessV2 {
Logger log(LogLevel::DEBUG);

void Game::loop() {
    bool rerender = true;
    while (this->m_window.isOpen()) {
        sf::Event event;
        while (this->m_window.waitEvent(event)) {
            if (event.type == sf::Event::Closed)
                this->m_window.close();
            else if (rerender) {
                this->m_window.clear();
                this->update();
                this->m_window.display();
                rerender = false;
            }
        }
    }
}
void Game::update() {
    this->m_cbPtr->drawBoard(this->m_window);
    this->m_cbPtr->drawPieces(this->m_window);
}
};  // namespace ChessV2