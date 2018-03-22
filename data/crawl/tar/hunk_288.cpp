   --version  Output version info.\n\
   --help  Output this help.\n"),
 	      program_name);
-      fputs (_("\nReport bugs to <bug-tar@gnu.org>.\n"), stdout);
+      printf (_("\nReport bugs to <%s>.\n"), PACKAGE_BUGREPORT);
     }
 
   exit (status);
