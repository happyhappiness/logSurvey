 	if (strcmp(entry->loc, "none") == 0)
 	    continue;
 	fprintf(fp, "\tdump_%s(entry, \"%s\", %s);\n",
-		entry->type,
-		entry->name,
-		entry->loc);
+	    entry->type,
+	    entry->name,
+	    entry->loc);
     }
     fprintf(fp, "}\n\n");
 }
