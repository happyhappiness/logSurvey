 			die("--bare and --origin %s options are incompatible.",
 			    option_origin);
 		option_no_checkout = 1;
-		use_separate_remote = 0;
 	}
 
 	if (!option_origin)
