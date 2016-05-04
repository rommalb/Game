#include "map.h"

#include <iostream>

#include "constants.h"
#include "format.h"
#include "hex.h"
#include "search.h"

namespace {
  static std::vector<sf::Vector3i> s_grid;
}

void map::build(const sf::Vector3i start, int32_t distance) {
  search::range(start, distance, s_grid);
}

void map::for_each_tile(std::function<void(const sf::Vector3i& coord)> operation) {
  for (auto grid : s_grid) {
    operation(grid);
  }
}

void map::update(const Camera& camera) {
  sf::Vector2i mouse_position = sf::Mouse::getPosition(camera.get_window());
  sf::Vector2i axial = hex::pixel_to_axial(mouse_position, HEX_SIZE);
  sf::Vector3i cube = hex::pixel_to_cube(mouse_position, HEX_SIZE);
  sf::Vector2i offset = hex::pixel_to_offset(mouse_position, HEX_SIZE);
  std::cout << "Mouse: " 
    << format::vector2(camera.get_window().mapPixelToCoords(mouse_position)) << " Axial: "
    << format::vector2(axial)  << " Cube: "
    << format::vector3(cube)   << " Offset: "
    << format::vector2(offset) << std::endl;
}