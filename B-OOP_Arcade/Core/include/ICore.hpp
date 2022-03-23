/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** ICore
*/

#ifndef ICORE_HPP_
#define ICORE_HPP_

namespace core {
    class ICore {
        public:
            ~ICore() = default;
            virtual void displayMenu(void) noexcept = 0;
            virtual void getGraphicLibs(char const *lib) = 0;
            virtual void getGames(void) = 0;
            virtual void loop() = 0;
            virtual std::string getCommand(void) = 0;
            virtual void writeScore(void) = 0;

        protected:
        private:
    };
}

#endif /* !ICORE_HPP_ */
