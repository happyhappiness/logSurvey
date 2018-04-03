 		if (envblk) free(envblk);
 		return -1;
 	} else {
+		if (debug_flag)
+			printf("CreateProcess(%s,%s,...)\n",
+				exec_path ? exec_path : "NULL",
+				command_line ? command_line : "NULL");
 		if (CreateProcess(
 			exec_path,
 			command_line,
