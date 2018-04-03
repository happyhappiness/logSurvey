       if (filenames != 0)						      \
 	record_files (filenames, pattern, pattern_percent, deps,	      \
 		      cmds_started, commands, commands_idx,		      \
-		      two_colon, filename, lineno,			      \
+		      two_colon, &fileinfo,				      \
 		      !(flags & RM_NO_DEFAULT_GOAL));		     	      \
       filenames = 0;							      \
       commands_idx = 0;							      \
       if (pattern) { free(pattern); pattern = 0; }                            \
     } while (0)
 
+  fileinfo.filenm = filename;
+  fileinfo.lineno = 1;
+
   pattern_percent = 0;
-  cmds_started = lineno;
+  cmds_started = fileinfo.lineno;
 
   if (debug_flag)
     {
-      printf ("Reading makefile `%s'", filename);
+      printf ("Reading makefile `%s'", fileinfo.filenm);
       if (flags & RM_NO_DEFAULT_GOAL)
 	printf (" (no default goal)");
       if (flags & RM_INCLUDED)
