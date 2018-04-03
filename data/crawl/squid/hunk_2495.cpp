             continue;
 
         if (entry->ifdef)
-            fprintf(fp, "#if %s\n", entry->ifdef);
+            fout << "#if " << entry->ifdef << std::endl;
 
-        fprintf(fp, "\tdump_%s(entry, \"%s\", %s);\n",
-                entry->type,
-                entry->name,
-                entry->loc);
+        fout << "\tdump_" << entry->type << "(entry, \"" << entry->name <<
+            "\", " << entry->loc << ");\n";
 
         if (entry->ifdef)
-            fprintf(fp, "#endif\n");
+            fout << "#endif\n";
     }
 
-    fprintf(fp, "}\n\n");
+    fout << "}\n\n";
 }
 
 static void
-gen_free(Entry * head, FILE * fp)
+gen_free(Entry * head, std::ostream &fout)
 {
     Entry *entry;
-    fprintf(fp,
+    fout <<
             "static void\n"
             "free_all(void)\n"
             "{\n"
-            "    debugs(5, 4, HERE);\n"
-           );
+            "    debugs(5, 4, HERE);\n";
 
     for (entry = head; entry != NULL; entry = entry->next) {
         if (!entry->loc || strcmp(entry->loc, "none") == 0)
