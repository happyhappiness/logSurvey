 	    );
 	assert(entry->loc);
 	if (entry->ifdef)
-	    fprintf(fp, "#ifdef %s\n", entry->ifdef);
+	    fprintf(fp, "#if %s\n", entry->ifdef);
 	if (strcmp(entry->loc, "none") == 0) {
 	    fprintf(fp,
 		"\t\tparse_%s();\n",
