#include <SFML/Graphics.hpp>

#include "Chessboard.hpp"
#include "Game.hpp"

int main() {
    ChessV2::Chessboard cb;
    cb.readFen("4kb1r/p4ppp/4q3/8/8/1B6/PPP2PPP/2KR4");
    sf::RenderWindow window(sf::VideoMode(cb.m_boardWidth, cb.m_boardHeight),
                            "ChessBitboard");
    ChessV2::Game game(&cb, window);
}
