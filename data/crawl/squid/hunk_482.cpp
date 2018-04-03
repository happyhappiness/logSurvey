         return;
 
     default:
-        fatal("Hit unreachable code in clientWriteComplete\n");
+        fatal("Hit unreachable code in ClientSocketContext::writeComplete\n");
     }
 }
 
