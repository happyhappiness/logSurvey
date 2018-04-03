 	strip_suffix_mem(start, &len, is_bundle ? ".bundle" : ".git");
 
 	if (!len || (len == 1 && *start == '/'))
-	    die("No directory name could be guessed.\n"
-		"Please specify a directory on the command line");
+		die(_("No directory name could be guessed.\n"
+		      "Please specify a directory on the command line"));
 
 	if (is_bare)
 		dir = xstrfmt("%.*s.git", (int)len, start);
