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

sf::Vector2f hex::hex_corner(const sf::Vector2f center, uint32_t size, uint32_t i) {
  // Corners of hex are 60 degrees apart starting at 30 degress (lower right corner)
  const uint32_t angle = 60 * i + 30;
  const float rad = PI / 180 * angle;
  return sf::Vector2f(center.x + size * cos(rad), center.y + size * sin(rad));
}

sf::Vector2f hex::axial_to_pixel(sf::Vector2i hex_coord, uint32_t size) {
  const float x = size * sqrt(3) * (hex_coord.x + hex_coord.y / 2);
  const float y = size * (3 / 2) * hex_coord.y;
  return sf::Vector2f(x, y);
}

sf::Vector2i hex::pixel_to_axial(sf::Vector2f pixel, uint32_t size) {
  const float x = (pixel.x * (sqrt(3) / 3) - pixel.y / 3) / size;
  const float y = pixel.y * (2 / 3) / size;
  return sf::Vector2i(static_cast<int32_t>(roundf(x)), static_cast<int32_t>(roundf(y)));
}