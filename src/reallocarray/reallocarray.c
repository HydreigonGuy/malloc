/*
** EPITECH PROJECT, 2022
** my_malloc
** File description:
** reallocarray
*/

#include <stddef.h>

#include "../../include/meta_data.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    return (realloc(ptr, nmemb * size));
}