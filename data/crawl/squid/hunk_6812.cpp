+	- Fixed some problems related to disk (and pipe) write error
+	  handling.  file_close() doesn't always close the file
+	  immediately; i.e. when there are pending buffers to write.
+	  StoreEntry->lock_count could become zero while a write is
+	  pending, then bad things happen during the callback.
+	- The file_write() callback data must now be in the callback
+	  database (cbdata).  We now use the swapout_ctrl_t structure
+	  for the callback data; it stays around for as long as we are
+	  swapping out.
+	- Changed the way write errors are handled by diskHandleWrite.
+	  If there is no callback function, now we exit with a fatal
+	  message under the assumption that the file in question is a
+	  log file or IPC pipe.  Otherwise, we flush all the pending
+	  write buffers (so we don't see multiple repeated write errors
+	  from the same descriptor) and let the upper layer decide how
+	  to handle the failure.
+	- Fixed storeDirWriteCleanLogs.  A write failure was leaving
+	  some empty swap.state files, even though it tells us that its
+	  "not replacing the file."  Don't flush/rename logs which we
+	  have prematurely closed due to write failures, indiciated by
+	  fd[dirn] == -1.  Close these files LAST, not before
+	  renaming.
+	- Fixed storeDirClean to clean directories in a more sensible
+	  order, instead of the new "MONOTONIC" order for swap files.
+
 Changes to squid-1.2.beta14 (Feb 6, 1998):
 
 	- Replaced snmplib free() calls with xfree().