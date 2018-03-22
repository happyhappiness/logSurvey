 	     stdout);
       fputs (_("\
 \n\
+Compatibility options:\n\
+  -o                                 when creating, same as --old-archive\n\
+                                     when extracting, same as --no-same-owner\n"),
+             stdout);
+      
+      fputs (_("\
+\n\
 The backup suffix is `~', unless set with --suffix or SIMPLE_BACKUP_SUFFIX.\n\
 The version control may be set with --backup or VERSION_CONTROL, values are:\n\
 \n\
