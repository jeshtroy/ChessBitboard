#include <iostream>
#include <string>

#include "BitOperations.hpp"
#include "Chessboard.hpp"
#include "Logger.hpp"

int main() {
    ChessV2::Chessboard cb;
    std::string fen = "r1bk3r/p2pBpNp/n4n2/1p1NP2P/6P1/3P4/P1P1K3/q5b1";
    std::string startingPos = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
    cb.readFen(startingPos);
}
