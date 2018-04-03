     md5_calc(calc_digest, (unsigned char *) auth, length + secretlen);
 
     if (memcmp(reply_digest, calc_digest, AUTH_VECTOR_LEN) != 0) {
-        fprintf(stderr, "Warning: Received invalid reply digest from server\n");
+        debug("WARNING: Received invalid reply digest from server\n");
         return -1;
     }
     if (auth->code != PW_AUTHENTICATION_ACK)
