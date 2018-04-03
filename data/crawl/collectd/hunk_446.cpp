   else if (n->severity == NOTIF_OKAY)
     severity = "OKAY";
 
-  fprintf (fh, "Severity: %s\n"
-      "Time: %u\n"
-      "Message: %s\n",
-      severity, (unsigned int) n->time, n->message);
+  fprintf (fh,
+      "Severity: %s\n"
+      "Time: %u\n",
+      severity, (unsigned int) n->time);
 
   /* Print the optional fields */
   if (strlen (n->host) > 0)
