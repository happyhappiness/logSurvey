 		}
 		*eol = ch;
 	}
-	opt->output(opt, bol, rest);
+	output_color(opt, bol, rest, line_color);
 	opt->output(opt, "\n", 1);
 }
 
