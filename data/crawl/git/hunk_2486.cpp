 
 static void show_edge(struct commit *commit)
 {
-	printf("-%s\n", sha1_to_hex(commit->object.sha1));
+	printf("-%s\n", oid_to_hex(&commit->object.oid));
 }
 
 static void print_var_str(const char *var, const char *val)
