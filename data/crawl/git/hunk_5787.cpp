 	printf("%.*s\n", rest, bol);
 }
 
+static int match_funcname(char *bol, char *eol)
+{
+	if (bol == eol)
+		return 0;
+	if (isalpha(*bol) || *bol == '_' || *bol == '$')
+		return 1;
+	return 0;
+}
+
+static void show_funcname_line(struct grep_opt *opt, const char *name,
+			       char *buf, char *bol, unsigned lno)
+{
+	while (bol > buf) {
+		char *eol = --bol;
+
+		while (bol > buf && bol[-1] != '\n')
+			bol--;
+		lno--;
+
+		if (lno <= opt->last_shown)
+			break;
+
+		if (match_funcname(bol, eol)) {
+			show_line(opt, bol, eol, name, lno, '=');
+			break;
+		}
+	}
+}
+
 static void show_pre_context(struct grep_opt *opt, const char *name, char *buf,
 			     char *bol, unsigned lno)
 {
-	unsigned cur = lno, from = 1;
+	unsigned cur = lno, from = 1, funcname_lno = 0;
+	int funcname_needed = opt->funcname;
 
 	if (opt->pre_context < lno)
 		from = lno - opt->pre_context;
