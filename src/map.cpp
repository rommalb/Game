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

void map::for_each_tile(std::function<void(const sf::Vector3i& cube_coord)> operation) {
  for (auto coord : s_grid) {
    operation(coord);
  }
}

void map::update(const Camera& camera) {
  const sf::Vector2i mouse_position = sf::Mouse::getPosition(camera.get_window());
  const sf::Vector2f world_position = camera.get_window().mapPixelToCoords(mouse_position);
  const sf::Vector2i axial = hex::world_to_axial(world_position, HEX_SIZE);
  const sf::Vector3i cube = hex::world_to_cube(world_position, HEX_SIZE);
  const sf::Vector2i offset = hex::world_to_offset(world_position, HEX_SIZE);
  std::cout << "World: " << format::vector2(world_position) << " Axial: "
    << format::vector2(axial)  << " Cube: "
    << format::vector3(cube)   << " Offset: "
    << format::vector2(offset) << std::endl;
}