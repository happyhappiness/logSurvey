 	  error (NILF, "*** Waiting for unfinished jobs....");
 	}
 
-#ifndef WAIT_NOHANG
-      /* We have one less dead child to reap.
+      /* We have one less dead child to reap.  As noted in
+	 child_handler() above, this count is completely unimportant for
+	 all modern, POSIX-y systems that support wait3() or waitpid().
+	 The rest of this comment below applies only to early, broken
+	 pre-POSIX systems.  We keep the count only because... it's there...
+
 	 The test and decrement are not atomic; if it is compiled into:
 	 	register = dead_children - 1;
 		dead_children = register;
