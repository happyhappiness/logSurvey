 	assert(entry->name);
 	if (entry->loc == NULL) {
 	    fprintf(stderr, "NO LOCATION FOR %s\n", entry->name);
+	    rc |= 1;
 	    continue;
 	}
 	if (entry->default_value == NULL) {
 	    fprintf(stderr, "NO DEFAULT FOR %s\n", entry->name);
+	    rc |= 1;
 	    continue;
 	}
-#ifdef OLD
-	if (!strcmp(entry->type, "string")) {
-	    fprintf(fp, "\t%s = xstrdup(\"%s\");\n",
-		entry->loc, entry->default_value);
-	} else if (!strcmp(entry->type, "string_optional")) {
-	    fprintf(fp, "\t%s = xstrdup(\"%s\");\n",
-		entry->loc, entry->default_value);
-	} else if (!strcmp(entry->type, "pathname_check")) {
-	    fprintf(fp, "\t%s = xstrdup(\"%s\");\n",
-		entry->loc, entry->default_value);
+	assert(entry->default_value);
+	if (strcmp(entry->default_value, "none") == 0) {
+	    fprintf(fp, "\t/* No default for %s */\n", entry->name);
 	} else {
-	    fprintf(fp, "\t%s = %s;\n",
-		entry->loc, entry->default_value);
-	}
-#else
-	fprintf(fp, "\tparse_line(\"%s %s\");\n",
+	    fprintf(fp, "\tparse_line(\"%s %s\");\n",
 		entry->name,
 		entry->default_value);
-#endif
+	}
     }
     fprintf(fp, "}\n\n");
+    return rc;
 }
 
 static void
