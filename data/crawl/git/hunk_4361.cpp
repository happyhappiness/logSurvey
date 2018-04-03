 				fputs(line, stdout);
 				fflush(stdout);
 			}
-			else
+			else {
 				diff_tree_stdin(line);
+				if (saved_nrl < opt->diffopt.needed_rename_limit)
+					saved_nrl = opt->diffopt.needed_rename_limit;
+				if (opt->diffopt.degraded_cc_to_c)
+					saved_dcctc = 1;
+			}
 		}
+		opt->diffopt.degraded_cc_to_c = saved_dcctc;
+		opt->diffopt.needed_rename_limit = saved_nrl;
 	}
 
 	return diff_result_code(&opt->diffopt, 0);
