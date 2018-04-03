 static void
 print_version (void)
 {
-  printf ("GNU Wget %s\n\n", version_string);
+#ifdef __VMS
+  printf ("GNU Wget %s built on VMS %s %s.\n\n",
+   VERSION_STRING, vms_arch(), vms_vers());
+#else /* def __VMS */
+  printf ("GNU Wget %s built on %s.\n\n", VERSION_STRING, OS_TYPE);
+#endif /* def __VMS */
   /* TRANSLATORS: When available, an actual copyright character
      (cirle-c) should be used in preference to "(C)". */
   fputs (_("\
