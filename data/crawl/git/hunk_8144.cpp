 		die("Invalid ref name or SHA1 expression: %s", from);
 
 	read_next_command();
+	return 1;
 }
 
 static struct hash_list *cmd_merge(unsigned int *count)
