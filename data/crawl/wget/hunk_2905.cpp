     return;
 #endif
 
-  /* Still not enough randomness, most likely because neither
-     /dev/random nor EGD were available.  Resort to a simple and
-     stupid method -- seed OpenSSL's PRNG with libc PRNG.  This is
-     cryptographically weak, but people who care about strong
-     cryptography should install /dev/random (default on Linux) or
-     specify their own source of randomness anyway.  */
+#if 0 /* don't do this by default */
+  {
+    int maxrand = 500;
 
-  logprintf (LOG_VERBOSE, _("Warning: using a weak random seed.\n"));
+    /* Still not random enough, presumably because neither /dev/random
+       nor EGD were available.  Try to seed OpenSSL's PRNG with libc
+       PRNG.  This is cryptographically weak and defeats the purpose
+       of using OpenSSL, which is why it is highly discouraged.  */
+
+    logprintf (LOG_VERBOSE, _("WARNING: using a weak random seed.\n"));
+
+    while (RAND_status () == 0 && maxrand-- > 0)
+      {
+	unsigned char rnd = random_number (256);
+	RAND_seed (&rnd, sizeof (rnd));
+      }
+  }
+#endif
 
-  while (RAND_status () == 0 && maxrand-- > 0)
-    {
-      unsigned char rnd = random_number (256);
-      RAND_seed (&rnd, sizeof (rnd));
-    }
 #endif /* SSLEAY_VERSION_NUMBER >= 0x00905100 */
 }
 
