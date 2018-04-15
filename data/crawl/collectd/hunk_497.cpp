     memcpy(&us, buf + offset + 2, 2);
     qclass = ntohs(us);
 
-    if (Filter && 0 == Filter(qtype, qclass, qname, sip, dip))
-	return 0;
+    fprintf (stderr, "qtype = %hu\n", qtype);
 
     /* gather stats */
     qtype_counts[qtype]++;
