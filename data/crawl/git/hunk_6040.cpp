 	const unsigned char *bisect_rev;
 	char bisect_rev_hex[41];
 
-	bisect_common(&revs, prefix, &reaches, &all);
+	if (read_bisect_refs())
+		die("reading bisect refs failed");
+
+	bisect_rev_setup(&revs, prefix);
+
+	bisect_common(&revs, &reaches, &all);
 
 	revs.commits = filter_skipped(revs.commits, &tried, 0);
 