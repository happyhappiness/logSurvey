         close(i); close(i-1);
 	i++;
 #endif
+#endif /* __CYGWIN32__ */
 	fprintf (fopen("conftestval", "w"), "%d\n", i);
 	exit(0);
 }
