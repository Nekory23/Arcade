/*
** EPITECH PROJECT, 2021
** Bootstrap_Arcade
** File description:
** main
*/

#include <dlfcn.h>
#include <stdio.h>

static const char *ENTRY = "entryPoint";

int open_libs(int ac, char **av, void *handle[])
{
    for (int i = 0; i != ac - 1; i++) {
        handle[i] = dlopen(av[i + 1], RTLD_LAZY);
        if (!handle[i]) {
            dprintf(2, "Error dlopen : %s\n", dlerror());
            return 84;
        }
    }
    return 0;
}

int load_libs(int ac, char **av, void *handle[])
{
    void (*func[ac])(void);
    char *error[ac];

    for (int i = 0; i != ac - 1; i++) {
        *(void**)(&func[i]) = dlsym(handle[i], ENTRY);
        error[i] = dlerror();
        if (error[i]) {
            dprintf(2, "Error dlsym: %s\n", dlerror());
            return 84;
        }
        (*func[i])();
    }
    return 0;
}

int close_libs(int ac, void *handle[])
{
    for (int i = 0; i != ac - 1; i++) {
        if (dlclose(handle[i]) == -1)
            dprintf(2, "Error dlclose : %s\n", dlerror());
    }
    return 0;
}

int main(int ac, char **av)
{
    void *handle[ac];

    if (open_libs(ac, av, handle) == 84 || load_libs(ac, av, handle) == 84)
        return 84;
    close_libs(ac, handle);
    return 0;
}