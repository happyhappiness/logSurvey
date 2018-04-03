 		}
 	}
 
+	if (opt.color && !opt.color_external)
+		builtin_grep = 1;
 	if (!opt.pattern_list)
 		die("no pattern given.");
 	if ((opt.regflags != REG_NEWLINE) && opt.fixed)
