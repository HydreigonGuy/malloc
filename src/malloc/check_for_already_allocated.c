/*
** EPITECH PROJECT, 2022
** my_malloc
** File description:
** check_for_already_allocated
*/

#include "../../include/meta_data.h"

void *handle_right_size_reallocation(meta_data_t *curr, size_t size,
int *closest_size)
{
    if (curr->size == size) {
        curr->is_alloc = true;
        return (curr->start_ptr);
    }
    if ((*closest_size == 0 || *closest_size > curr->size) &&
        curr->size > size + get_closest_size(sizeof(meta_data_t)))
        *closest_size = curr->size;
    return (NULL);
}

void *split_meta_data(meta_data_t *meta_data, size_t size)
{
    meta_data_t *new = create_meta_data(size,
        meta_data->start_ptr + meta_data->size - size -
        get_closest_size(sizeof(meta_data_t)),
        meta_data);

    meta_data->size -= size +
        get_closest_size(sizeof(meta_data_t));
    new->next = meta_data->next;
    meta_data->next = new;
    return (new->start_ptr);
}

void *handle_reallocating_closest_size(meta_data_t *first, size_t size,
int closest_size)
{
    for (meta_data_t *curr = first; curr; curr = curr->next)
        if (!curr->is_alloc && curr->size == closest_size)
            return (split_meta_data(curr, size));
    return (NULL);
}

void *check_for_already_allocated(meta_data_t *first, size_t size)
{
    int closest_size = 0;

    for (meta_data_t *curr = first; curr; curr = curr->next)
        if (!curr->is_alloc &&
        handle_right_size_reallocation(curr, size, &closest_size))
            return (curr->start_ptr);
    if (closest_size != 0)
        return (handle_reallocating_closest_size(first, size, closest_size));
    return (NULL);
}
