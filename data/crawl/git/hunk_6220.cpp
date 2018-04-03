 	 * A classic recursive descent parser would do.
 	 */
 	p = opt->pattern_list;
-	opt->pattern_expression = compile_pattern_expr(&p);
+	if (p)
+		opt->pattern_expression = compile_pattern_expr(&p);
 	if (p)
 		die("incomplete pattern expression: %s", p->pattern);
 }
