         /* fallthrough */
 
     case STREAM_FAILED:
-        initiateClose();
+        initiateClose("STREAM_UNPLANNED_COMPLETE|STREAM_FAILED");
         return;
 
     default:
