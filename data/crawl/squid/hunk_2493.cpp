             continue;
 
         if (entry->ifdef)
-            fprintf(fp, "#if %s\n", entry->ifdef);
+            fout << "#if " << entry->ifdef << std::endl;
 
         if (entry->default_if_none) {
-            fprintf(fp,
-                    "\tif (check_null_%s(%s)) {\n",
-                    entry->type,
-                    entry->loc);
+            fout << "\tif (check_null_" << entry->type << "(" <<
+                entry->loc << ")) {\n";
 
             for (line = entry->default_if_none; line; line = line->next)
-                fprintf(fp,
-                        "\t\tdefault_line(\"%s %s\");\n",
-                        entry->name,
-                        line->data);
+                fout << "\t\tdefault_line(\"" << entry->name << " " <<
+                    line->data <<"\");\n";
 
-            fprintf(fp, "\t}\n");
+            fout << "\t}\n";
         }
 
         if (entry->ifdef)
-            fprintf(fp, "#endif\n");
+            fout << "#endif\n";
     }
 
-    fprintf(fp, "}\n\n");
+    fout << "}\n\n";
 }
 
 void
-gen_parse_alias(char *name, EntryAlias *alias, Entry *entry, FILE *fp)
+gen_parse_alias(char *name, EntryAlias *alias, Entry *entry, std::ostream &fout)
 {
-    fprintf(fp, "\tif (!strcmp(token, \"%s\")) {\n", name);
+    fout << "\tif (!strcmp(token, \"" << name << "\")) {\n";
 
     if (strcmp(entry->type,"obsolete") == 0) {
-        fprintf(fp, "\t\tdebugs(0, DBG_CRITICAL, \"ERROR: Directive '%s' is obsolete.\");\n", name);
+        fout << "\t\tdebugs(0, DBG_CRITICAL, \"ERROR: Directive '" << name << "' is obsolete.\");\n";
         for (Line *line = entry->doc; line != NULL; line = line->next) {
             // offset line to strip initial whitespace tab byte
-            fprintf(fp, "\t\tdebugs(0, opt_parse_cfg_only?0:1, \"%s : %s\");\n", name, &line->data[1]);
+            fout << "\t\tdebugs(0, opt_parse_cfg_only?0:1, \"" << name << " : " << &line->data[1] << "\");\n";
         }
-        fprintf(fp, "\t\tparse_obsolete(token);\n");
+        fout << "\t\tparse_obsolete(token);\n";
     } else if (!entry->loc || strcmp(entry->loc, "none") == 0) {
-        fprintf(fp,
-                "\t\tparse_%s();\n",
-                entry->type
-               );
+        fout << "\t\tparse_" << entry->type << "();\n";
     } else {
-        fprintf(fp,
-                "\t\tparse_%s(&%s%s);\n",
-                entry->type, entry->loc,
-                entry->array_flag ? "[0]" : ""
-               );
+        fout << "\t\tparse_" << entry->type << "(&" << entry->loc <<
+            (entry->array_flag ? "[0]" : "") << ");\n";
     }
 
-    fprintf(fp,"\t\treturn 1;\n");
-    fprintf(fp,"\t};\n");
+    fout << "\t\treturn 1;\n";
+    fout << "\t};\n";
 }
 
 void
-gen_parse_entry(Entry *entry, FILE *fp)
+gen_parse_entry(Entry *entry, std::ostream &fout)
 {
     if (strcmp(entry->name, "comment") == 0)
         return;
 
     if (entry->ifdef)
-        fprintf(fp, "#if %s\n", entry->ifdef);
+        fout << "#if " << entry->ifdef << std::endl;
 
     char *name = entry->name;
 
