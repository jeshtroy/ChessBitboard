#include <string>

#include "Piece.hpp"

namespace ChessV2 {
void getTexturePath(PieceType& pt, std::string* texturePath) {
    switch (pt) {
        case PieceType::whitePawn:
            *texturePath = "../resources/pieces/white-pawn.png";
            break;
        case PieceType::whiteRook:
            *texturePath = "../resources/pieces/white-rook.png";
            break;
        case PieceType::whiteKnight:
            *texturePath = "../resources/pieces/white-knight.png";
            break;
        case PieceType::whiteBishop:
            *texturePath = "../resources/pieces/white-bishop.png";
            break;
        case PieceType::whiteQueen:
            *texturePath = "../resources/pieces/white-queen.png";
            break;
        case PieceType::whiteKing:
            *texturePath = "../resources/pieces/white-king.png";
            break;
        case PieceType::blackPawn:
            *texturePath = "../resources/pieces/black-pawn.png";
            break;
        case PieceType::blackRook:
            *texturePath = "../resources/pieces/black-rook.png";
            break;
        case PieceType::blackKnight:
            *texturePath = "../resources/pieces/black-knight.png";
            break;
        case PieceType::blackBishop:
            *texturePath = "../resources/pieces/black-bishop.png";
            break;
        case PieceType::blackQueen:
            *texturePath = "../resources/pieces/black-queen.png";
            break;
        case PieceType::blackKing:
            *texturePath = "../resources/pieces/black-king.png";
            break;
        default:
            break;
    }
}
};  // namespace ChessV2