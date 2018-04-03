 		int ch = *eol;
 		int eflags = 0;
 
+		if (sign == ':')
+			line_color = opt->color_selected;
+		else if (sign == '-')
+			line_color = opt->color_context;
+		else if (sign == '=')
+			line_color = opt->color_function;
 		*eol = '\0';
 		while (next_match(opt, bol, eol, ctx, &match, eflags)) {
 			if (match.rm_so == match.rm_eo)
 				break;
 
-			opt->output(opt, bol, match.rm_so);
+			output_color(opt, bol, match.rm_so, line_color);
 			output_color(opt, bol + match.rm_so,
 				     match.rm_eo - match.rm_so,
 				     opt->color_match);
