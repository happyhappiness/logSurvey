 		if ('1' <= ch && ch <= '3')
 			checkout_stage = arg[0] - '0';
 		else
-			die("stage should be between 1 and 3 or all");
+			die(_("stage should be between 1 and 3 or all"));
 	}
 	return 0;
 }
