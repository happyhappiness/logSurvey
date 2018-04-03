         }
         if (!doEpsv) {
             debugs(9, 5, "EPSV support manually disabled. Sending PASV for FTP Channel (" << ctrl.conn->remote <<")");
-            mb.Printf("PASV%s", Ftp::crlf);
+            mb.appendf("PASV%s", Ftp::crlf);
             state = SENT_PASV;
         } else if (Config.Ftp.epsv_all) {
             debugs(9, 5, "EPSV ALL manually enabled. Attempting with FTP Channel (" << ctrl.conn->remote <<")");
-            mb.Printf("EPSV ALL%s", Ftp::crlf);
+            mb.appendf("EPSV ALL%s", Ftp::crlf);
             state = SENT_EPSV_ALL;
         } else {
             if (ctrl.conn->local.isIPv6()) {
                 debugs(9, 5, "FTP Channel (" << ctrl.conn->remote << "). Sending default EPSV 2");
-                mb.Printf("EPSV 2%s", Ftp::crlf);
+                mb.appendf("EPSV 2%s", Ftp::crlf);
                 state = SENT_EPSV_2;
             }
             if (ctrl.conn->local.isIPv4()) {
                 debugs(9, 5, "Channel (" << ctrl.conn->remote <<"). Sending default EPSV 1");
-                mb.Printf("EPSV 1%s", Ftp::crlf);
+                mb.appendf("EPSV 1%s", Ftp::crlf);
                 state = SENT_EPSV_1;
             }
         }
