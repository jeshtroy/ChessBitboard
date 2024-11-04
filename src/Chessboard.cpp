
#include "Chessboard.hpp"

namespace ChessV2 {

void Chessboard::readFen(const std::string& fen) {
    Logger log(LogLevel::DEBUG);

    std::unordered_map<char, PieceType> fenPieceTypeMap = {
        {'P', PieceType::whitePawn},   {'R', PieceType::whiteRook},
        {'N', PieceType::whiteKnight}, {'B', PieceType::whiteBishop},
        {'Q', PieceType::whiteQueen},  {'K', PieceType::whiteKing},
        {'p', PieceType::blackPawn},   {'r', PieceType::blackRook},
        {'n', PieceType::blackKnight}, {'b', PieceType::blackBishop},
        {'q', PieceType::blackQueen},  {'k', PieceType::blackKing},
    };

    int offset = 0, currBit = 63;

    for (char fenChar : fen) {
        switch (fenChar) {
            case '/':
                break;
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
                offset = (int)fenChar - 48;
                while (offset != 0) {
                    this->m_emptyBoard |= this->m_64BitOne << currBit;
                    offset--;
                    currBit--;
                }
                break;
            case 'p':
            case 'r':
            case 'n':
            case 'b':
            case 'q':
            case 'k':
                this->m_blackBoard |= this->m_64BitOne << currBit;
                this->m_pieces[static_cast<int>(fenPieceTypeMap.at(fenChar))] |=
                    this->m_64BitOne << currBit;
                currBit--;
                break;

            case 'P':
            case 'R':
            case 'N':
            case 'B':
            case 'Q':
            case 'K':
                this->m_whiteBoard |= this->m_64BitOne << currBit;
                this->m_pieces[static_cast<int>(fenPieceTypeMap.at(fenChar))] |=
                    this->m_64BitOne << currBit;
                currBit--;
                break;
            default:
                break;
        }
    }

    this->m_wholeBoard = this->m_whiteBoard | this->m_blackBoard;

    if (currBit != -1) {
        log.error("FEN Failure: Converted fen is not of length 64");
    }

    /*
    // test bit sets
    uint64_t result = m_pieces[0];
    for (int i = 1; i < 14; i++) {
        result |= this->m_pieces[i];
    }
    if (result != this->m_wholeBoard) {
        log.error("Bits don't tally up");
    }

    log.bitout(this->m_wholeBoard);
    log.bitout(this->m_blackBoard);
    log.bitout(this->m_whiteBoard);
    */
}
};  // namespace ChessV2