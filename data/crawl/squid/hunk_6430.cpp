 	    if (read_reply(pconn_fd) != 0)
 		pconn_fd = -1;
 	}
+	gettimeofday(&now, NULL);
+        if (now.tv_sec > last.tv_sec) {
+	    int dt;
+	    int nreq;
+	    last = now;
+	    dt = (int) (now.tv_sec - start.tv_sec);
+	    nreq=0;
+	    for (r=Requests; r ; r=r->next) nreq++;
+	    printf("T+ %6d: %9d req (%+4d), %4d pend, %3d/sec avg, %dmb, %dkb/sec avg\n",
+		    dt,
+		    nrequests,
+		    reqpersec,
+		    nreq,
+		    (int) (nrequests / dt),
+		    (int)total_bytes_read / 1024 / 1024,
+		    (int)total_bytes_read / 1024 / dt);
+	    reqpersec = 0;
+	}
     }
 }
 
 void
 usage(void)
 {
-    fprintf(stderr, "usage: %s: -p port -h host -n max\n", progname);
+    fprintf(stderr, "usage: %s: -p port -h host -n max -t tracefile -i -c -l lifetime\n", progname);
 }
 
 int
