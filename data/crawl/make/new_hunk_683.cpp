#endif

#if HAVE_ANSI_COMPILER && USE_VARIADIC && HAVE_STDARG_H
void message (int prefix, const char *fmt, ...)
              __attribute__ ((__format__ (__printf__, 2, 3)));
void error (const struct floc *flocp, const char *fmt, ...)
            __attribute__ ((__format__ (__printf__, 2, 3)));
void fatal (const struct floc *flocp, const char *fmt, ...)
                   __attribute__ ((noreturn, __format__ (__printf__, 2, 3)));
#else
void message ();
void error ();
void fatal ();
#endif

void die (int) __attribute__ ((noreturn));
void log_working_directory (int);
void pfatal_with_name (const char *) __attribute__ ((noreturn));
void perror_with_name (const char *, const char *);
char *savestring (const char *, unsigned int);
char *concat (const char *, const char *, const char *);
char *xmalloc (unsigned int);
char *xrealloc (char *, unsigned int);
char *xstrdup (const char *);
char *find_next_token (char **, unsigned int *);
char *next_token (const char *);
char *end_of_token (const char *);
void collapse_continuations (char *);
char *lindex (const char *, const char *, int);
int alpha_compare (const void *, const void *);
void print_spaces (unsigned int);
char *find_percent (char *);
FILE *open_tmpfile (char **, const char *);

#ifndef NO_ARCHIVES
int ar_name (char *);
void ar_parse_name (char *, char **, char **);
int ar_touch (char *);
time_t ar_member_date (char *);
#endif

int dir_file_exists_p (char *, char *);
int file_exists_p (char *);
int file_impossible_p (char *);
void file_impossible (char *);
char *dir_name (char *);
void hash_init_directories (void);

void define_default_variables (void);
void set_default_suffixes (void);
void install_default_suffix_rules (void);
void install_default_implicit_rules (void);

void build_vpath_lists (void);
void construct_vpath_list (char *pattern, char *dirpath);
int vpath_search (char **file, FILE_TIMESTAMP *mtime_ptr);
int gpath_search (char *file, unsigned int len);

void construct_include_path (char **arg_dirs);

void user_access (void);
void make_access (void);
void child_access (void);

void close_stdout (void);

char *strip_whitespace (const char **begpp, const char **endpp);

/* String caching  */
void strcache_init (void);
void strcache_print_stats (const char *prefix);
int strcache_iscached (const char *str);
const char *strcache_add (const char *str);
const char *strcache_add_len (const char *str, int len);
int strcache_setbufsize (int size);

#ifdef  HAVE_VFORK_H
# include <vfork.h>
