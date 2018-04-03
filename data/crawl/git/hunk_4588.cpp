 		if (rev->commit_format != CMIT_FMT_ONELINE)
 			putchar(rev->diffopt.line_termination);
 	}
-	printf("Final output: %d %s\n", nr, stage);
+	printf(_("Final output: %d %s\n"), nr, stage);
 }
 
 static struct itimerval early_output_timer;
