#pragma once
#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

#include "Logger.hpp"
#include "Piece.hpp"
#include "SFML/Graphics.hpp"

namespace ChessV2 {
enum class Turn { White = 0, Black };

class Chessboard {
public:
    Chessboard() {
    }
    ~Chessboard() {
    }
    void readFen();
    void readFen(const std::string&);
    void drawBoard(sf::RenderWindow&);
    void drawPieces(sf::RenderWindow&);

public:
    int m_boardWidth = 980, m_boardHeight = 980;
    int m_rows = 8, m_columns = 8;
    int m_cellWidth = m_boardWidth / m_columns,
        m_cellHeight = m_boardHeight / m_rows;
    sf::Color m_whiteSqColor = sf::Color(234, 236, 208),
              m_blackSqColor = sf::Color(119, 149, 86),
              m_currSqColor = sf::Color(245, 246, 130);

private:
    Turn m_turn = Turn::White;
    std::uint64_t m_pieces[14] = {0};
    std::uint64_t m_wholeBoard = 0;
    std::uint64_t m_whiteBoard = 0;
    std::uint64_t m_blackBoard = 0;
    std::uint64_t m_emptyBoard = 0;
    std::uint64_t m_64BitOne = 1;
    std::string m_startingPos = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";

    std::unordered_map<char, PieceType> fenPieceTypeMap = {
        {'P', PieceType::whitePawn},   {'R', PieceType::whiteRook},
        {'N', PieceType::whiteKnight}, {'B', PieceType::whiteBishop},
        {'Q', PieceType::whiteQueen},  {'K', PieceType::whiteKing},
        {'p', PieceType::blackPawn},   {'r', PieceType::blackRook},
        {'n', PieceType::blackKnight}, {'b', PieceType::blackBishop},
        {'q', PieceType::blackQueen},  {'k', PieceType::blackKing},
    };

    friend class Game;
};
};  // namespace ChessV2