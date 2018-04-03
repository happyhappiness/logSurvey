 {
 	char *names = pprint_rename(p->one->path, p->two->path);
 
-	printf(" %s %s (%d%%)\n", renamecopy, names,
-	       (int)(0.5 + p->score * 100.0/MAX_SCORE));
+	printf(" %s %s (%d%%)\n", renamecopy, names, similarity_index(p));
 	free(names);
 	show_mode_change(p, 0);
 }
