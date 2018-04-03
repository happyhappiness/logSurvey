   return read_makefiles;
 }
 
-/* Read file FILENAME as a makefile and add its contents to the data base.
-
-   FLAGS contains bits as above.
-
-   FILENAME is added to the `read_makefiles' chain.
-
-   Returns 0 if a file was not found or not read.
-   Returns 1 if FILENAME was found and read.
-   Returns 2 if FILENAME was read, and we kept a reference (don't free it).  */
-
-static int
-read_makefile (filename, flags)
+int
+eval_makefile (filename, flags)
      char *filename;
      int flags;
 {
-  static char *collapsed = 0;
-  static unsigned int collapsed_length = 0;
-  register FILE *infile;
-  struct linebuffer lb;
-  unsigned int commands_len = 200;
-  char *commands;
-  unsigned int commands_idx = 0;
-  unsigned int cmds_started, tgts_started;
-  char *p;
-  char *p2;
-  int len, reading_target;
-  int ignoring = 0, in_ignored_define = 0;
-  int no_targets = 0;		/* Set when reading a rule without targets.  */
-  struct floc fileinfo;
-  char *passed_filename = filename;
-
-  struct nameseq *filenames = 0;
   struct dep *deps;
-  unsigned int nlines = 0;
-  int two_colon = 0;
-  char *pattern = 0, *pattern_percent;
-
+  struct ebuffer ebuf;
+  const struct floc *curfile;
   int makefile_errno;
-#if defined (WINDOWS32) || defined (__MSDOS__)
-  int check_again;
-#endif
+  int r;
 
-#define record_waiting_files()						      \
-  do									      \
-    { 									      \
-      if (filenames != 0)						      \
-        {                                                                     \
-	  struct floc fi;                                                     \
-	  fi.filenm = fileinfo.filenm;                                        \
-	  fi.lineno = tgts_started;                                           \
-	  record_files (filenames, pattern, pattern_percent, deps,            \
-                        cmds_started, commands, commands_idx, two_colon,      \
-                        &fi, !(flags & RM_NO_DEFAULT_GOAL));                  \
-        }                                                                     \
-      filenames = 0;							      \
-      commands_idx = 0;							      \
-      if (pattern) { free(pattern); pattern = 0; }                            \
-    } while (0)
-
-  fileinfo.filenm = filename;
-  fileinfo.lineno = 1;
-
-  pattern_percent = 0;
-  cmds_started = tgts_started = fileinfo.lineno;
+  ebuf.floc.filenm = filename;
+  ebuf.floc.lineno = 1;
 
   if (ISDB (DB_VERBOSE))
     {
-      printf (_("Reading makefile `%s'"), fileinfo.filenm);
+      printf (_("Reading makefile `%s'"), filename);
       if (flags & RM_NO_DEFAULT_GOAL)
 	printf (_(" (no default goal)"));
       if (flags & RM_INCLUDED)
