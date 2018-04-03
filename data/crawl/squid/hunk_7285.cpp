 void
 commSetSelect(int fd, unsigned int type, PF * handler, void *client_data, time_t timeout)
 {
-    if (fd < 0) {
-	debug_trap("commSetSelect: FD < 0");
-	return;
-    }
-    if (type & COMM_SELECT_TIMEOUT) {
-	fd_table[fd].timeout_time = (getCurrentTime() + timeout);
-	fd_table[fd].timeout_delta = timeout;
-	fd_table[fd].timeout_handler = handler;
-	fd_table[fd].timeout_data = client_data;
-	if ((timeout <= 0) && handler) {
-	    debug(5, 2, "commSetSelect: Zero timeout doesn't make sense\n");
-	}
-    }
-    if (type & COMM_SELECT_READ) {
-	fd_table[fd].read_handler = handler;
-	fd_table[fd].read_data = client_data;
-    }
-    if (type & COMM_SELECT_WRITE) {
-	fd_table[fd].write_handler = handler;
-	fd_table[fd].write_data = client_data;
-    }
-    if (type & COMM_SELECT_LIFETIME) {
-	fd_table[fd].lifetime_handler = handler;
-	fd_table[fd].lifetime_data = client_data;
-    }
-}
-
-int
-comm_get_select_handler(int fd,
-    unsigned int type,
-    void (**handler_ptr) _PARAMS((int, void *)),
-    void **client_data_ptr)
-{
-    if (type & COMM_SELECT_TIMEOUT) {
-	*handler_ptr = fd_table[fd].timeout_handler;
-	*client_data_ptr = fd_table[fd].timeout_data;
-    }
+    FD_ENTRY *fde;
+    if (fd < 0)
+        fatal_dump("commSetSelect: bad FD");
+    fde = &fd_table[fd];
     if (type & COMM_SELECT_READ) {
-	*handler_ptr = fd_table[fd].read_handler;
-	*client_data_ptr = fd_table[fd].read_data;
+        fde->read_handler = handler;
+        fde->read_data = client_data;
     }
     if (type & COMM_SELECT_WRITE) {
-	*handler_ptr = fd_table[fd].write_handler;
-	*client_data_ptr = fd_table[fd].write_data;
-    }
-    if (type & COMM_SELECT_LIFETIME) {
-	*handler_ptr = fd_table[fd].lifetime_handler;
-	*client_data_ptr = fd_table[fd].lifetime_data;
+        fde->write_handler = handler;
+        fde->write_data = client_data;
     }
-    return 0;			/* XXX What is meaningful? */
+    if (timeout)
+        fde->timeout = squid_curtime + timeout;
 }
 
 void
