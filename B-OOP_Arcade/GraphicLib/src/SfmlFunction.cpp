/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** SfmlMenu
*/

#include <iostream>
#include <string>
#include <vector>
#include "Sfml.hpp"

lib::Sfml::Sfml() noexcept : _win(sf::VideoMode(1920, 1080), "Arcade")
{   
    sf::Color semiTransparent(255, 255, 255, 128);

    _font.loadFromFile("./GraphicLib/res/font.ttf");
    _textureBackground.loadFromFile("./GraphicLib/res/pacman.jpg");
    _background.setTexture(_textureBackground);
    _background.setColor(semiTransparent);
    _win.isOpen();
    _name = "";
    _time = sf::seconds(0.08);
    _select = Createtext({340, 210}, "--]", 20);
    _game = 0;
}

bool lib::Sfml::GetStatus() const noexcept
{
    if (_win.isOpen())
        return true;
    return false;
}

int lib::Sfml::Menu(std::vector<std::string> game, std::vector<std::string> lib, std::vector<std::string> score) noexcept
{
    sf::Text textgame = Createtext({320, 170}, _games, 24);
    sf::Text textlib = Createtext({1280, 170}, _lib, 24);
    sf::Text textscore = Createtext({960 - (float) (_score.length() * 10), 370}, _score, 24);
    sf::Text textname = Createtext({960 - (float) (_names.length() * 6), 640}, _names, 24);
    sf::Text name = Createtext({960 - (float) (_name.length() * 6), 690}, _name, 20);
    std::vector<sf::Text> games;
    std::vector<sf::Text> libs;
    std::vector<sf::Text> scores;

    for (std::size_t i = 0; i != game.size(); i++)
        games.push_back(Createtext({320 * 1.3, (170 + (20 * ((float)i+2)))}, game[i], 20));
    for (std::size_t i = 0; i != lib.size(); i++)
        libs.push_back(Createtext({1280 * 1.1, (170 + (20 * ((float)i+2)))}, lib[i], 20));
    _win.setFramerateLimit(60);
    for (std::size_t i = 0; i != score.size(); i++)
        scores.push_back(Createtext({810, 370 + (20 * ((float)i+2))}, score[i], 20));
    sf::Event event;
    while (_win.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _win.close();
        if (event.type == sf::Event::Resized) {
            sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
            _win.setView(sf::View(visibleArea));
        }
    }
    if (_clock.getElapsedTime() > _time) {
        GetKeyName();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            return _game;
        _clock.restart();
    }
    _win.clear();
    _win.draw(_background);
    for (std::size_t i = 0; i != games.size(); i++)
        _win.draw(games[i]);
    for (std::size_t i = 0; i != libs.size(); i++)
        _win.draw(libs[i]);
    for (std::size_t i = 0; i != scores.size(); i++) {
        if (i == 10)
            break;
        _win.draw(scores[i]);
    }
    _win.draw(name);
    _win.draw(textgame);
    _win.draw(textlib);
    _win.draw(textscore);
    _win.draw(textname);
    _win.draw(_select);
    _win.display();
    return -1;
}

void lib::Sfml::GetKeyName() noexcept
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        _name.insert(_name.end(), 1, 'A');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        _name.insert(_name.end(), 1, 'B');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
        _name.insert(_name.end(), 1, 'C');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        _name.insert(_name.end(), 1, 'D');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
        _name.insert(_name.end(), 1, 'E');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
        _name.insert(_name.end(), 1, 'F');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G))
        _name.insert(_name.end(), 1, 'G');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
        _name.insert(_name.end(), 1, 'H');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
        _name.insert(_name.end(), 1, 'I');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
        _name.insert(_name.end(), 1, 'J');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        _name.insert(_name.end(), 1, 'K');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
        _name.insert(_name.end(), 1, 'L');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
        _name.insert(_name.end(), 1, 'M');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
        _name.insert(_name.end(), 1, 'N');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
        _name.insert(_name.end(), 1, 'O');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
        _name.insert(_name.end(), 1, 'P');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        _name.insert(_name.end(), 1, 'Q');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        _name.insert(_name.end(), 1, 'R');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        _name.insert(_name.end(), 1, 'S');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
        _name.insert(_name.end(), 1, 'T');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::U))
        _name.insert(_name.end(), 1, 'U');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::V))
        _name.insert(_name.end(), 1, 'V');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        _name.insert(_name.end(), 1, 'W');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        _name.insert(_name.end(), 1, 'X');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
        _name.insert(_name.end(), 1, 'Y');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        _name.insert(_name.end(), 1, 'Z');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        _name.insert(_name.end(), 1, ' ');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Dash))
        _name.insert(_name.end(), 1, '-');
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
        if (_name.size() != 0)
            _name.erase(_name.size() - 1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if (_select.getPosition() == (sf::Vector2f) {340, 210}) {
            _select.setPosition(340, 230);
            _game = 1;
        } else {
            _select.setPosition(340, 210);
            _game = 0;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (_select.getPosition() == (sf::Vector2f) {340, 230}) {
            _select.setPosition(340, 210);
            _game = 0;
        } else {
            _select.setPosition(340, 230);
            _game = 1;
        }
    }
}

void lib::Sfml::Game(std::vector<std::string> map) noexcept
{
    sf::Color blue = sf::Color::Blue;
    sf::Color black = sf::Color::Black;
    sf::Color yellow = sf::Color::Yellow;
    sf::Color pink = sf::Color::Magenta;
    sf::Event event;
    sf::RectangleShape rectangle(sf::Vector2f(50, 50));

    _win.setFramerateLimit(60);
    while (_win.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _win.close();
        if (event.type == sf::Event::Resized) {
            sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
            _win.setView(sf::View(visibleArea));
        }
    }
    _win.clear();
    for (long unsigned int i = 0; i < map.size(); i++) {
        for (long unsigned int y = 0; y < map[0].length(); y++) {
            if (map[i][y] == '*') {
                rectangle.setPosition(y * 50, i * 50);
                rectangle.setFillColor(blue);
                _win.draw(rectangle);
            }
            if (map[i][y] == ' ') {
                rectangle.setPosition(y * 50, i * 50);
                rectangle.setFillColor(black);
                _win.draw(rectangle);
            }
            if (map[i][y] == 'o') {
                rectangle.setPosition(y * 50, i * 50);
                rectangle.setFillColor(black);
                _win.draw(rectangle);
                sf::CircleShape gum(10);
                gum.setPosition(y * 50, i * 50 + 10);
                gum.setFillColor(yellow);
                _win.draw(gum);
            }
            if (map[i][y] == 'P') {
                sf::CircleShape shape(20);
                shape.setFillColor(yellow);
                shape.setPosition(y * 50, i * 50);
                _win.draw(shape);
            }
            if (map[i][y] == 'F') {
                sf::CircleShape shape(20);
                shape.setFillColor(pink);
                shape.setPosition(y * 50, i * 50);
                _win.draw(shape);
            }
        }
    }
    _win.display();
}

void lib::Sfml::DisplayScore(int score) noexcept
{
    std::string base = "Score : ";
    base.append(std::to_string(score));
 
    sf::Text scoreText = Createtext({800, 50}, base, 24);
    scoreText.setCharacterSize(50);
    _win.draw(scoreText);
    _win.display();
}

sf::Text lib::Sfml::Createtext(sf::Vector2f pos, std::string str, int size) noexcept
{
    sf::Text text;

    text.setFont(_font);
    text.setCharacterSize(size);
    text.setPosition(pos);
    text.setString(str);
    text.setFillColor(sf::Color::Black);
    text.setOutlineColor(sf::Color::White);
    text.setOutlineThickness(1);
    text.setStyle(1);
    return text;
}

int lib::Sfml::GetKey() noexcept
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        return lib::escape;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        return lib::space;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
        return lib::backspace;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        _win.close();
        return lib::arrowUp;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        _win.close();
        return lib::arrowDown;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        return lib::arrowLeft;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        return lib::arrowRight;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        return lib::Z;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        return lib::Q;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        return lib::S;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        return lib::D;
    return null;
}

std::string lib::Sfml::GetName() const noexcept
{
    return _name;
}