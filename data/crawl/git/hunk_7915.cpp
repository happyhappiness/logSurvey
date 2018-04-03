 		*arg++ = name;
 	}
 	*arg = NULL;
-	retval = spawn_prog(pgm, spawn_arg);
+	fflush(NULL);
+	retval = run_command_v_opt(spawn_arg, 0);
 	remove_tempfile();
 	if (retval) {
 		fprintf(stderr, "external diff died, stopping at %s.\n", name);