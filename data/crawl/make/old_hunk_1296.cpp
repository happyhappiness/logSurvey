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
extern char *xmalloc ();
extern char *xrealloc ();
extern char *find_next_token ();
extern char *next_token ();
extern char *end_of_token ();
extern void collapse_continuations ();
extern void remove_comments ();
extern char *sindex ();
extern char *lindex ();
extern int alpha_compare ();
extern void print_spaces ();
extern struct dep *copy_dep_chain ();
extern char *find_char_unquote ();
extern char *find_percent ();

#ifndef	NO_ARCHIVES
extern int ar_name ();
extern void ar_parse_name ();
extern int ar_touch ();
extern time_t ar_member_date ();
#endif

extern void dir_load ();
extern int dir_file_exists_p ();
extern int file_exists_p ();
extern int file_impossible_p ();
extern void file_impossible ();
extern char *dir_name ();

extern void define_default_variables ();
extern void set_default_suffixes ();
extern void install_default_suffix_rules ();
extern void install_default_implicit_rules ();
extern void count_implicit_rule_limits ();
extern void convert_to_pattern ();
extern void create_pattern_rule ();

extern void build_vpath_lists ();
extern void construct_vpath_list ();
extern int vpath_search ();
extern int gpath_search ();

extern void construct_include_path ();
extern void uniquize_deps ();

extern int update_goal_chain ();
extern void notice_finished_file ();

extern void user_access ();
extern void make_access ();
extern void child_access ();

#ifdef	HAVE_VFORK_H
#include <vfork.h>
#endif

/* We omit these declarations on non-POSIX systems which define _POSIX_VERSION,
