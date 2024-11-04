
#include "Chessboard.hpp"

#include "ResourceManager.hpp"

namespace ChessV2 {
void Chessboard::readFen() {
    this->readFen(this->m_startingPos);
}
void Chessboard::readFen(const std::string& fen) {
    Logger log(LogLevel::DEBUG);

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
                this->m_pieces[static_cast<int>(this->fenPieceTypeMap.at(
                    fenChar))] |= this->m_64BitOne << currBit;
                currBit--;
                break;

            case 'P':
            case 'R':
            case 'N':
            case 'B':
            case 'Q':
            case 'K':
                this->m_whiteBoard |= this->m_64BitOne << currBit;
                this->m_pieces[static_cast<int>(this->fenPieceTypeMap.at(
                    fenChar))] |= this->m_64BitOne << currBit;
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
}

void Chessboard::drawBoard(sf::RenderWindow& window) {
    for (int y = 0; y < this->m_rows; y++) {
        for (int x = 0; x < this->m_columns; x++) {
            sf::Vector2f position = sf::Vector2f(float(x * this->m_cellWidth),
                                                 float(y * this->m_cellHeight));
            sf::RectangleShape square(
                sf::Vector2f(this->m_cellWidth, this->m_cellHeight));
            square.setPosition(position);

            if ((x + y) % 2 == 0) {
                square.setFillColor(this->m_whiteSqColor);
            } else {
                square.setFillColor(this->m_blackSqColor);
            }
            window.draw(square);
        }
    }
}

void Chessboard::drawPieces(sf::RenderWindow& window) {
    std::string texturePath;
    for (auto [fenChar, type] : this->fenPieceTypeMap) {
        uint64_t bb = this->m_pieces[(int)type];
        std::bitset<64> bits(bb);
        for (int i = 0; i < bits.size(); i++) {
            if (bits[i]) {
                getTexturePath(type, &texturePath);

                int x = 7 - (i % 8);
                int y = 7 - int(i / 8);
                sf::Sprite sprite;
                sf::Vector2f position =
                    sf::Vector2f(float(x * this->m_cellWidth),
                                 float(y * this->m_cellHeight));
                sprite.setPosition(position);

                sf::Texture texture;
                texture.loadFromFile(texturePath);
                sprite.setTexture(texture);
                window.draw(sprite);
            }
        }
    }
}
};  // namespace ChessV2