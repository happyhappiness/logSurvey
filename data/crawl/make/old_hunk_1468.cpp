#endif

extern void die ();
extern void message (), fatal (), error ();
extern void log_working_directory ();
extern void makefile_error (), makefile_fatal ();
extern void pfatal_with_name (), perror_with_name ();
extern char *savestring (), *concat ();
extern char *xmalloc (), *xrealloc ();
extern char *find_next_token (), *next_token (), *end_of_token ();
extern void collapse_continuations (), remove_comments ();
extern char *sindex (), *lindex ();
extern int alpha_compare ();
extern void print_spaces ();
extern struct dep *copy_dep_chain ();
extern char *find_char_unquote (), *find_percent ();

#ifndef	NO_ARCHIVES
extern int ar_name ();
