#ifndef STRING_BUILDER_H
#define STRING_BUILDER_H

#include <stdbool.h>
#include <stddef.h>

/*
 * This is a string builder.
 * We often need simple operations like
 * - append one character
 * - append a string
 * without thinking about managing memory for that.
 * More so, C standard library is slow at that because
 * C strings are null terminated, so to append a char
 * one needs to walk through a string to find where
 * do it end and then append character.
 *
 * So we implement custom string builder which solves
 * this problem. To do it it stores additional data:
 * capacity and length.
 *
 * Length is the length of a string,
 * capacity is the allocated amount of memory.
 *
 * We implement growth strategy too.
 * It aims to reserve `growth factor` times more memory than was
 * at the previous allocation time.
 *
 * Every string builder has minimum capacity.
 *
 * Be careful to choose three values:
 * - STRING_BUILDER_MIN_CAPACITY
 * - STRING_BUILDER_GROWTH_FACTOR_NUMERATOR
 * - STRING_BUILDER_GROWTH_FACTOR_DENOMINATOR
 * such that min_capacity * numerator / denominator > min_capacity.
 */

#define STRING_BUILDER_MIN_CAPACITY 16
#define STRING_BUILDER_GROWTH_FACTOR_NUMERATOR 3
#define STRING_BUILDER_GROWTH_FACTOR_DENOMINATOR 2

struct string_builder {
	char *string;
	size_t capacity;
	size_t size;
};

struct string_builder string_builder_empty(void);

bool string_builder_init(struct string_builder *sb);

bool string_builder_append_char(struct string_builder *sb, char c);
bool string_builder_append_string(struct string_builder *sb, const char *s);

char *string_builder_get_string(struct string_builder *sb);

void string_builder_drop(struct string_builder *sb);

#endif
