         debug("Got '%s' from Squid (length: %d).\n", buf, strlen(buf));
 
         if (buf[0] == '\0') {
-            fprintf(stderr, "Invalid Request\n");
-            goto error;
+            SEND_ERR("Invalid Request.");
+            continue;
         }
         username = strtok(buf, " ");
         for (n = 0; (group = strtok(NULL, " ")) != NULL; n++) {
