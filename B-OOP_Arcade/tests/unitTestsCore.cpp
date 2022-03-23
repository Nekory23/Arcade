/*
** EPITECH PROJECT, 2021
** arcade
** File description:
** unitTestsCore
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../Core/include/Core.hpp"
#include "../Core/include/Error.hpp"
#include "../Core/include/Arcade.hpp"

int startCore(int const ac, char const **av);

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(error, not_enough_args)
{
    const int ac = 1;
    const char *av[] = {"\0"};

    cr_assert_any_throw(core::Core Core(ac, av)); 
}

Test(error, not_enough_args_message, .init=redirect_all_stdout)
{
    const int ac = 1;
    const char *av[] = {"\0"};

    startCore(ac, av);
    cr_assert_stderr_eq_str("Error: Invalid number of arguments.\n\nUSAGE:\n    ./arcade ./lib/arcade_[name of your graphic lib].so\n");
}

Test(error, too_many_args)
{
    const int ac = 3;
    const char *av[] = {"\0", "hey", "hey"};

    cr_assert_any_throw(core::Core Core(ac, av)); 
}

Test(error, too_many_args_message, .init=redirect_all_stdout)
{
    const int ac = 3;
    const char *av[] = {"\0", "hey", "hey"};

    startCore(ac, av);
    cr_assert_stderr_eq_str("Error: Invalid number of arguments.\n\nUSAGE:\n    ./arcade ./lib/arcade_[name of your graphic lib].so\n");
}

Test(error, invalid_args)
{
    const int ac = 2;
    const char *av[2] = {"\0", "./lib/uvgudkbgsyqugcqsdyib"};

    cr_assert_any_throw(core::Core Core(ac, av)); 
}