/*
** EPITECH PROJECT, 2022
** my_malloc
** File description:
** meta_data
*/

#include <stddef.h>
#include <stdbool.h>

#ifndef META_DATA_H_
    #define META_DATA_H_

    typedef struct meta_data_s {
        bool is_alloc;
        void *start_ptr;
        size_t size;
        struct meta_data_s *next;
        struct meta_data_s *prev;
    } meta_data_t;

    meta_data_t *create_meta_data(size_t, void *, meta_data_t *);
    size_t get_closest_size(size_t);

    void *check_for_already_allocated(meta_data_t *first, size_t size);
    void *allocate_new_memory(meta_data_t *first, size_t size);
    void *malloc(size_t size);
    void free(void *ptr);
    void *realloc(void *ptr, size_t size);

#endif /* !META_DATA_H_ */
