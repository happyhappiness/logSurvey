extern int kill(int pid, int sig);
extern int safe_stat(char *file, struct stat *sb);
extern char *end_of_token_w32();
extern int find_and_set_default_shell(char *token);

/* indicates whether or not we have Bourne shell */
extern int no_default_sh_exe;

/* is default_shell unixy? */
extern int unixy_shell;
#endif  /* WINDOWS32 */

extern void die () __attribute__ ((noreturn));
extern void message ();
extern void fatal () __attribute__ ((noreturn));
extern void error ();
extern void log_working_directory ();
extern void makefile_error ();
extern void makefile_fatal () __attribute__ ((noreturn));
extern void pfatal_with_name () __attribute__ ((noreturn));
extern void perror_with_name ();
extern char *savestring ();
extern char *concat ();
