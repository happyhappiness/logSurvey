 			if (chdir(work_tree_env) < 0)
 				die ("Could not chdir to %s", work_tree_env);
 			strcat(buffer, "/");
-			inside_work_tree = 1;
 			return retval;
 		}
 		if (nongit_ok) {
