 	i++;
 #endif
 #endif /* __CYGWIN32__ */
-	fprintf (fopen("conftestval", "w"), "%d\n", i);
+	fp = fopen("conftestval", "w");
+	fprintf (fp, "%d\n", i);
 	exit(0);
 }
 ],
