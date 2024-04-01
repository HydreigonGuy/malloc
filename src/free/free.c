/*
** EPITECH PROJECT, 2022
** my_malloc
** File description:
** free
*/

#include "../../include/meta_data.h"

void free(void *ptr)
{
    meta_data_t *meta_data = NULL;

    if (ptr == NULL)
        return;
    meta_data = ptr - get_closest_size(sizeof(meta_data_t));
    meta_data->is_alloc = false;
    if (meta_data->next && !meta_data->next->is_alloc) {
        meta_data->size += meta_data->next->size +
            get_closest_size(sizeof(meta_data_t));
        meta_data->next = meta_data->next->next;
        if (meta_data->next)
            meta_data->next->prev = meta_data;
    }
    if (meta_data->prev && !meta_data->prev->is_alloc) {
        meta_data->prev->size += meta_data->size +
            get_closest_size(sizeof(meta_data_t));
        meta_data->prev->next = meta_data->next;
        if (meta_data->next)
            meta_data->next->prev = meta_data->prev;
    }
}