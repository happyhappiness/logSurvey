 	process->in = -1;
 	process->out = -1;
 	process->clean_on_exit = 1;
-	process->clean_on_exit_handler = stop_multi_file_filter;
+	process->clean_on_exit_handler = subprocess_exit_handler;
 
 	err = start_command(process);
 	if (err) {
-		error("cannot fork to run external filter '%s'", cmd);
+		error("cannot fork to run subprocess '%s'", cmd);
 		return err;
 	}
 
 	hashmap_entry_init(entry, strhash(cmd));
 
 	err = startfn(entry);
 	if (err) {
-		error("initialization for external filter '%s' failed", cmd);
-		kill_multi_file_filter(hashmap, entry);
+		error("initialization for subprocess '%s' failed", cmd);
+		subprocess_stop(hashmap, entry);
 		return err;
 	}
 
