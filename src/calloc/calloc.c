/*
** EPITECH PROJECT, 2022
** my_malloc
** File description:
** calloc
*/

#include <stddef.h>
#include <string.h>

#include "../../include/meta_data.h"

void *calloc(size_t nmemb, size_t size)
{
    void *ret = malloc(nmemb * size);

    if (ret == NULL)
        return (NULL);
    memset(ret, 0, nmemb * size);
    return (ret);
}