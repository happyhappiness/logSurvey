 static unsigned __stdcall ticktack(void *dummy)
 {
 	while (WaitForSingleObject(timer_event, timer_interval) == WAIT_TIMEOUT) {
-		if (timer_fn == SIG_DFL)
-			die("Alarm");
+		if (timer_fn == SIG_DFL) {
+			if (isatty(STDERR_FILENO))
+				fputs("Alarm clock\n", stderr);
+			exit(128 + SIGALRM);
+		}
 		if (timer_fn != SIG_IGN)
 			timer_fn(SIGALRM);
 		if (one_shot)