 	int i, exit_status = 0;
 
 	if (dir->ignored_nr) {
-		fprintf(stderr, ignore_error);
+		fprintf(stderr, _(ignore_error));
 		for (i = 0; i < dir->ignored_nr; i++)
 			fprintf(stderr, "%s\n", dir->ignored[i]->name);
-		fprintf(stderr, "Use -f if you really want to add them.\n");
-		die("no files added");
+		fprintf(stderr, _("Use -f if you really want to add them.\n"));
+		die(_("no files added"));
 	}
 
 	for (i = 0; i < dir->nr; i++)
