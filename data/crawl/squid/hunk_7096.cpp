     /* what == 0 for client, 1 for server */
     if (what == 0)
 	client_pconn_hist[i]++;
+    else if (what == 1)
+	server_pconn_hist[i]++;
+    else
+	fatal_dump("pconnHistCount: bad 'what' arg");
 }
 
 void
