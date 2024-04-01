/*
** EPITECH PROJECT, 2022
** my_malloc
** File description:
** create_meta_data
*/

#include "../../include/meta_data.h"
#include <unistd.h>

meta_data_t *create_meta_data(size_t size, void *curr_break, meta_data_t *prev)
{
    meta_data_t *meta_data = curr_break;

    meta_data->is_alloc = true;
    meta_data->start_ptr = curr_break +
        get_closest_size(sizeof(meta_data_t));
    meta_data->size = get_closest_size(size);
    meta_data->next = NULL;
    meta_data->prev = prev;
    return (meta_data);
}