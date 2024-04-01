/*
** EPITECH PROJECT, 2022
** my_malloc
** File description:
** realloc
*/

#include <stddef.h>
#include <string.h>

#include "../../include/meta_data.h"

void *realloc(void *ptr, size_t size)
{
    void *ret = NULL;
    meta_data_t *meta_data = NULL;

    if (ptr == NULL)
        return (malloc(size));
    meta_data = ptr - get_closest_size(sizeof(meta_data_t));
    ret = malloc(size);
    if (ret == NULL)
        return (NULL);
    if (meta_data->size > size)
        memcpy(ret, ptr, size);
    else
        memcpy(ret, ptr, meta_data->size);
    free(ptr);
    return (ret);
}