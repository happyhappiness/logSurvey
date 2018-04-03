 
 static void remove_locks(void)
 {
-	struct remote_lock *lock = remote->locks;
+	struct remote_lock *lock = repo->locks;
 
 	fprintf(stderr, "Removing remote locks...\n");
 	while (lock) {
