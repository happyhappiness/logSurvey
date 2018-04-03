 	printf("Final output: %d %s\n", nr, stage);
 }
 
-struct itimerval early_output_timer;
+static struct itimerval early_output_timer;
 
 static void log_show_early(struct rev_info *revs, struct commit_list *list)
 {
