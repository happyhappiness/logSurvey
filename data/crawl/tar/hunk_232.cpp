   if (time_to_start_writing || access_mode == ACCESS_WRITE)
     flush_archive ();
 
-#if !MSDOS
-
-  /* Manage to fully drain a pipe we might be reading, so to not break it on
-     the producer after the EOF block.  FIXME: one of these days, GNU tar
-     might become clever enough to just stop working, once there is no more
-     work to do, we might have to revise this area in such time.  */
-
-  if (access_mode == ACCESS_READ
-      && ! _isrmt (archive)
-      && (S_ISFIFO (archive_stat.st_mode) || S_ISSOCK (archive_stat.st_mode)))
-    while (rmtread (archive, record_start->buffer, record_size) > 0)
-      continue;
-#endif
-
+  sys_drain_input_pipe ();
+  
   if (verify_option)
     verify_volume ();
 
   if (rmtclose (archive) != 0)
     close_warn (*archive_name_cursor);
 
-#if !MSDOS
-
-  if (child_pid)
-    {
-      int wait_status;
-
-      while (waitpid (child_pid, &wait_status, 0) == -1)
-	if (errno != EINTR)
-	  {
-	    waitpid_error (use_compress_program_option);
-	    break;
-	  }
-
-      if (WIFSIGNALED (wait_status))
-	ERROR ((0, 0, _("Child died with signal %d"),
-		WTERMSIG (wait_status)));
-      else if (WEXITSTATUS (wait_status) != 0)
-	ERROR ((0, 0, _("Child returned status %d"),
-		WEXITSTATUS (wait_status)));
-    }
-#endif /* !MSDOS */
-
+  sys_wait_for_child (child_pid);
+  
   destroy_stat (&current_stat_info);
   if (save_name)
     free (save_name);
