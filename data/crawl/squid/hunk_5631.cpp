       username = strtok (NULL, " \t");
     } else {
       fprintf (stderr, "helper: unable to read tokens\n");
+      printf ("ERR\n");
+      continue;
     }
 #ifdef DEBUG
     printf ("result: %d\n",
