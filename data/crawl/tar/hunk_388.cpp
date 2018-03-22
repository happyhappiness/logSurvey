 GNU `tar' saves many files together into a single tape or disk archive, and\n\
 can restore individual files from the archive.\n"),
 	     stdout);
-      printf (_("\nUsage: %s [OPTION]... [FILE]...\n"), program_name);
+      printf (_("\nUsage: %s [OPTION]... [FILE]...\n\
+\n\
+Examples:\n\
+  %s -cf archive.tar foo bar  # Create archive.tar from files foo and bar.\n\
+  %s -tvf archive.tar         # List all files in archive.tar verbosely.\n\
+  %s -xf archive.tar          # Extract all files from archive.tar.\n"),
+	     program_name, program_name, program_name, program_name);
       fputs (_("\
 \n\
 If a long option shows an argument as mandatory, then it is mandatory\n\
