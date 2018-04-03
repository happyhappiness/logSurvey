 		pconn_fd = -1;
 	}
 	gettimeofday(&now, NULL);
-        if (now.tv_sec > last.tv_sec) {
+	if (now.tv_sec > last.tv_sec) {
 	    int dt;
 	    int nreq;
 	    last = now;
 	    dt = (int) (now.tv_sec - start.tv_sec);
-	    nreq=0;
-	    for (r=Requests; r ; r=r->next) nreq++;
+	    nreq = 0;
+	    for (r = Requests; r; r = r->next)
+		nreq++;
 	    printf("T+ %6d: %9d req (%+4d), %4d pend, %3d/sec avg, %dmb, %dkb/sec avg\n",
-		    dt,
-		    nrequests,
-		    reqpersec,
-		    nreq,
-		    (int) (nrequests / dt),
-		    (int)total_bytes_read / 1024 / 1024,
-		    (int)total_bytes_read / 1024 / dt);
+		dt,
+		nrequests,
+		reqpersec,
+		nreq,
+		(int) (nrequests / dt),
+		(int) total_bytes_read / 1024 / 1024,
+		(int) total_bytes_read / 1024 / dt);
 	    reqpersec = 0;
 	}
     }
