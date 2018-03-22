 ARCHIVE may be FILE, HOST:FILE or USER@HOST:FILE; and FILE may be a file\n\
 or a device.  *This* `tar' defaults to `-f%s -b%d'.\n"),
 	      DEFAULT_ARCHIVE, DEFAULT_BLOCKING);
-      fputs (_("\
-\n\
-Report bugs to <bug-tar@gnu.org>.\n"),
-	       stdout);
+      fputs (_("\nReport bugs to <bug-tar@gnu.org>.\n"), stdout);
     }
   exit (status);
 }
