 * Return the fully-qualified refname of the tracking branch for `branch`.
 * I.e., what "branch@{upstream}" would give you. Returns NULL if no
 * upstream is defined.
 */
const char *branch_get_upstream(struct branch *branch);

/* Flags to match_refs. */
enum match_refs_flags {
