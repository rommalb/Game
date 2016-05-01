#include "map.h"

#include "search.h"

namespace {
  static std::vector<sf::Vector3i> s_grid;
}

void map::initialize(int32_t distance) {
  search::range(sf::Vector3i(0, 0, 0), distance, s_grid);
}

void map::for_each_tile(std::function<void(const sf::Vector3i& coord)> operation) {
  for (auto grid : s_grid) {
    operation(grid);
  }
}