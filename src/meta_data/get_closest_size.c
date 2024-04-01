/*
** EPITECH PROJECT, 2022
** my_malloc
** File description:
** get_closest_size
*/

#include <stddef.h>

size_t get_closest_size(size_t size)
{
    size_t ret = size / 4;

    if (size % 4 != 0)
        ret++;
    return (ret * 4);
}