     if (x < 0)
 	perror("write");
     if (debug)
-    fprintf(stderr, "dispatched URL to thing PID %d, %d bytes\n", (int) t->pid, x);
+	fprintf(stderr, "dispatched URL to thing PID %d, %d bytes\n", (int) t->pid, x);
     strncpy(t->url, url, URL_BUF_SZ);
     if ((s = strchr(t->url, '\n')))
 	*s = '\0';
