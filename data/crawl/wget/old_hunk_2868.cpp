
#define HYPHENP(x) (*(x) == '-' && !*((x) + 1))

char *time_str PARAMS ((time_t *));
char *datetime_str PARAMS ((time_t *));

#ifdef DEBUG_MALLOC
void print_malloc_debug_stats ();
#endif

char *xstrdup_lower PARAMS ((const char *));

char *strdupdelim PARAMS ((const char *, const char *));
char **sepstring PARAMS ((const char *));
int frontcmp PARAMS ((const char *, const char *));
void fork_to_background PARAMS ((void));

#ifdef WGET_USE_STDARG
char *aprintf PARAMS ((const char *, ...))
     GCC_FORMAT_ATTR (1, 2);
char *concat_strings PARAMS ((const char *, ...));
#else  /* not WGET_USE_STDARG */
char *aprintf ();
char *concat_strings ();
#endif /* not WGET_USE_STDARG */

void touch PARAMS ((const char *, time_t));
int remove_link PARAMS ((const char *));
int file_exists_p PARAMS ((const char *));
int file_non_directory_p PARAMS ((const char *));
wgint file_size PARAMS ((const char *));
int make_directory PARAMS ((const char *));
char *unique_name PARAMS ((const char *, int));
FILE *unique_create PARAMS ((const char *, int, char **));
FILE *fopen_excl PARAMS ((const char *, int));
char *file_merge PARAMS ((const char *, const char *));

int acceptable PARAMS ((const char *));
int accdir PARAMS ((const char *s, enum accd));
char *suffix PARAMS ((const char *s));
int match_tail PARAMS ((const char *, const char *, int));
int has_wildcards_p PARAMS ((const char *));

int has_html_suffix_p PARAMS ((const char *));

char *read_whole_line PARAMS ((FILE *));
struct file_memory *read_file PARAMS ((const char *));
void read_file_free PARAMS ((struct file_memory *));

void free_vec PARAMS ((char **));
char **merge_vecs PARAMS ((char **, char **));
char **vec_append PARAMS ((char **, const char *));

void string_set_add PARAMS ((struct hash_table *, const char *));
int string_set_contains PARAMS ((struct hash_table *, const char *));
void string_set_to_array PARAMS ((struct hash_table *, char **));
void string_set_free PARAMS ((struct hash_table *));
void free_keys_and_values PARAMS ((struct hash_table *));

char *with_thousand_seps PARAMS ((wgint));
char *with_thousand_seps_large PARAMS ((LARGE_INT));
char *human_readable PARAMS ((wgint));
int numdigit PARAMS ((wgint));
char *number_to_string PARAMS ((char *, wgint));
char *number_to_static_string PARAMS ((wgint));

int determine_screen_width PARAMS ((void));
int random_number PARAMS ((int));
double random_float PARAMS ((void));

int run_with_timeout PARAMS ((double, void (*) (void *), void *));
void xsleep PARAMS ((double));

/* How many bytes it will take to store LEN bytes in base64.  */
#define BASE64_LENGTH(len) (4 * (((len) + 2) / 3))

int base64_encode PARAMS ((const char *, int, char *));
int base64_decode PARAMS ((const char *, char *));

void stable_sort PARAMS ((void *, size_t, size_t,
                          int (*) (const void *, const void *)));

#endif /* UTILS_H */