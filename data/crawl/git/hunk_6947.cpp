 static int option_parse_strategy(const struct option *opt,
 				 const char *name, int unset)
 {
-	int i;
-	struct strategy *s;
-
 	if (unset)
 		return 0;
 
-	s = get_strategy(name);
-
-	if (s)
-		append_strategy(s);
-	else {
-		struct strbuf err;
-		strbuf_init(&err, 0);
-		for (i = 0; i < ARRAY_SIZE(all_strategy); i++)
-			strbuf_addf(&err, " %s", all_strategy[i].name);
-		fprintf(stderr, "Could not find merge strategy '%s'.\n", name);
-		fprintf(stderr, "Available strategies are:%s.\n", err.buf);
-		exit(1);
-	}
+	append_strategy(get_strategy(name));
 	return 0;
 }
 
