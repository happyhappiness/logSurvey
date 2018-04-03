     totallen = ntohs(auth->length);
 
     if (totallen != length) {
-	fprintf(stderr,
-	    "Squid_rad_auth: Received invalid reply length from server (want %d/ got %d)\n",
-	    totallen, length);
-	return -1;
+        fprintf(stderr,
+                "Squid_rad_auth: Received invalid reply length from server (want %d/ got %d)\n",
+                totallen, length);
+        return -1;
     }
     if (auth->id != request_id) {
-	/* Duplicate response of an earlier query, ignore */
-	return -1;
+        /* Duplicate response of an earlier query, ignore */
+        return -1;
     }
     /* Verify the reply digest */
     memcpy(reply_digest, auth->vector, AUTH_VECTOR_LEN);
