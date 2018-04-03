 				continue;
 			}
 			if (show_flag(arg) && verify)
-				die("Needed a single revision");
+				die_no_single_rev(quiet);
 			continue;
 		}
 
