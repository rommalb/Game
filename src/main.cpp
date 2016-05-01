#include <SFML/Graphics.hpp>

#include "camera.h"
#include "format.h"
#include "hex.h"
#include "hexagon_shape.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(1280, 720), "Foobar");

  sf::View view;
  view.reset(sf::FloatRect(0, 0, 1280.0f, 720.0f));
  view.setViewport(sf::FloatRect(0.0f, 0.0f, 1.0f, 1.0f));

  window.setView(view);
  Camera camera(window, view);

  // Center the camera at 0, 0
  camera.move_to(sf::Vector2f(0.0f, 0.0f));

  sf::Vector2i hex(0, 0);

  HexagonShape hexagon_shape(50, hex::axial_to_pixel(hex, 50));

  while (window.isOpen()) {
    sf::Event event;
    
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();
    window.draw(hexagon_shape.get_drawable());
    window.display();
  }

  return 0;
}