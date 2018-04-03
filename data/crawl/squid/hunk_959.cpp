     case SENT_EPSV_2: /* EPSV IPv6 failed. Try EPSV IPv4 */
         if (ctrl.conn->local.isIPv4()) {
             debugs(9, 5, "FTP Channel is IPv4 (" << ctrl.conn->remote << ") attempting EPSV 1 after EPSV ALL has failed.");
-            mb.Printf("EPSV 1%s", Ftp::crlf);
+            mb.appendf("EPSV 1%s", Ftp::crlf);
             state = SENT_EPSV_1;
             break;
         } else if (Config.Ftp.epsv_all) {
