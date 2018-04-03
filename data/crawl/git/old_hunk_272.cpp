
/*
 * Attempt to create a temporary file at the specified `path`. Return
 * a file descriptor for writing to it, or -1 on error. It is an error
 * if a file already exists at that path.
 */
extern int create_tempfile(struct tempfile *tempfile, const char *path);

/*
 * Register an existing file as a tempfile, meaning that it will be
 * deleted when the program exits. The tempfile is considered closed,
 * but it can be worked with like any other closed tempfile (for
 * example, it can be opened using reopen_tempfile()).
 */
extern void register_tempfile(struct tempfile *tempfile, const char *path);


/*
