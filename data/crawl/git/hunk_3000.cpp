 	const unsigned char *bisect_rev;
 	char bisect_rev_hex[GIT_SHA1_HEXSZ + 1];
 
-	term_bad = "bad";
-	term_good = "good";
+	read_bisect_terms(&term_bad, &term_good);
 	if (read_bisect_refs())
 		die("reading bisect refs failed");
 
