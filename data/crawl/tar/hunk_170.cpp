   exit (exit_status);
 }
 
+
+
+static void
+dec_to_env (char *envar, uintmax_t num)
+{
+  char buf[UINTMAX_STRSIZE_BOUND];
+  char *numstr;
+
+  numstr = STRINGIFY_BIGINT (num, buf);
+  setenv (envar, numstr, 1);
+}
+
+static void
+oct_to_env (char *envar, unsigned long num)
+{
+  char buf[1+1+(sizeof(unsigned long)*CHAR_BIT+2)/3];
+  
+  snprintf (buf, sizeof buf, "0%lo", num);
+  setenv (envar, buf, 1);
+}
+
+static void
+str_to_env (char *envar, char const *str)
+{
+  if (str)
+    setenv (envar, str, 1);
+  else
+    unsetenv (envar);
+}
+
+static void
+chr_to_env (char *envar, char c)
+{
+  char buf[2];
+  buf[0] = c;
+  buf[1] = 0;
+  setenv (envar, buf, 1);
+}
+
+static void
+stat_to_env (char *name, char type, struct tar_stat_info *st)
+{
+  chr_to_env ("TAR_FILETYPE", type);
+  oct_to_env ("TAR_MODE", st->stat.st_mode);
+  str_to_env ("TAR_FILENAME", name);
+  str_to_env ("TAR_REALNAME", st->file_name);
+  str_to_env ("TAR_UNAME", st->uname);
+  str_to_env ("TAR_GNAME", st->gname);
+  dec_to_env ("TAR_MTIME", st->stat.st_mtime);
+  dec_to_env ("TAR_ATIME", st->stat.st_atime);
+  dec_to_env ("TAR_CTIME", st->stat.st_ctime);
+  dec_to_env ("TAR_SIZE", st->stat.st_size);
+  dec_to_env ("TAR_UID", st->stat.st_uid);
+  dec_to_env ("TAR_GID", st->stat.st_gid);     
+
+  switch (type)
+    {
+    case 'b':
+    case 'c':
+      dec_to_env ("TAR_MINOR", minor (st->stat.st_rdev));
+      dec_to_env ("TAR_MAJOR", major (st->stat.st_rdev));
+      unsetenv ("TAR_LINKNAME");
+      break;
+
+    case 'l':
+    case 'h':
+      unsetenv ("TAR_MINOR");
+      unsetenv ("TAR_MAJOR");
+      str_to_env ("TAR_LINKNAME", st->link_name);
+      break;
+
+    default:
+      unsetenv ("TAR_MINOR");
+      unsetenv ("TAR_MAJOR");
+      unsetenv ("TAR_LINKNAME");
+      break;
+    }
+}
+
+static pid_t pid;
+static RETSIGTYPE (*pipe_handler) (int sig);
+
+int
+sys_exec_command (char *file_name, int typechar, struct tar_stat_info *st)
+{
+  int p[2];
+  char *argv[4];
+  
+  if (pipe (p))
+    {
+      pipe_error (file_name);
+      return -1;
+    }
+
+  pipe_handler = signal (SIGPIPE, SIG_IGN);
+  pid = fork ();
+
+  if (pid < 0)
+    {
+      fork_error (file_name);
+      close (p[1]);
+      close (p[0]);
+      signal (SIGPIPE, pipe_handler);
+      return -1;
+    }
+
+  if (pid != 0)
+    {
+      close (p[0]);
+      return p[1];
+    }
+
+  /* Child */
+  close (0);
+  dup (p[0]);
+  close (p[1]);
+  
+  stat_to_env (file_name, typechar, st);
+
+  argv[0] = "/bin/sh";
+  argv[1] = "-c";
+  argv[2] = to_command_option;
+  argv[3] = NULL;
+
+  execv ("/bin/sh", argv);
+
+  exec_error (file_name);
+  _exit (127);
+}
+
+void
+sys_wait_command (void)
+{
+  int status;
+  
+  if (pid < 0)
+    return;
+
+  signal (SIGPIPE, pipe_handler);
+  while (waitpid (pid, &status, 0) == -1)
+    if (errno != EINTR)
+      {
+        pid = -1;
+        waitpid_error (to_command_option);
+        return;
+      }
+
+  if (WIFEXITED (status))
+    {
+      if (!ignore_command_error_option && WEXITSTATUS (status))
+	ERROR ((0, 0, _("%lu: Child returned status %d"),
+		(unsigned long) pid, WEXITSTATUS (status)));
+    }
+  else if (WIFSIGNALED (status))
+    {
+      WARN ((0, 0, _("%lu: Child terminated on signal %d"),
+	     (unsigned long) pid, WTERMSIG (status)));
+    }
+  else
+    ERROR ((0, 0, _("%lu: Child terminated on unknown reason"),
+	    (unsigned long) pid, WTERMSIG (status)));
+
+  pid = -1;
+}
+
 #endif /* not MSDOS */
 
