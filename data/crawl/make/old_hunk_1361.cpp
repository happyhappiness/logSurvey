extern int kill(int pid, int sig);
extern int safe_stat(char *file, struct stat *sb);
extern char *end_of_token_w32();
#endif

extern void die ();
extern void message ();
extern void fatal ();
extern void error ();
extern void log_working_directory ();
extern void makefile_error ();
extern void makefile_fatal ();
extern void pfatal_with_name ();
extern void perror_with_name ();
extern char *savestring ();
extern char *concat ();
