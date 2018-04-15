 		if ((pid = fork ()) == -1)
 		{
 			/* error */
-			fprintf (stderr, "fork: %s", strerror (errno));
+			char errbuf[1024];
+			fprintf (stderr, "fork: %s",
+					sstrerror (errno, errbuf,
+						sizeof (errbuf)));
 			return (1);
 		}
 		else if (pid != 0)
