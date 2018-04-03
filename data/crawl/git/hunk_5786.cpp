 {
 	int rest = eol - bol;
 
-	if (opt->pre_context || opt->post_context) {
+	if (opt->pre_context || opt->post_context || opt->funcname) {
 		if (opt->last_shown == 0) {
 			if (opt->show_hunk_mark)
-				fputs("--\n", stdout);
+				fputs(opt->funcname ? "==\n" : "--\n", stdout);
 			else
 				opt->show_hunk_mark = 1;
-		} else if (lno > opt->last_shown + 1)
-			fputs("--\n", stdout);
+		} else if (lno > opt->last_shown + 1) {
+			if (opt->pre_context || opt->post_context)
+				fputs((sign == '=') ? "==\n" : "--\n", stdout);
+			else if (sign == '=')
+				fputs("==\n", stdout);
+		}
 	}
 	opt->last_shown = lno;
 