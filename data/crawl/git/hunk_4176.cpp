 		printf("------\n");
 	}
 
-	if (flags & BISECT_SHOW_TRIED)
-		show_tried_revs(tried);
-
 	print_var_str("bisect_rev", hex);
 	print_var_int("bisect_nr", cnt - 1);
 	print_var_int("bisect_good", all - reaches - 1);