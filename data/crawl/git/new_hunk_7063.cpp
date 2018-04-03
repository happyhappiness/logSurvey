
extern void release_pack_memory(size_t, int);

extern char *xstrdup(const char *str);
extern void *xmalloc(size_t size);
extern void *xmemdupz(const void *data, size_t len);
extern char *xstrndup(const char *str, size_t len);
extern void *xrealloc(void *ptr, size_t size);
extern void *xcalloc(size_t nmemb, size_t size);
extern void *xmmap(void *start, size_t length, int prot, int flags, int fd, off_t offset);
extern ssize_t xread(int fd, void *buf, size_t len);
extern ssize_t xwrite(int fd, const void *buf, size_t len);
extern int xdup(int fd);
extern FILE *xfdopen(int fd, const char *mode);
extern int xmkstemp(char *template);

static inline size_t xsize_t(off_t len)
{
