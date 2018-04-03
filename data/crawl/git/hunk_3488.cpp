 	}
 
 	if (0 <= option_verbosity)
-		printf(_("done.\n"));
+		fprintf(stderr, _("done.\n"));
 }
 
 static const char *junk_work_tree;
