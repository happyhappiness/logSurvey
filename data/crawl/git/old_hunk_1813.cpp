/* Include broken references in a do_for_each_ref*() iteration: */
#define DO_FOR_EACH_INCLUDE_BROKEN 0x01

/*
 * Call fn for each reference in the specified submodule for which the
 * refname begins with prefix. If trim is non-zero, then trim that