#include "Piece.h"

Piece::Piece(colorType color) :
    pColor{color} {}

colorType Piece::getColor() {
    return pColor;
}
