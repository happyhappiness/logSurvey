 	assert(entry->loc);
 	if (strcmp(entry->loc, "none") == 0)
 	    continue;
+	if (strcmp(entry->name, "arbtext") == 0)
+	    continue;
 	fprintf(fp, "\tdump_%s(entry, \"%s\", %s);\n",
 	    entry->type,
 	    entry->name,
