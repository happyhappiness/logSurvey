             mustStop("pconn race");
             return;
         }
-    } else {
-
-        al.icap.bytesRead+=io.size;
-
-        updateTimeout();
-
-        debugs(93, 3, HERE << "read " << io.size << " bytes");
 
-        /*
-         * See comments in Adaptation::Icap::Xaction.h about why we use commBuf
-         * here instead of reading directly into readBuf.buf.
-         */
+        break;
 
-        readBuf.append(commBuf, io.size);
-        disableRetries(); // because pconn did not fail
+        // case Comm::COMM_ERROR:
+    default: // no other flags should ever occur
+        debugs(11, 2, io.conn << ": read failure: " << xstrerr(rd.xerrno));
+        mustStop("unknown ICAP I/O read error");
+        return;
     }
 
     handleCommRead(io.size);
