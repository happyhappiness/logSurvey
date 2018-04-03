 		"\t\tparse_%s();\n",
 		entry->type
 		);
-	} else {
+	} else if (strcmp(entry->loc, "arbtext")) {
 	    fprintf(fp,
 		"\t\tparse_%s(&%s);\n",
 		entry->type, entry->loc
