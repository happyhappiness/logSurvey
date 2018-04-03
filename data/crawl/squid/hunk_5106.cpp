 
         if (!defined(entry->ifdef)) {
             fprintf(fp, "# Note: This option is only available if Squid is rebuilt with the\n");
-            fprintf(fp, "#       %s option\n#\n", available_if(entry->ifdef));
+            fprintf(fp, "#       %s\n#\n", available_if(entry->ifdef));
         }
 
         for (line = entry->doc; line != NULL; line = line->next) {
