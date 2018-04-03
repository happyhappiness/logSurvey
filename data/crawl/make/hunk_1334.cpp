   retsock = Rpc_UdpCreate (True, 0);
   if (retsock < 0)
     {
-      error ("exporting: Couldn't create return socket.");
+      error (NILF, "exporting: Couldn't create return socket.");
       return 1;
     }
 
