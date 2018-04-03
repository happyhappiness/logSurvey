 
     if (io.flag != Comm::OK) {
         debugs(33, 3, "FTP reply data writing failed: " << xstrerr(io.xerrno));
-        closeDataConnection();
-        writeCustomReply(426, "Data connection error; transfer aborted");
+        userDataCompletionCheckpoint(426);
         return;
     }
 
