         return;
     case STREAM_COMPLETE:
         debugs(33, 3, "FTP reply data transfer successfully complete");
-        writeCustomReply(226, "Transfer complete");
+        userDataCompletionCheckpoint(226);
         break;
     case STREAM_UNPLANNED_COMPLETE:
         debugs(33, 3, "FTP reply data transfer failed: STREAM_UNPLANNED_COMPLETE");
-        writeCustomReply(451, "Server error; transfer aborted");
+        userDataCompletionCheckpoint(451);
         break;
     case STREAM_FAILED:
+        userDataCompletionCheckpoint(451);
         debugs(33, 3, "FTP reply data transfer failed: STREAM_FAILED");
-        writeCustomReply(451, "Server error; transfer aborted");
         break;
     default:
         fatal("unreachable code");
     }
-
-    closeDataConnection();
 }
 
 void
