 	    fprintf(stderr, "WARNING: %s invalid checksum wanted 0x%lx got 0x%lx\n",
 		r->url, r->validsum, r->sum);
     }
-    if (r->status != r->validstatus && r->validstatus)
-	fprintf(stderr, "WARNING: %s status %d\n", r->url, r->status);
     if (trace_file) {
-	fprintf(trace_file, "%s %s %s %d 0x%lx %d\n",
-	    r->method, r->url, r->requestbodyfile, r->bodysize, r->sum, r->status);
+	if (opt_checksum)
+	    fprintf(trace_file, "%s %s %d %s %d 0x%lx\n",
+		r->method, r->url, r->status, r->requestbodyfile, r->bodysize, r->sum);
+	else
+	    fprintf(trace_file, "%s %s %d %s %d\n",
+		r->method, r->url, r->status, r->requestbodyfile, r->bodysize);
     }
     free_request(r);
 }
