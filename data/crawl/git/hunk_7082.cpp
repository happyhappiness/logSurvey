 	fprintf(stderr, "usage: %s\n", *usagestr++);
 	while (*usagestr && **usagestr)
 		fprintf(stderr, "   or: %s\n", *usagestr++);
-	while (*usagestr)
-		fprintf(stderr, "    %s\n", *usagestr++);
+	while (*usagestr) {
+		fprintf(stderr, "%s%s\n",
+				**usagestr ? "    " : "",
+				*usagestr);
+		usagestr++;
+	}
 
 	if (opts->type != OPTION_GROUP)
 		fputc('\n', stderr);
