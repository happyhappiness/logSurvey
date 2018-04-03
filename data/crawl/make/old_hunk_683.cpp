#endif

#if HAVE_ANSI_COMPILER && USE_VARIADIC && HAVE_STDARG_H
extern void message (int prefix, const char *fmt, ...)
                     __attribute__ ((__format__ (__printf__, 2, 3)));
extern void error (const struct floc *flocp, const char *fmt, ...)
                   __attribute__ ((__format__ (__printf__, 2, 3)));
extern void fatal (const struct floc *flocp, const char *fmt, ...)
                   __attribute__ ((noreturn, __format__ (__printf__, 2, 3)));
#else
extern void message ();
extern void error ();
extern void fatal ();
#endif

extern void die PARAMS ((int)) __attribute__ ((noreturn));
extern void log_working_directory PARAMS ((int));
extern void pfatal_with_name PARAMS ((const char *)) __attribute__ ((noreturn));
extern void perror_with_name PARAMS ((const char *, const char *));
extern char *savestring PARAMS ((const char *, unsigned int));
extern char *concat PARAMS ((const char *, const char *, const char *));
extern char *xmalloc PARAMS ((unsigned int));
extern char *xrealloc PARAMS ((char *, unsigned int));
extern char *xstrdup PARAMS ((const char *));
extern char *find_next_token PARAMS ((char **, unsigned int *));
extern char *next_token PARAMS ((const char *));
extern char *end_of_token PARAMS ((const char *));
extern void collapse_continuations PARAMS ((char *));
extern char *lindex PARAMS ((const char *, const char *, int));
extern int alpha_compare PARAMS ((const void *, const void *));
extern void print_spaces PARAMS ((unsigned int));
extern char *find_percent PARAMS ((char *));
extern FILE *open_tmpfile PARAMS ((char **, const char *));

#ifndef NO_ARCHIVES
extern int ar_name PARAMS ((char *));
extern void ar_parse_name PARAMS ((char *, char **, char **));
extern int ar_touch PARAMS ((char *));
extern time_t ar_member_date PARAMS ((char *));
#endif

extern int dir_file_exists_p PARAMS ((char *, char *));
extern int file_exists_p PARAMS ((char *));
extern int file_impossible_p PARAMS ((char *));
extern void file_impossible PARAMS ((char *));
extern char *dir_name PARAMS ((char *));
extern void hash_init_directories PARAMS ((void));

extern void define_default_variables PARAMS ((void));
extern void set_default_suffixes PARAMS ((void));
extern void install_default_suffix_rules PARAMS ((void));
extern void install_default_implicit_rules PARAMS ((void));

extern void build_vpath_lists PARAMS ((void));
extern void construct_vpath_list PARAMS ((char *pattern, char *dirpath));
extern int vpath_search PARAMS ((char **file, FILE_TIMESTAMP *mtime_ptr));
extern int gpath_search PARAMS ((char *file, unsigned int len));

extern void construct_include_path PARAMS ((char **arg_dirs));

extern void user_access PARAMS ((void));
extern void make_access PARAMS ((void));
extern void child_access PARAMS ((void));

extern void close_stdout PARAMS ((void));

extern char *strip_whitespace PARAMS ((const char **begpp, const char **endpp));

/* String caching  */
extern void strcache_init PARAMS ((void));
extern void strcache_print_stats PARAMS ((const char *prefix));
extern int strcache_iscached PARAMS ((const char *str));
extern const char *strcache_add PARAMS ((const char *str));
extern const char *strcache_add_len PARAMS ((const char *str, int len));
extern int strcache_setbufsize PARAMS ((int size));

#ifdef  HAVE_VFORK_H
# include <vfork.h>
