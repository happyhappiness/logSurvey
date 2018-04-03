 
 	status = finish_command(&child_process);
 	if (status)
-		error("external filter %s failed %d", params->cmd, -status);
+		error("external filter %s failed %d", params->cmd, status);
 	return (write_err || status);
 }
 
