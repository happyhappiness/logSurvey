char *aprintf (const char *, ...) GCC_FORMAT_ATTR (1, 2);
char *concat_strings (const char *, ...);

typedef struct file_stat_s {
  int access_err;               /* Error in accecssing file : Not present vs permission */
  ino_t st_ino;                 /* st_ino from stats() on the file before open() */
  dev_t st_dev;                 /* st_dev from stats() on the file before open() */
} file_stats_t;

void touch (const char *, time_t);
int remove_link (const char *);
bool file_exists_p (const char *, file_stats_t *);
bool file_non_directory_p (const char *);
wgint file_size (const char *);
int make_directory (const char *);
char *unique_name (const char *, bool);
FILE *unique_create (const char *, bool, char **);
FILE *fopen_excl (const char *, int);
FILE *fopen_stat (const char *, const char *, file_stats_t *);
int   open_stat  (const char *, int, mode_t, file_stats_t *);
char *file_merge (const char *, const char *);

int fnmatch_nocase (const char *, const char *, int);
