 	item->util = id;
 	fprintf(stderr, "Forgot resolution for %s\n", path);
 	return 0;
+
+fail_exit:
+	free(id);
+	return -1;
 }
 
 int rerere_forget(struct pathspec *pathspec)