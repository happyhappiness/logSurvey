             continue;
 
         if (entry->ifdef)
-            fprintf(fp, "#if %s\n", entry->ifdef);
+            fout << "#if " << entry->ifdef << std::endl;
 
-        fprintf(fp, "\tfree_%s(&%s%s);\n",
-                entry->type, entry->loc,
-                entry->array_flag ? "[0]" : "");
+        fout << "\tfree_" << entry->type << "(&" << entry->loc <<
+            (entry->array_flag ? "[0]" : "") << ");\n";
 
         if (entry->ifdef)
-            fprintf(fp, "#endif\n");
+            fout << "#endif\n";
     }
 
-    fprintf(fp, "}\n\n");
+    fout << "}\n\n";
 }
 
 static int
