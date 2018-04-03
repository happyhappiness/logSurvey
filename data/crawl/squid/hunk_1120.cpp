                       strerror(ferror(stdin)));
 
                 fprintf(stdout, "BH input error\n");
-                exit(1);	/* BIIG buffer */
+                exit(1);    /* BIIG buffer */
             }
             fprintf(stdout, "BH input error\n");
             exit(0);
