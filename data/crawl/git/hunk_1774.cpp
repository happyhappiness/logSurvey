 		if (rev->commit_format != CMIT_FMT_ONELINE)
 			putchar(rev->diffopt.line_termination);
 	}
-	printf(_("Final output: %d %s\n"), nr, stage);
+	fprintf(rev->diffopt.file, _("Final output: %d %s\n"), nr, stage);
 }
 
 static struct itimerval early_output_timer;
