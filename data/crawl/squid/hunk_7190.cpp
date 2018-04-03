     switch (sscanf(asc, "%d.%d.%d.%d", &a1, &a2, &a3, &a4)) {
     case 4:			/* a dotted quad */
 	if (!safe_inet_addr(asc, addr)) {
-	    debug(28, 0, "decode_addr: unsafe IP address: '%s'\n", asc);
+	    debug(28, 0) ("decode_addr: unsafe IP address: '%s'\n", asc);
 	    fatal("decode_addr: unsafe IP address");
 	}
 	break;
