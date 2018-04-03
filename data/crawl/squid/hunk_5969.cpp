 	    (int) n->next_ping_time,
 	    (int) n->last_use_time);
 	for (x = n->hosts; x; x = x->next)
-	    ro += snprintf(rbuf + ro, RBUF_SZ - ro, " %s", x->name);
-	ro += snprintf(rbuf + ro, RBUF_SZ - ro, "\n");
-	assert(ro <= RBUF_SZ);
-	while (ro + wo > wl) {
-	    char *t;
-	    t = wbuf;
-	    wl <<= 1;
-	    wbuf = xmalloc(wl);
-	    xmemcpy(wbuf, t, wo);
-	    xfree(t);
-	}
-	xmemcpy(wbuf + wo, rbuf, ro);
-	wo += ro;
+	    logfilePrintf(lf, " %s", x->name);
+	logfilePrintf(lf, "\n");
 	count++;
 #undef RBUF_SZ
     }
-    write(fd, wbuf, wo);
-    file_close(fd);
+    logfileClose(lf);
     getCurrentTime();
     debug(38, 1) ("NETDB state saved; %d entries, %d msec\n",
 	count, tvSubMsec(start, current_time));
