 		     len, (Rpc_Opaque) waybill,
 		     sizeof(msg), (Rpc_Opaque) msg,
 		     1, &timeout);
+
+  host = gethostbyaddr((char *)&permit.addr, sizeof(permit.addr), AF_INET);
+
   if (status != RPC_SUCCESS)
     {
       (void) close (retsock);
       (void) close (sock);
-      error ("exporting: %s", Rpc_ErrorMessage (status));
+      error ("exporting to %s: %s",
+             host ? host->h_name : inet_ntoa (permit.addr),
+             Rpc_ErrorMessage (status));
       return 1;
     }
   else if (msg[0] != 'O' || msg[1] != 'k' || msg[2] != '\0')
     {
       (void) close (retsock);
       (void) close (sock);
-      error ("CUSTOMS_IMPORT: %s", msg);
+      error ("exporting to %s: %s",
+             host ? host->h_name : inet_ntoa (permit.addr),
+             msg);
       return 1;
     }
-  else if (debug_flag)
+  else
     {
-      struct hostent *host = gethostbyaddr (&permit.addr, sizeof (permit.addr),
-					    AF_INET);
-      printf ("Job exported to %s ID %u\n",
-	      host == 0 ? inet_ntoa (permit.addr) : host->h_name,
+      error ("*** exported to %s (id %u)",
+	      host ? host->h_name : inet_ntoa (permit.addr),
 	      permit.id);
     }
 
