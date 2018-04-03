  * Make sure the format string is well formed, and parse out
  * the used atoms.
  */
-static void verify_format(const char *format)
+static int verify_format(const char *format)
 {
 	const char *cp, *sp;
 	for (cp = format; *cp && (sp = find_next(cp)); ) {
 		const char *ep = strchr(sp, ')');
 		if (!ep)
-			die("malformatted format string %s", sp);
+			return error("malformatted format string %s", sp);
 		/* sp points at "%(" and ep points at the closing ")" */
 		parse_atom(sp + 2, ep);
 		cp = ep + 1;
 	}
+	return 0;
 }
 
 /*
