/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** Sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include "ALibGraph.hpp"

namespace lib {
    class Sfml : public ALibGraph {
        public:
            Sfml() noexcept;
            ~Sfml() = default;
            int Menu(std::vector<std::string> game, std::vector<std::string> lib, std::vector<std::string> score) noexcept;
            void Game(std::vector<std::string> map) noexcept;
            sf::Text Createtext(sf::Vector2f pos, std::string str, int size) noexcept;
            void DisplayScore(int score) noexcept;
            int GetKey() noexcept;
            void GetKeyName() noexcept;
            std::string GetName() const noexcept;
            bool GetStatus() const noexcept ;

        protected:
        private:
            std::string _name;
            sf::RenderWindow _win;
            sf::Font _font;
            sf::Texture _textureBackground;
            sf::Sprite _background;
            sf::Clock _clock;
            sf::Time _time;
            sf::Text _select;
            int _game;
    };
}

#endif /* !SFML_HPP_ */
