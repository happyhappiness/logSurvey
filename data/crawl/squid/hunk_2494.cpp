     } while (more);
 
     if (entry->ifdef)
-        fprintf(fp, "#endif\n");
+        fout << "#endif\n";
 }
 
 static void
-gen_parse(Entry * head, FILE * fp)
+gen_parse(Entry * head, std::ostream &fout)
 {
-    fprintf(fp,
+    fout <<
             "static int\n"
             "parse_line(char *buff)\n"
             "{\n"
             "\tchar\t*token;\n"
             "\tif ((token = strtok(buff, w_space)) == NULL) \n"
-            "\t\treturn 1;\t/* ignore empty lines */\n"
-           );
+            "\t\treturn 1;\t/* ignore empty lines */\n";
 
     for (Entry *entry = head; entry != NULL; entry = entry->next)
-        gen_parse_entry (entry, fp);
+        gen_parse_entry (entry, fout);
+
+    fout << "\treturn 0; /* failure */\n"
+            "}\n\n";
 
-    fprintf(fp,
-            "\treturn 0; /* failure */\n"
-            "}\n\n"
-           );
 }
 
 static void
-gen_dump(Entry * head, FILE * fp)
+gen_dump(Entry * head, std::ostream &fout)
 {
     Entry *entry;
-    fprintf(fp,
+    fout <<
             "static void\n"
             "dump_config(StoreEntry *entry)\n"
             "{\n"
-            "    debugs(5, 4, HERE);\n"
-           );
+            "    debugs(5, 4, HERE);\n";
 
     for (entry = head; entry != NULL; entry = entry->next) {
 
