#pragma once
#include "Chessboard.hpp"
#include "SFML/Graphics.hpp"

namespace ChessV2 {
class Game {
public:
    Game(Chessboard* cbPtr, sf::RenderWindow& window)
        : m_cbPtr(cbPtr), m_window(window) {
        this->loop();
    }
    ~Game() {
    }

    void loop();
    void update();

private:
    Chessboard* m_cbPtr;
    sf::RenderWindow& m_window;
};
}  // namespace ChessV2