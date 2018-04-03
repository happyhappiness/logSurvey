 			rlines -= null_context;
 		}
 
-		fputs(c_frag, stdout);
+		printf("%s%s", line_prefix, c_frag);
 		for (i = 0; i <= num_parent; i++) putchar(combine_marker);
 		for (i = 0; i < num_parent; i++)
 			show_parent_lno(sline, lno, hunk_end, i, null_context);
