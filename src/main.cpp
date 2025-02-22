#include <SFML/Graphics.hpp>


#define TEST_TEXT

int main() {

    auto window = sf::RenderWindow(sf::VideoMode({ 1920u, 1080u }), "CMake SFML Project");
    window.setFramerateLimit(144);

#ifdef TEST_TEXT
    sf::Font font;
    if (!font.openFromFile("arialmt.ttf")) {
        // error...
        if (window.isOpen()) {
            window.close();
        }
        return 0;
    }
    sf::Text text(font);
    text.setString("Hello world");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
#endif

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear();
#ifdef TEST_TEXT
        window.draw(text);
#endif
        window.display();
    }
}
