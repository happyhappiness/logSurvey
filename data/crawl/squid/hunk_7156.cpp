     fprintf(fp, "}\n\n");
 }
 
+static void
+gen_free(Entry * head, FILE * fp)
+{
+    Entry *entry;
+    fprintf(fp,
+	"void\n"
+	"free_all(void)\n"
+	"{\n"
+	);
+    for (entry = head; entry != NULL; entry = entry->next) {
+	if (entry->loc == NULL) {
+	    fprintf(fp, "\tfree_%s();\n", entry->type);
+	} else {
+	    fprintf(fp, "\tfree_%s(&%s);\n", entry->type, entry->loc);
+	}
+    }
+    fprintf(fp, "}\n\n");
+}
+
 static void
 gen_conf(Entry * head, FILE * fp)
 {