#pragma once
#include <cstdint>
#include <string>
#include <unordered_map>

#include "Logger.hpp"
#include "Piece.hpp"

namespace ChessV2 {
enum class Turn { White = 0, Black };

class Chessboard {
public:
    Chessboard() {
    }
    ~Chessboard() {
    }
    void readFen(const std::string&);

private:
    Turn m_turn = Turn::White;
    std::uint64_t m_pieces[14] = {0};
    std::uint64_t m_wholeBoard = 0;
    std::uint64_t m_whiteBoard = 0;
    std::uint64_t m_blackBoard = 0;
    std::uint64_t m_emptyBoard = 0;
    std::uint64_t m_64BitOne = 1;
};
};  // namespace ChessV2