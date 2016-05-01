#include "hex.h"

#include <cmath>

namespace {
  const static float PI = 3.1415926535897f;
}

hex::CubeNeighbors::CubeNeighbors(const sf::Vector3i& start) {
  for (uint32_t i = 0; i < NEIGHBOR_COUNT; ++i) {
    neighbors[i] = start + CUBE_DIRECTIONS[i];
  }
}

hex::AxialNeighbors::AxialNeighbors(const sf::Vector2i& start) {
  for (uint32_t i = 0; i < NEIGHBOR_COUNT; ++i) {
    neighbors[i] = start + AXIAL_DIRECTIONS[i];
  }
}

sf::Vector2i hex::cube_to_axial(const sf::Vector3i& cube_coord) {
  return sf::Vector2i(cube_coord.x, cube_coord.y);
}

sf::Vector3i hex::axial_to_cube(const sf::Vector2i& hex_coord) {
  return sf::Vector3i(hex_coord.x, hex_coord.y, -hex_coord.x - hex_coord.y);
}

// Offset coordinate conversion, every odd row we offset
sf::Vector3i hex::grid_to_cube(const sf::Vector2i& grid) {
  const uint32_t col = grid.x;
  const uint32_t row = grid.y;

  const uint32_t x = col - (row - (row & 1)) / 2;
  const uint32_t z = row;
  const uint32_t y = -x - z;

  return sf::Vector3i(x, y, z);
}

sf::Vector2f hex::hex_corner(const sf::Vector2f center, uint32_t size, uint32_t i) {
  // Corners of hex are 60 degrees apart starting at 30 degress (lower right corner)
  uint32_t angle = 60 * i + 30;
  float rad = PI / 180 * angle;
  return sf::Vector2f(center.x + size * cos(rad), center.y + size * sin(rad));
}