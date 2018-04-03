         else if (!strcmp(entry->name, "obsolete"))
             (void) 0;
         else if (verbose_output) {
-            fprintf(fp, "#  TAG: %s", entry->name);
+            fout << "#  TAG: " << entry->name;
 
             if (entry->comment)
-                fprintf(fp, "\t%s", entry->comment);
+                fout << "\t" << entry->comment;
 
-            fprintf(fp, "\n");
+            fout << std::endl;
         }
 
         if (!defined(entry->ifdef)) {
             if (verbose_output) {
-                fprintf(fp, "# Note: This option is only available if Squid is rebuilt with the\n");
-                fprintf(fp, "#       %s\n#\n", available_if(entry->ifdef));
+
+                fout << "# Note: This option is only available if "
+                    "Squid is rebuilt with the\n" <<
+                    "#       " << available_if(entry->ifdef) << "\n#\n";
             }
             enabled = 0;
         }
 
         if (verbose_output) {
             for (line = entry->doc; line != NULL; line = line->next) {
-                fprintf(fp, "#%s\n", line->data);
+                fout << "#" << line->data << std::endl;
             }
         }
 
