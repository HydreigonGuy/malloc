/*
** EPITECH PROJECT, 2022
** my_malloc
** File description:
** allocate_new_memory
*/

#include <unistd.h>
#include "../../include/meta_data.h"

bool move_break_if_needed(size_t old, size_t new)
{
    size_t step = getpagesize() * 2;
    size_t step_count = 1;

    for (; step_count * step < old; step_count++);
    for (; step_count * step < old + new; step_count++)
        if (!sbrk(step))
            return (false);
    return (true);
}

void *allocate_new_memory(meta_data_t *first, size_t size)
{
    size_t already_allocated = 0;
    meta_data_t *curr = first;

    for (; curr && curr->next; curr = curr->next)
        already_allocated += curr->size +
            get_closest_size(sizeof(meta_data_t));
    already_allocated += curr->size + get_closest_size(sizeof(meta_data_t));
    if (!move_break_if_needed(already_allocated, size +
        get_closest_size(sizeof(meta_data_t))))
        return (NULL);
    curr->next = create_meta_data(size,
        curr->start_ptr + curr->size, curr);
    return (curr->next->start_ptr);
}