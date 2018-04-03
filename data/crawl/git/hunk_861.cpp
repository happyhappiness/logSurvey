 	die("Unknown command: %d", command);
 }
 
+static int is_noop(const enum todo_command command)
+{
+	return TODO_NOOP <= (size_t)command;
+}
 
 static int do_pick_commit(enum todo_command command, struct commit *commit,
 		struct replay_opts *opts)
