 	if (status && !gpg_output.len)
 		strbuf_addstr(&gpg_output, "No signature\n");
 
-	color = diff_get_color_opt(&opt->diffopt,
-				   status ? DIFF_WHITESPACE : DIFF_FRAGINFO);
-	reset = diff_get_color_opt(&opt->diffopt, DIFF_RESET);
-
-	bol = gpg_output.buf;
-	while (*bol) {
-		eol = strchrnul(bol, '\n');
-		printf("%s%.*s%s%s", color, (int)(eol - bol), bol, reset,
-		       *eol ? "\n" : "");
-		bol = (*eol) ? (eol + 1) : eol;
-	}
+	show_sig_lines(opt, status, gpg_output.buf);
 
  out:
 	strbuf_release(&gpg_output);