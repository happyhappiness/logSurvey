         i++;
 #endif /* IF !DEF CYGWIN */
 	fp = fopen("conftestval", "w");
-	fprintf (fp, "%d\n", i);
+	fprintf (fp, "%d\n", i & ~0x3F);
 	exit(0);
 }
   ],
