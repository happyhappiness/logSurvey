 */
extern int create_tempfile(struct tempfile *tempfile, const char *path);

/*
 * Associate a stdio stream with the temporary file (which must still
 * be open). Return `NULL` (*without* deleting the file) on error. The