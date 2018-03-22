 -t, --list		list the contents of an archive\n\
 -u, --update		only append files that are newer than copy in archive\n\
 -x, --extract,\n\
-    --get		extract files from an archive\n",stdout);
+    --get		extract files from an archive\n", stdout);
 
-	fprintf(stdout, "\
+  fprintf (stdout, "\
 Other options:\n\
 --atime-preserve	don't change access times on dumped files\n\
 -b, --block-size N	block size of Nx512 bytes (default N=%d)\n", DEFBLOCKING);
-	fputs ("\
+  fputs ("\
 -B, --read-full-blocks	reblock as we read (for reading 4.2BSD pipes)\n\
 -C, --directory DIR	change to directory DIR\n\
 --checkpoint		print directory names while reading the archive\n\
-", stdout); /* KLUDGE */ fprintf(stdout, "\
+", stdout);			/* KLUDGE */
+  fprintf (stdout, "\
 -f, --file [HOSTNAME:]F	use archive file or device F (default %s)\n",
-				 DEF_AR_FILE); fputs("\
+	   DEF_AR_FILE);
+  fputs ("\
 --force-local		archive file is local even if has a colon\n\
 -F, --info-script F	run script at end of each tape (implies -M)\n\
 -G, --incremental	create/list/extract old GNU-format incremental backup\n\
