 		printf("%s ",
 		       diff_unique_abbrev(p->two->sha1, abbrev));
 	}
-	printf("%s%c%s", status, inter_name_termination, path_one);
+	printf("%s%c%s", status, inter_name_termination,
+			two_paths || p->one->mode ?  path_one : path_two);
 	if (two_paths)
 		printf("%c%s", inter_name_termination, path_two);
 	putchar(line_termination);
