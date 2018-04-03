         return;
 
     case STREAM_UNPLANNED_COMPLETE:
-        /* fallthrough */
+        initiateClose("STREAM_UNPLANNED_COMPLETE");
+        return;
 
     case STREAM_FAILED:
-        initiateClose("STREAM_UNPLANNED_COMPLETE|STREAM_FAILED");
+        initiateClose("STREAM_FAILED");
         return;
 
     default:
