 	if (strcmp(entry->default_value, "none") == 0) {
 	    fprintf(fp, "\t/* No default for %s */\n", entry->name);
 	} else {
-	    fprintf(fp, "\tparse_line(\"%s %s\");\n",
+	    fprintf(fp, "\tdefault_line(\"%s %s\");\n",
 		entry->name,
 		entry->default_value);
 	}