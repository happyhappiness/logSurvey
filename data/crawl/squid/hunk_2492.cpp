             continue;
 
         if (entry->loc == NULL) {
-            fprintf(stderr, "NO LOCATION FOR %s\n", entry->name);
+            std::cerr << "NO LOCATION FOR " << entry->name << std::endl;
             rc |= 1;
             continue;
         }
 
         if (entry->default_value == NULL && entry->default_if_none == NULL) {
-            fprintf(stderr, "NO DEFAULT FOR %s\n", entry->name);
+            std::cerr << "NO DEFAULT FOR " << entry->name << std::endl;
             rc |= 1;
             continue;
         }
 
         if (entry->default_value == NULL || strcmp(entry->default_value, "none") == 0) {
-            fprintf(fp, "\t/* No default for %s */\n", entry->name);
+            fout << "\t/* No default for " << entry->name << " */\n";
         } else {
             if (entry->ifdef)
-                fprintf(fp, "#if %s\n", entry->ifdef);
+                fout << "#if " << entry->ifdef << std::endl;
 
-            fprintf(fp, "\tdefault_line(\"%s %s\");\n",
-                    entry->name,
-                    entry->default_value);
+            fout << "\tdefault_line(\"" << entry->name << " " << 
+                entry->default_value << "\");\n";
 
             if (entry->ifdef)
-                fprintf(fp, "#endif\n");
-        }
+                fout << "#endif\n"; }
     }
 
-    fprintf(fp, "\tcfg_filename = NULL;\n");
-    fprintf(fp, "}\n\n");
+    fout << "\tcfg_filename = NULL;\n"
+        "}\n\n";
     return rc;
 }
 
 static void
-gen_default_if_none(Entry * head, FILE * fp)
+gen_default_if_none(Entry * head, std::ostream &fout)
 {
     Entry *entry;
     Line *line;
-    fprintf(fp,
-            "static void\n"
+    fout << "static void\n"
             "defaults_if_none(void)\n"
-            "{\n"
-           );
+            "{\n";
 
     for (entry = head; entry != NULL; entry = entry->next) {
         assert(entry->name);
