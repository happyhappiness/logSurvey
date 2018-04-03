/**
 * Read the contents of a file, specified by its path. The third argument
 * can be used to give a hint about the file size, to avoid reallocs.
 */
extern ssize_t strbuf_read_file(struct strbuf *sb, const char *path, size_t hint);
