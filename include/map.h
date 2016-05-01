#pragma once

// Map will be stored in axial coordinates

#include <cstdint>
#include <functional>
#include <SFML/System/Vector3.hpp>
#include <vector>

namespace map {
  void initialize(int32_t distance);
  void for_each_tile(std::function<void(const sf::Vector3i& coord)> operation);
}