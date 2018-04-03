 	    (int) n->next_ping_time,
 	    (int) n->last_use_time);
 	for (x = n->hosts; x; x = x->next)
-	    fprintf(fp, " %s", x->name);
-	fprintf(fp, "\n");
+	    ro += snprintf(rbuf + ro, RBUF_SZ - ro, " %s", x->name);
+	ro += snprintf(rbuf + ro, RBUF_SZ - ro, "\n");
+	assert(ro <= RBUF_SZ);
+	while (ro + wo > wl) {
+	    char *t;
+	    t = wbuf;
+	    wl <<= 1;
+	    wbuf = xmalloc(wl);
+	    debug(0, 0) ("netdbSaveState: wbuf now %d bytes\n", wl);
+	    xmemcpy(wbuf, t, wo);
+	    xfree(t);
+	}
+	xmemcpy(wbuf + wo, rbuf, ro);
+	wo += ro;
 	count++;
+#undef RBUF_SZ
     }
-    fclose(fp);
+    write(fd, wbuf, wo);
+    file_close(fd);
     getCurrentTime();
     debug(38, 1) ("NETDB state saved; %d entries, %d msec\n",
 	count, tvSubMsec(start, current_time));
