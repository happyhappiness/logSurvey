         /* fallthrough */
 
     case STREAM_FAILED:
-        comm_close(fd);
+        initiateClose();
         return;
 
     default:
