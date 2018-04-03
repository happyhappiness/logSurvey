 * Return the fully-qualified refname of the tracking branch for `branch`.
 * I.e., what "branch@{upstream}" would give you. Returns NULL if no
 * upstream is defined.
 *
 * If `err` is not NULL and no upstream is defined, a more specific error
 * message is recorded there (if the function does not return NULL, then
 * `err` is not touched).
 */
const char *branch_get_upstream(struct branch *branch, struct strbuf *err);

/* Flags to match_refs. */
enum match_refs_flags {
