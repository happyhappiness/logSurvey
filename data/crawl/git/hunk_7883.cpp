 int cmd_help(int argc, const char **argv, const char *prefix)
 {
 	const char *help_cmd = argc > 1 ? argv[1] : NULL;
-	const char *exec_path = git_exec_path();
 
 	if (!help_cmd) {
 		printf("usage: %s\n\n", git_usage_string);
