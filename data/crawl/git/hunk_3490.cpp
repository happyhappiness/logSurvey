 
 	if (0 <= option_verbosity) {
 		if (option_bare)
-			printf(_("Cloning into bare repository '%s'...\n"), dir);
+			fprintf(stderr, _("Cloning into bare repository '%s'...\n"), dir);
 		else
-			printf(_("Cloning into '%s'...\n"), dir);
+			fprintf(stderr, _("Cloning into '%s'...\n"), dir);
 	}
 	init_db(option_template, INIT_DB_QUIET);
 	write_config(&option_config);
