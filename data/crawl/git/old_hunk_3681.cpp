/* Include broken references in a do_for_each_ref*() iteration: */
#define DO_FOR_EACH_INCLUDE_BROKEN 0x01

/*
 * current_ref is a performance hack: when iterating over references
 * using the for_each_ref*() functions, current_ref is set to the
