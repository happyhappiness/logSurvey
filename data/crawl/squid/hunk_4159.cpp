     if (strlen(buf) <= 3) {
       if (debug)
 	fprintf(stderr, "%s| %s: Invalid negotiate request [%s]\n", LogTime(), PROGRAM, buf);
-      fprintf(stdout, "NA Invalid negotiate request\n");
+      fprintf(stdout, "BH Invalid negotiate request\n");
       continue;
     }
         
-    input_token.length = base64_decode_len(buf+3);
-    input_token.value = malloc(input_token.length);
+    input_token.length = ska_base64_decode_len(buf+3);
+    if (debug)
+      fprintf(stderr, "%s| %s: Decode '%s' (decoded length: %d).\n", LogTime(), PROGRAM, buf+3,(int)input_token.length);
+    input_token.value = xmalloc(input_token.length);
 
-    base64_decode(input_token.value,buf+3,input_token.length);
+    ska_base64_decode(input_token.value,buf+3,input_token.length);
 
  
 #ifndef HAVE_SPNEGO
