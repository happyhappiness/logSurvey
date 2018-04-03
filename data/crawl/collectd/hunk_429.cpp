 
 {NUMBER}		{yylval.number = strtod (yytext, NULL); return (NUMBER);}
 
-{QUOTED_STRING}		{yylval.string = yytext; return (QUOTED_STRING);}
+\"{QUOTED_STRING}\"	{yylval.string = yytext; return (QUOTED_STRING);}
 {UNQUOTED_STRING}	{yylval.string = yytext; return (UNQUOTED_STRING);}
+
+\"{QUOTED_STRING}\\\n {
+	ml_pos = 0;
+
+	/* remove "\\\n" */
+	yytext[strlen (yytext) - 2] = '\0';
+
+	ml_append (yytext);
+	BEGIN (ML);
+}
+<ML>^{WHITE_SPACE}+ {/* remove leading white-space */}
+<ML>{NON_WHITE_SPACE}{QUOTED_STRING}\\\n {
+	/* remove "\\\n" */
+	yytext[strlen (yytext) - 2] = '\0';
+
+	ml_append(yytext);
+}
+<ML>{NON_WHITE_SPACE}{QUOTED_STRING}\" {
+	ml_append(yytext);
+	yylval.string = ml_buffer;
+
+	BEGIN (INITIAL);
+	return (QUOTED_STRING);
+}
 %%
+static void ml_append (char *string)
+{
+	int len = strlen (string);
+	int s;
+
+	if (ml_free <= len) {
+		ml_len += len - ml_free + 1;
+		ml_buffer = (char *)realloc (ml_buffer, ml_len);
+		if (NULL == ml_buffer)
+			YY_FATAL_ERROR ("out of dynamic memory in ml_append");
+	}
+
+	s = snprintf (ml_buffer + ml_pos, ml_free, "%s", string);
+	if ((0 > s) || (ml_free <= s))
+		YY_FATAL_ERROR ("failed to write to multiline buffer");
+
+	ml_pos += s;
+	return;
+} /* ml_append */
+