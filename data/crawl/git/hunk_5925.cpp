 		}
 
 		if (cmd->dir && chdir(cmd->dir))
-			die("exec %s: cd to %s failed (%s)", cmd->argv[0],
-			    cmd->dir, strerror(errno));
+			die_errno("exec '%s': cd to '%s' failed", cmd->argv[0],
+			    cmd->dir);
 		if (cmd->env) {
 			for (; *cmd->env; cmd->env++) {
 				if (strchr(*cmd->env, '='))
