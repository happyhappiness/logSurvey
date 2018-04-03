
/*
 * Attempt to create a temporary file at the specified `path`. Return
 * a tempfile (whose "fd" member can be used for writing to it), or
 * NULL on error. It is an error if a file already exists at that path.
 */
extern struct tempfile *create_tempfile(const char *path);

/*
 * Register an existing file as a tempfile, meaning that it will be
 * deleted when the program exits. The tempfile is considered closed,
 * but it can be worked with like any other closed tempfile (for
 * example, it can be opened using reopen_tempfile()).
 */
extern struct tempfile *register_tempfile(const char *path);


/*
