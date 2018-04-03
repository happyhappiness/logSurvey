 	}
 	assert(entry->default_value);
 	if (entry->ifdef)
-	    fprintf(fp, "#ifdef %s\n", entry->ifdef);
+	    fprintf(fp, "#if %s\n", entry->ifdef);
 	if (strcmp(entry->default_value, "none") == 0) {
 	    fprintf(fp, "\t/* No default for %s */\n", entry->name);
 	} else {
