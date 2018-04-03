char *aprintf (const char *, ...) GCC_FORMAT_ATTR (1, 2);
char *concat_strings (const char *, ...);

void touch (const char *, time_t);
int remove_link (const char *);
bool file_exists_p (const char *);
bool file_non_directory_p (const char *);
wgint file_size (const char *);
int make_directory (const char *);
char *unique_name (const char *, bool);
FILE *unique_create (const char *, bool, char **);
FILE *fopen_excl (const char *, int);
char *file_merge (const char *, const char *);

int fnmatch_nocase (const char *, const char *, int);
