        (((ch) == DIR_SEPARATOR) || ((ch) == DIR_SEPARATOR_2))
#endif /* DIR_SEPARATOR_2 */

#define XMALLOC(type, num)      ((type *) xmalloc ((num) * sizeof(type)))
#define XFREE(stale) do { \
  if (stale) { free ((void *) stale); stale = 0; } \
} while (0)

const char *program_name = NULL;

void * xmalloc (size_t num);
char * xstrdup (const char *string);
char * basename (const char *name);
char * fnqualify(const char *path);
char * strendzap(char *str, const char *pat);
void lt_fatal (const char *message, ...);

