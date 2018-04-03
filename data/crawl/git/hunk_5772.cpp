 				close_pair(fdout);
 			else if (cmd->out)
 				close(cmd->out);
-			return -ERR_RUN_COMMAND_PIPE;
+fail_pipe:
+			error("cannot create pipe for %s: %s",
+				cmd->argv[0], strerror(failed_errno));
+			errno = failed_errno;
+			return -1;
 		}
 		cmd->err = fderr[0];
 	}
