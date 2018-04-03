 	if (opt->show_log_size)
 		printf("log size %i\n", len);
 
-	printf("%s%s%s", msgbuf, extra, sep);
+	if (*msgbuf)
+		printf("%s%s%s", msgbuf, extra, sep);
 	free(msgbuf);
 }
 
