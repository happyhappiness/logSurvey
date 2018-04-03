     else if (what == 1)
 	server_pconn_hist[i]++;
     else
-	fatal_dump("pconnHistCount: bad 'what' arg");
+	assert(0);
 }
 
 void
