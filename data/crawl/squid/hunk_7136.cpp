 	    "\t} else if (!strcmp(token, \"%s\")) {\n",
 	    entry->name
 	    );
-	if (entry->loc == NULL) {
+	assert(entry->loc);
+	if (strcmp(entry->loc, "none") == 0) {
 	    fprintf(fp,
 		"\t\tparse_%s();\n",
 		entry->type
