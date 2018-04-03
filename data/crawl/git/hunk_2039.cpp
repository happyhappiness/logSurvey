 	{
 		int err = pthread_create(&async->tid, NULL, run_thread, async);
 		if (err) {
-			error("cannot create thread: %s", strerror(err));
+			error_errno("cannot create thread");
 			goto error;
 		}
 	}