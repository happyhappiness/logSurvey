         if (verbose_output && entry->nocomment)
             fprintf(fp, "#\n");
 
-	if (enabled || verbose_output) {
-	    for (line = entry->nocomment; line != NULL; line = line->next) {
-		if (!enabled && line->data[0] != '#')
-		    fprintf(fp, "#%s\n", line->data);
-		else
-		    fprintf(fp, "%s\n", line->data);
-	    }
-	}
+        if (enabled || verbose_output) {
+            for (line = entry->nocomment; line != NULL; line = line->next) {
+                if (!enabled && line->data[0] != '#')
+                    fprintf(fp, "#%s\n", line->data);
+                else
+                    fprintf(fp, "%s\n", line->data);
+            }
+        }
 
         if (verbose_output && entry->doc != NULL) {
             fprintf(fp, "\n");