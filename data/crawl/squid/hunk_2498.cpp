             lineAdd(&def, "none");
 
         if (verbose_output && def && (entry->doc || entry->nocomment)) {
-            fprintf(fp, "#Default:\n");
+            fout << "#Default:\n";
             while (def != NULL) {
                 line = def;
                 def = line->next;
-                fprintf(fp, "# %s\n", line->data);
+                fout << "# " << line->data << std::endl;
                 xfree(line->data);
                 xfree(line);
             }
         }
 
         if (verbose_output && entry->nocomment)
-            fprintf(fp, "#\n");
+            fout << "#" << std::endl;
 
         if (enabled || verbose_output) {
             for (line = entry->nocomment; line != NULL; line = line->next) {
                 if (!line->data)
                     continue;
                 if (!enabled && line->data[0] != '#')
-                    fprintf(fp, "#%s\n", line->data);
+                    fout << "#" << line->data << std::endl;
                 else
-                    fprintf(fp, "%s\n", line->data);
+                    fout << line->data << std::endl;
             }
         }
 
         if (verbose_output && entry->doc != NULL) {
-            fprintf(fp, "\n");
+            fout << std::endl;
         }
     }
 }