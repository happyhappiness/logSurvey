 	if (!strcmp(argv[1], "run-command"))
 		exit(run_command(&proc));
 
+	jobs = atoi(argv[2]);
+	proc.argv = (const char **)argv + 3;
+
+	if (!strcmp(argv[1], "run-command-parallel"))
+		exit(run_processes_parallel(jobs, parallel_next,
+					    NULL, NULL, &proc));
+
+	if (!strcmp(argv[1], "run-command-abort"))
+		exit(run_processes_parallel(jobs, parallel_next,
+					    NULL, task_finished, &proc));
+
+	if (!strcmp(argv[1], "run-command-no-jobs"))
+		exit(run_processes_parallel(jobs, no_job,
+					    NULL, task_finished, &proc));
+
 	fprintf(stderr, "check usage\n");
 	return 1;
 }