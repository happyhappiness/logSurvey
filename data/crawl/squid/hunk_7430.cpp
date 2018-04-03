 		fatal_dump("Invalid $ttl");
 	    i.expires = squid_curtime + atoi(token);
 	} else {
-	    fatal_dump("Invalid dnsserver output");
+	    debug(14,0,"--> %s <--\n", inbuf);
+	    debug_trap("Invalid dnsserver output");
 	}
     }
     xfree(buf);