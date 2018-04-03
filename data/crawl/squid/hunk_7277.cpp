 {
     FD_ENTRY *fde;
     if (fd < 0)
-        fatal_dump("commSetSelect: bad FD");
+	fatal_dump("commSetSelect: bad FD");
     fde = &fd_table[fd];
     if (type & COMM_SELECT_READ) {
-        fde->read_handler = handler;
-        fde->read_data = client_data;
+	fde->read_handler = handler;
+	fde->read_data = client_data;
     }
     if (type & COMM_SELECT_WRITE) {
-        fde->write_handler = handler;
-        fde->write_data = client_data;
+	fde->write_handler = handler;
+	fde->write_data = client_data;
     }
     if (timeout)
-        fde->timeout = squid_curtime + timeout;
+	fde->timeout = squid_curtime + timeout;
 }
 
 void
