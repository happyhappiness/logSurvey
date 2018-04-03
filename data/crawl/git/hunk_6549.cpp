 		/* Not numeric */
 		struct servent *se = getservbyname(port,"tcp");
 		if ( !se )
-			die("Unknown port %s\n", port);
+			die("Unknown port %s", port);
 		nport = se->s_port;
 	}
 
