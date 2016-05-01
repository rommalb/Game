#include <SFML/Graphics.hpp>

#include "format.h"
#include "hex.h"
#include "hexagon_shape.h"

#include <iostream>
#include <sstream>

int main() {
  
  sf::RenderWindow window(sf::VideoMode(1280, 720), "Foobar");

  HexagonShape hex(50, sf::Vector2f(100.0f, 100.0f));

  while (window.isOpen()) {
    sf::Event event;
    
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();
    window.draw(hex.get_drawable());
    window.display();
  }

  // sf::Vector2i axial(0, 0);
  // sf::Vector3i cube(0, 0, 0);

  // std::cout << format::vector2(axial) << std::endl;
  // std::cout << format::vector3(cube) << std::endl;

  // std::cout << format::axial_neighbors(axial) << std::endl;
  // std::cout << format::cube_neighbors(cube) << std::endl;

  return 0;
}