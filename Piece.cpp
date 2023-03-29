#include "headers/Piece.h"

Piece::Piece(colorType color) :
    pColor{color} {}

colorType Piece::getColor() const {
    return pColor;
}
