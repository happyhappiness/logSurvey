 		else {
 			char errbuf[1024];
 			/* We can't use `ERROR' yet.. */
-			fprintf (stderr, "stderr plugin: Access to %s denied: %s\n",
+			fprintf (stderr, "logfile plugin: Access to %s denied: %s\n",
 					value, sstrerror (errno, errbuf, sizeof (errbuf)));
 			return 1;
 		}
