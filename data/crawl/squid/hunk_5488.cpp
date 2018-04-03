 		entry->array_flag ? "[0]" : ""
 		);
 	}
-	if (alias) {
-	    name = alias->name;
-	    alias = alias->next;
-	    goto next_alias;
-	}
+	fprintf(fp,"\t\treturn 1;\n");
+	fprintf(fp,"\t};\n");
+}
+
+void
+gen_parse_entry(Entry *entry, FILE *fp)
+{
+	if (strcmp(entry->name, "comment") == 0)
+	    return;
+	if (entry->ifdef)
+	    fprintf(fp, "#if %s\n", entry->ifdef);
+	char *name = entry->name;
+	EntryAlias *alias = entry->alias;
+	assert (entry->loc);
+	bool more;
+	do {
+	    gen_parse_alias (name, alias,entry, fp);
+	    more = false;
+	    if (alias) {
+		name = alias->name;
+		alias = alias->next;
+		more = true;
+	    }
+	} while (more);
 	if (entry->ifdef)
 	    fprintf(fp, "#endif\n");
-    }
+}
+
+static void
+gen_parse(Entry * head, FILE * fp)
+{
+    fprintf(fp,
+	"static int\n"
+	"parse_line(char *buff)\n"
+	"{\n"
+	"\tchar\t*token;\n"
+	"\tdebug(0,10)(\"parse_line: %%s\\n\", buff);\n"
+	"\tif ((token = strtok(buff, w_space)) == NULL) \n"
+	"\t\treturn 1;\t/* ignore empty lines */\n"
+	);
+
+    for (Entry *entry = head; entry != NULL; entry = entry->next)
+	gen_parse_entry (entry, fp);
 
     fprintf(fp,
-	"\telse\n"
-	"\t\tresult = 0; /* failure */\n"
-	"\treturn(result);\n"
+	"\treturn 0; /* failure */\n"
 	"}\n\n"
 	);
 }