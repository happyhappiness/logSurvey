 	Line *line;
 
 	if (strcmp(entry->name, "arbtext"))
-		fprintf(fp, "#  TAG: %s", entry->name);
+	    fprintf(fp, "#  TAG: %s", entry->name);
 	if (entry->comment)
 	    fprintf(fp, "\t%s", entry->comment);
 	fprintf(fp, "\n");
