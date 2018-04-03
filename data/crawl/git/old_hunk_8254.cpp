extern const char *git_commit_encoding;
extern const char *git_log_output_encoding;

extern int copy_fd(int ifd, int ofd);
extern int read_in_full(int fd, void *buf, size_t count);
extern int write_in_full(int fd, const void *buf, size_t count);
