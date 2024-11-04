#pragma once
#include <cstdint>

namespace ChessV2 {

enum class PieceType {
    whitePawn = 0,
    whiteRook,
    whiteKnight,
    whiteBishop,
    whiteQueen,
    whiteKing,
    blackPawn,
    blackRook,
    blackKnight,
    blackBishop,
    blackQueen,
    blackKing,

};

class Piece {
private:
    PieceType m_pieceType;

public:
    std::uint64_t m_pieceBitBoard = 0;

public:
    Piece() {
    }
    Piece(PieceType pt) : m_pieceType(pt) {
    }
    ~Piece() {
    }
    void setPieceType(PieceType pt);
};
}  // namespace ChessV2