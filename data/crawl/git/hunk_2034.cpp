 		}
 	}
 	if (cmd->pid < 0)
-		error("cannot fork() for %s: %s", cmd->argv[0],
-			strerror(errno));
+		error_errno("cannot fork() for %s", cmd->argv[0]);
 	else if (cmd->clean_on_exit)
 		mark_child_for_cleanup(cmd->pid);
 
