             }
           if (!userrc_ret)
             {
-              printf ("Exiting due to error in %s\n", optarg);
+              fprintf (stderr, "Exiting due to error in %s\n", optarg);
               exit (2);
             }
           else
