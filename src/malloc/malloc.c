/*
** EPITECH PROJECT, 2022
** my_malloc
** File description:
** malloc
*/

#include <unistd.h>
#include "../../include/meta_data.h"

void *malloc(size_t size)
{
    static meta_data_t *first = NULL;
    static void *new_break = NULL;
    void *current_break = sbrk(0);
    size_t allocated = 0;

    if (first == NULL) {
        for (; allocated == 0 || allocated < get_closest_size(size) +
            get_closest_size(sizeof(meta_data_t))
            && new_break != NULL; allocated += getpagesize() * 2)
            new_break = sbrk(getpagesize() * 2);
        if (new_break == NULL)
            return (NULL);
        first = create_meta_data(size, current_break, NULL);
        return (first->start_ptr);
    }
    new_break = check_for_already_allocated(first, get_closest_size(size));
    if (new_break)
        return (new_break);
    return (allocate_new_memory(first, size));
}