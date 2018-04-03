         return;
     }
 
-    static MemBuf mb;
-    mb.reset();
+    SBuf buf;
     if (params.size() > 0)
-        mb.Printf("%s %s%s", cmd.termedBuf(), params.termedBuf(), Ftp::crlf);
+        buf.Printf("%s %s%s", cmd.termedBuf(), params.termedBuf(), Ftp::crlf);
     else
-        mb.Printf("%s%s", cmd.termedBuf(), Ftp::crlf);
+        buf.Printf("%s%s", cmd.termedBuf(), Ftp::crlf);
 
-    writeCommand(mb.content());
+    writeCommand(buf.c_str());
 
     state =
         serverState() == fssHandleCdup ? SENT_CDUP :
