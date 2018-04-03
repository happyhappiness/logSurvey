 {
     fprintf(fp, "\tif (!strcmp(token, \"%s\")) {\n", name);
 
-    if (strcmp(entry->loc, "none") == 0) {
+    if (strcmp(entry->type,"obsolete") == 0) {
+        fprintf(fp, "\t\tdebugs(0, DBG_CRITICAL, \"ERROR: Directive '%s' is obsolete.\");\n", name);
+        for (Line *line = entry->doc; line != NULL; line = line->next) {
+            // offset line to strip initial whitespace tab byte
+            fprintf(fp, "\t\tdebugs(0, opt_parse_cfg_only?0:1, \"%s : %s\");\n", name, &line->data[1]);
+        }
+        fprintf(fp, "\t\tparse_obsolete(token);\n");
+    } else if (!entry->loc || strcmp(entry->loc, "none") == 0) {
         fprintf(fp,
                 "\t\tparse_%s();\n",
                 entry->type
