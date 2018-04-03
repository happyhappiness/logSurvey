/* Include broken references in a do_for_each_ref*() iteration: */
#define DO_FOR_EACH_INCLUDE_BROKEN 0x01

/*
 * Reference iterators
 *
 * A reference iterator encapsulates the state of an in-progress
 * iteration over references. Create an instance of `struct
 * ref_iterator` via one of the functions in this module.
 *
 * A freshly-created ref_iterator doesn't yet point at a reference. To
 * advance the iterator, call ref_iterator_advance(). If successful,
 * this sets the iterator's refname, oid, and flags fields to describe
 * the next reference and returns ITER_OK. The data pointed at by
 * refname and oid belong to the iterator; if you want to retain them
 * after calling ref_iterator_advance() again or calling
 * ref_iterator_abort(), you must make a copy. When the iteration has
 * been exhausted, ref_iterator_advance() releases any resources
 * assocated with the iteration, frees the ref_iterator object, and
 * returns ITER_DONE. If you want to abort the iteration early, call
 * ref_iterator_abort(), which also frees the ref_iterator object and
 * any associated resources. If there was an internal error advancing
 * to the next entry, ref_iterator_advance() aborts the iteration,
 * frees the ref_iterator, and returns ITER_ERROR.
 *
 * The reference currently being looked at can be peeled by calling
 * ref_iterator_peel(). This function is often faster than peel_ref(),
 * so it should be preferred when iterating over references.
 *
 * Putting it all together, a typical iteration looks like this:
 *
 *     int ok;
 *     struct ref_iterator *iter = ...;
 *
 *     while ((ok = ref_iterator_advance(iter)) == ITER_OK) {
 *             if (want_to_stop_iteration()) {
 *                     ok = ref_iterator_abort(iter);
 *                     break;
 *             }
 *
 *             // Access information about the current reference:
 *             if (!(iter->flags & REF_ISSYMREF))
 *                     printf("%s is %s\n", iter->refname, oid_to_hex(&iter->oid));
 *
 *             // If you need to peel the reference:
 *             ref_iterator_peel(iter, &oid);
 *     }
 *
 *     if (ok != ITER_DONE)
 *             handle_error();
 */
struct ref_iterator {
	struct ref_iterator_vtable *vtable;
	const char *refname;
	const struct object_id *oid;
	unsigned int flags;
};

/*
 * Advance the iterator to the first or next item and return ITER_OK.
 * If the iteration is exhausted, free the resources associated with
 * the ref_iterator and return ITER_DONE. On errors, free the iterator
 * resources and return ITER_ERROR. It is a bug to use ref_iterator or
 * call this function again after it has returned ITER_DONE or
 * ITER_ERROR.
 */
int ref_iterator_advance(struct ref_iterator *ref_iterator);

/*
 * If possible, peel the reference currently being viewed by the
 * iterator. Return 0 on success.
 */
int ref_iterator_peel(struct ref_iterator *ref_iterator,
		      struct object_id *peeled);

/*
 * End the iteration before it has been exhausted, freeing the
 * reference iterator and any associated resources and returning
 * ITER_DONE. If the abort itself failed, return ITER_ERROR.
 */
int ref_iterator_abort(struct ref_iterator *ref_iterator);

/*
 * An iterator over nothing (its first ref_iterator_advance() call
 * returns ITER_DONE).
 */
struct ref_iterator *empty_ref_iterator_begin(void);

/*
 * Return true iff ref_iterator is an empty_ref_iterator.
 */
int is_empty_ref_iterator(struct ref_iterator *ref_iterator);

/*
 * A callback function used to instruct merge_ref_iterator how to
 * interleave the entries from iter0 and iter1. The function should
 * return one of the constants defined in enum iterator_selection. It
 * must not advance either of the iterators itself.
 *
 * The function must be prepared to handle the case that iter0 and/or
 * iter1 is NULL, which indicates that the corresponding sub-iterator
 * has been exhausted. Its return value must be consistent with the
 * current states of the iterators; e.g., it must not return
 * ITER_SKIP_1 if iter1 has already been exhausted.
 */
typedef enum iterator_selection ref_iterator_select_fn(
		struct ref_iterator *iter0, struct ref_iterator *iter1,
		void *cb_data);

/*
 * Iterate over the entries from iter0 and iter1, with the values
 * interleaved as directed by the select function. The iterator takes
 * ownership of iter0 and iter1 and frees them when the iteration is
 * over.
 */
struct ref_iterator *merge_ref_iterator_begin(
		struct ref_iterator *iter0, struct ref_iterator *iter1,
		ref_iterator_select_fn *select, void *cb_data);

/*
 * An iterator consisting of the union of the entries from front and
 * back. If there are entries common to the two sub-iterators, use the
 * one from front. Each iterator must iterate over its entries in
 * strcmp() order by refname for this to work.
 *
 * The new iterator takes ownership of its arguments and frees them
 * when the iteration is over. As a convenience to callers, if front
 * or back is an empty_ref_iterator, then abort that one immediately
 * and return the other iterator directly, without wrapping it.
 */
struct ref_iterator *overlay_ref_iterator_begin(
		struct ref_iterator *front, struct ref_iterator *back);

/*
 * Wrap iter0, only letting through the references whose names start
 * with prefix. If trim is set, set iter->refname to the name of the
 * reference with that many characters trimmed off the front;
 * otherwise set it to the full refname. The new iterator takes over
 * ownership of iter0 and frees it when iteration is over. It makes
 * its own copy of prefix.
 *
 * As an convenience to callers, if prefix is the empty string and
 * trim is zero, this function returns iter0 directly, without
 * wrapping it.
 */
struct ref_iterator *prefix_ref_iterator_begin(struct ref_iterator *iter0,
					       const char *prefix,
					       int trim);

/*
 * Iterate over the packed and loose references in the specified
 * submodule that are within find_containing_dir(prefix). If prefix is
 * NULL or the empty string, iterate over all references in the
 * submodule.
 */
struct ref_iterator *files_ref_iterator_begin(const char *submodule,
					      const char *prefix,
					      unsigned int flags);

/* Internal implementation of reference iteration: */

/*
 * Base class constructor for ref_iterators. Initialize the
 * ref_iterator part of iter, setting its vtable pointer as specified.
 * This is meant to be called only by the initializers of derived
 * classes.
 */
void base_ref_iterator_init(struct ref_iterator *iter,
			    struct ref_iterator_vtable *vtable);

/*
 * Base class destructor for ref_iterators. Destroy the ref_iterator
 * part of iter and shallow-free the object. This is meant to be
 * called only by the destructors of derived classes.
 */
void base_ref_iterator_free(struct ref_iterator *iter);

/* Virtual function declarations for ref_iterators: */

typedef int ref_iterator_advance_fn(struct ref_iterator *ref_iterator);

typedef int ref_iterator_peel_fn(struct ref_iterator *ref_iterator,
				 struct object_id *peeled);

/*
 * Implementations of this function should free any resources specific
 * to the derived class, then call base_ref_iterator_free() to clean
 * up and free the ref_iterator object.
 */
typedef int ref_iterator_abort_fn(struct ref_iterator *ref_iterator);

struct ref_iterator_vtable {
	ref_iterator_advance_fn *advance;
	ref_iterator_peel_fn *peel;
	ref_iterator_abort_fn *abort;
};

/*
 * Call fn for each reference in the specified submodule for which the
 * refname begins with prefix. If trim is non-zero, then trim that