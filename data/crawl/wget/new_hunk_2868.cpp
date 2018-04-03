
#define HYPHENP(x) (*(x) == '-' && !*((x) + 1))

char *time_str (time_t *);
char *datetime_str (time_t *);

#ifdef DEBUG_MALLOC
void print_malloc_debug_stats ();
#endif

char *xstrdup_lower (const char *);

char *strdupdelim (const char *, const char *);
char **sepstring (const char *);
int frontcmp (const char *, const char *);
void fork_to_background (void);

char *aprintf (const char *, ...) GCC_FORMAT_ATTR (1, 2);
char *concat_strings (const char *, ...);

void touch (const char *, time_t);
int remove_link (const char *);
int file_exists_p (const char *);
int file_non_directory_p (const char *);
wgint file_size (const char *);
int make_directory (const char *);
char *unique_name (const char *, int);
FILE *unique_create (const char *, int, char **);
FILE *fopen_excl (const char *, int);
char *file_merge (const char *, const char *);

int acceptable (const char *);
int accdir (const char *s, enum accd);
char *suffix (const char *s);
int match_tail (const char *, const char *, int);
int has_wildcards_p (const char *);

int has_html_suffix_p (const char *);

char *read_whole_line (FILE *);
struct file_memory *read_file (const char *);
void read_file_free (struct file_memory *);

void free_vec (char **);
char **merge_vecs (char **, char **);
char **vec_append (char **, const char *);

void string_set_add (struct hash_table *, const char *);
int string_set_contains (struct hash_table *, const char *);
void string_set_to_array (struct hash_table *, char **);
void string_set_free (struct hash_table *);
void free_keys_and_values (struct hash_table *);

char *with_thousand_seps (wgint);
char *with_thousand_seps_large (LARGE_INT);
char *human_readable (wgint);
int numdigit (wgint);
char *number_to_string (char *, wgint);
char *number_to_static_string (wgint);

int determine_screen_width (void);
int random_number (int);
double random_float (void);

int run_with_timeout (double, void (*) (void *), void *);
void xsleep (double);

/* How many bytes it will take to store LEN bytes in base64.  */
#define BASE64_LENGTH(len) (4 * (((len) + 2) / 3))

int base64_encode (const char *, int, char *);
int base64_decode (const char *, char *);

void stable_sort (void *, size_t, size_t, int (*) (const void *, const void *));

#endif /* UTILS_H */
