 		}
 
 		if (cmd->dir && chdir(cmd->dir))
-			die_errno("exec '%s': cd to '%s' failed", cmd->argv[0],
-			    cmd->dir);
+			child_die(CHILD_ERR_CHDIR);
 
 		/*
 		 * Attempt to exec using the command and arguments starting at
