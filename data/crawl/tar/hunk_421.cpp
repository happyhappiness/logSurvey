 #if MSDOS
 		spawnl (P_WAIT, getenv ("COMSPEC"), "-", 0);
 #else /* not MSDOS */
-		switch (fork ())
-		  {
-		  case -1:
-		    WARN ((0, errno, _("Cannot fork!")));
-		    break;
-
-		  case 0:
-		    {
-		      const char *shell = getenv ("SHELL");
-
-		      if (shell == NULL)
-			shell = "/bin/sh";
-		      execlp (shell, "-sh", "-i", 0);
-		      FATAL_ERROR ((0, errno, _("Cannot exec a shell %s"),
-				    shell));
-		    }
-
-		  default:
+		{
+		  pid_t child = fork ();
+		  switch (child)
 		    {
-		      WAIT_T wait_status;
-
-		      wait (&wait_status);
+		    case -1:
+		      WARN ((0, errno, _("Cannot fork!")));
+		      break;
+
+		    case 0:
+		      {
+			const char *shell = getenv ("SHELL");
+			
+			if (shell == NULL)
+			  shell = "/bin/sh";
+			execlp (shell, "-sh", "-i", 0);
+			FATAL_ERROR ((0, errno, _("Cannot exec a shell %s"),
+				      shell));
+		      }
+
+		    default:
+		      {
+			int wait_status;
+			while (waitpid (child, &wait_status, 0) == -1)
+			  if (errno != EINTR)
+			    {
+			      ERROR ((0, errno,
+				      _("While waiting for child")));
+			      break;
+			    }
+		      }
+		      break;
 		    }
-		    break;
-		  }
-
-		/* FIXME: I'm not sure if that's all that has to be done
-		   here.  (jk)  */
-
+		}
 #endif /* not MSDOS */
 		break;
 	      }
