 		err = pthread_create(&threads[i], NULL, run, o);
 
 		if (err)
-			die("grep: failed to create thread: %s",
+			die(_("grep: failed to create thread: %s"),
 			    strerror(err));
 	}
 }
