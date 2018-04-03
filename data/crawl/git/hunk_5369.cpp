 	else if (async->out)
 		close(async->out);
 #else
+	if (proc_in >= 0)
+		set_cloexec(proc_in);
+	if (proc_out >= 0)
+		set_cloexec(proc_out);
 	async->proc_in = proc_in;
 	async->proc_out = proc_out;
-	async->tid = (HANDLE) _beginthreadex(NULL, 0, run_thread, async, 0, NULL);
-	if (!async->tid) {
-		error("cannot create thread: %s", strerror(errno));
-		goto error;
+	{
+		int err = pthread_create(&async->tid, NULL, run_thread, async);
+		if (err) {
+			error("cannot create thread: %s", strerror(err));
+			goto error;
+		}
 	}
 #endif
 	return 0;
