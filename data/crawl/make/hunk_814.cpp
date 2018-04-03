 	    --argc;
 	  }
 
+# ifdef __EMX__
+	pid = spawnvpe (P_NOWAIT, shell, new_argv, envp);
+	if (pid >= 0)
+          break;
+# else
 	execvp (shell, new_argv);
+# endif
 	if (errno == ENOENT)
 	  error (NILF, _("%s: Shell program not found"), shell);
 	else
