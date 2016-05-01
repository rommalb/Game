#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>

#include <cstdint>

namespace hex
{
  // Hexagons coordinates have 6 neighbors
  const static unsigned int NEIGHBOR_COUNT = 6;

  // Given a hexagon, the directos are:
  //        
  //  North West   / \   North East
  //  West        |   |  East
  //  South West   \ /   South East
  // 

  // Cube coordinates for hex grid must maintain equality: x + y + z = 0
  const static sf::Vector3i CUBE_DIRECTIONS[NEIGHBOR_COUNT] = {
    sf::Vector3i(1, -1, 0), // East
    sf::Vector3i(1, 0, -1), // North East
    sf::Vector3i(0, 1, -1), // North West
    sf::Vector3i(-1, 1, 0), // West
    sf::Vector3i(-1, 0, 1), // South West
    sf::Vector3i(0, -1, 1), // South East
  };

  // Axial coordinates simply drop the third coordinate of cube
  const static sf::Vector2i AXIAL_DIRECTIONS[NEIGHBOR_COUNT] = {
    sf::Vector2i(1 ,  0), // East
    sf::Vector2i(1 , -1), // North East
    sf::Vector2i(0 , -1), // North Qest
    sf::Vector2i(-1,  0), // West
    sf::Vector2i(-1,  1), // South West
    sf::Vector2i(0 ,  1), // South East
  };

  struct CubeNeighbors {
    CubeNeighbors(const sf::Vector3i& start);
    sf::Vector3i& operator[](uint32_t i) { return neighbors[i]; }
    sf::Vector3i neighbors[NEIGHBOR_COUNT];
  };

  struct AxialNeighbors {
    AxialNeighbors(const sf::Vector2i& start);
    sf::Vector2i& operator[](uint32_t i) { return neighbors[i]; }
    sf::Vector2i neighbors[NEIGHBOR_COUNT];
  };

  // Grid conversions
  sf::Vector2i cube_to_axial(const sf::Vector3i& cube_coord);
  sf::Vector3i axial_to_cube(const sf::Vector2i& hex_coord);
  sf::Vector3i grid_to_cube(const sf::Vector2i& grid);

  // Hexagon drawing helpers
  sf::Vector2f hex_corner(const sf::Vector2f center, uint32_t size, uint32_t i);
}