 	return rc;
 }
 
+static void remove_locks(void)
+{
+	struct remote_lock *lock = remote->locks;
+
+	fprintf(stderr, "Removing remote locks...\n");
+	while (lock) {
+		unlock_remote(lock);
+		lock = lock->next;
+	}
+}
+
+static void remove_locks_on_signal(int signo)
+{
+	remove_locks();
+	signal(signo, SIG_DFL);
+	raise(signo);
+}
+
 static void remote_ls(const char *path, int flags,
 		      void (*userFunc)(struct remote_ls_ctx *ls),
 		      void *userData);
