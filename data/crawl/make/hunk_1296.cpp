 /* is default_shell unixy? */
 extern int unixy_shell;
 #endif  /* WINDOWS32 */
+
+struct floc
+  {
+    char *filenm;
+    unsigned long lineno;
+  };
+#define NILF ((struct floc *)0)
+
 
-extern void die () __attribute__ ((noreturn));
+/* Fancy processing for variadic functions in both ANSI and pre-ANSI
+   compilers.  */
+#if defined __STDC__ && __STDC__
+extern void message (int prefix, const char *fmt, ...)
+                     __attribute__ ((__format__ (__printf__, 2, 3)));
+extern void error (const struct floc *flocp, const char *fmt, ...)
+                   __attribute__ ((__format__ (__printf__, 2, 3)));
+extern void fatal (const struct floc *flocp, const char *fmt, ...)
+                   __attribute__ ((noreturn, __format__ (__printf__, 2, 3)));
+#else
 extern void message ();
-extern void fatal () __attribute__ ((noreturn));
 extern void error ();
-extern void log_working_directory ();
-extern void makefile_error ();
-extern void makefile_fatal () __attribute__ ((noreturn));
-extern void pfatal_with_name () __attribute__ ((noreturn));
-extern void perror_with_name ();
-extern char *savestring ();
-extern char *concat ();
-extern char *xmalloc ();
-extern char *xrealloc ();
-extern char *find_next_token ();
-extern char *next_token ();
-extern char *end_of_token ();
-extern void collapse_continuations ();
-extern void remove_comments ();
-extern char *sindex ();
-extern char *lindex ();
-extern int alpha_compare ();
-extern void print_spaces ();
-extern struct dep *copy_dep_chain ();
-extern char *find_char_unquote ();
-extern char *find_percent ();
-
-#ifndef	NO_ARCHIVES
-extern int ar_name ();
-extern void ar_parse_name ();
-extern int ar_touch ();
-extern time_t ar_member_date ();
-#endif
-
-extern void dir_load ();
-extern int dir_file_exists_p ();
-extern int file_exists_p ();
-extern int file_impossible_p ();
-extern void file_impossible ();
-extern char *dir_name ();
-
-extern void define_default_variables ();
-extern void set_default_suffixes ();
-extern void install_default_suffix_rules ();
-extern void install_default_implicit_rules ();
-extern void count_implicit_rule_limits ();
-extern void convert_to_pattern ();
-extern void create_pattern_rule ();
-
-extern void build_vpath_lists ();
-extern void construct_vpath_list ();
-extern int vpath_search ();
-extern int gpath_search ();
-
-extern void construct_include_path ();
-extern void uniquize_deps ();
-
-extern int update_goal_chain ();
-extern void notice_finished_file ();
-
-extern void user_access ();
-extern void make_access ();
-extern void child_access ();
-
-#ifdef	HAVE_VFORK_H
-#include <vfork.h>
+extern void fatal ();
+#endif
+
+extern void die PARAMS ((int)) __attribute__ ((noreturn));
+extern void log_working_directory PARAMS ((int));
+extern void pfatal_with_name PARAMS ((char *)) __attribute__ ((noreturn));
+extern void perror_with_name PARAMS ((char *, char *));
+extern char *savestring PARAMS ((char *, unsigned int));
+extern char *concat PARAMS ((char *, char *, char *));
+extern char *xmalloc PARAMS ((unsigned int));
+extern char *xrealloc PARAMS ((char *, unsigned int));
+extern char *find_next_token PARAMS ((char **, unsigned int *));
+extern char *next_token PARAMS ((char *));
+extern char *end_of_token PARAMS ((char *));
+extern void collapse_continuations PARAMS ((char *));
+extern void remove_comments PARAMS((char *));
+extern char *sindex PARAMS ((char *, unsigned int, char *, unsigned int));
+extern char *lindex PARAMS ((char *, char *, int));
+extern int alpha_compare PARAMS ((const void *, const void *));
+extern void print_spaces PARAMS ((unsigned int));
+extern char *find_char_unquote PARAMS ((char *, char *, int));
+extern char *find_percent PARAMS ((char *));
+
+#ifndef NO_ARCHIVES
+extern int ar_name PARAMS ((char *));
+extern void ar_parse_name PARAMS ((char *, char **, char **));
+extern int ar_touch PARAMS ((char *));
+extern time_t ar_member_date PARAMS ((char *));
+#endif
+
+extern int dir_file_exists_p PARAMS ((char *, char *));
+extern int file_exists_p PARAMS ((char *));
+extern int file_impossible_p PARAMS ((char *));
+extern void file_impossible PARAMS ((char *));
+extern char *dir_name PARAMS ((char *));
+
+extern void define_default_variables PARAMS ((void));
+extern void set_default_suffixes PARAMS ((void));
+extern void install_default_suffix_rules PARAMS ((void));
+extern void install_default_implicit_rules PARAMS ((void));
+
+extern void build_vpath_lists PARAMS ((void));
+extern void construct_vpath_list PARAMS ((char *pattern, char *dirpath));
+extern int vpath_search PARAMS ((char **file, FILE_TIMESTAMP *mtime_ptr));
+extern int gpath_search PARAMS ((char *file, int len));
+
+extern void construct_include_path PARAMS ((char **arg_dirs));
+
+extern void user_access PARAMS ((void));
+extern void make_access PARAMS ((void));
+extern void child_access PARAMS ((void));
+
+#ifdef  HAVE_VFORK_H
+# include <vfork.h>
 #endif
 
 /* We omit these declarations on non-POSIX systems which define _POSIX_VERSION,
