 
 static int verify_callback PARAMS ((int, X509_STORE_CTX *));
 
-static void
+void
 ssl_init_prng (void)
 {
+  /* It is likely that older versions of OpenSSL will fail on
+     non-Linux machines because this code is unable to seed the PRNG
+     on older versions of the library.  */
+
 #if SSLEAY_VERSION_NUMBER >= 0x00905100
+  char rand_file[256];
+  int maxrand = 500;
+
+  /* First, seed from a file specified by the user.  This will be
+     $RANDFILE, if set, or ~/.rnd.  */
+  RAND_file_name (rand_file, sizeof (rand_file));
+  if (rand_file)
+    /* Seed at most 16k (value borrowed from curl) from random file. */
+    RAND_load_file (rand_file, 16384);
+
+  if (RAND_status ())
+    return;
+
+  /* Get random data from EGD if opt.sslegdsock was set.  */
+  if (opt.sslegdsock)
+    RAND_egd (opt.sslegdsock);
+
+  if (RAND_status ())
+    return;
+
+#ifdef WINDOWS
+  /* Under Windows, we can try to seed the PRNG using screen content.
+     This may or may not work, depending on whether we'll calling Wget
+     interactively.  */
+
+  RAND_screen ();
+  if (RAND_status ())
+    return;
+#endif
+
+  /* Still not enough randomness, presumably because neither random
+     file nor EGD have been available.  Use the stupidest possible
+     method -- seed OpenSSL's PRNG with the system's PRNG.  This is
+     insecure in the cryptographic sense, but people who care about
+     security will use /dev/random or their own source of randomness
+     anyway.  */
+
+  srand (time (NULL));
+  while (RAND_status () == 0 && maxrand-- > 0)
+    {
+      int rnd = rand ();
+      RAND_seed ((unsigned char *)&rnd, sizeof (rnd));
+    }
+
   if (RAND_status () == 0)
     {
-      char rand_file[256];
-      time_t t;
-      long l,seed;
-
-      t = time(NULL);
-      /* gets random data from egd if opt.sslegdsock was set */
-      if (opt.sslegdsock != NULL)
-	RAND_egd(opt.sslegdsock);
-      /* gets the file ~/.rnd or $RANDFILE if set */
-      RAND_file_name(rand_file, 256);
-      if (rand_file != NULL)
-	{
-	  /* Seed as much as 1024 bytes from RAND_file_name */
-	  RAND_load_file(rand_file, 1024);
-	}
-      /* Seed in time (mod_ssl does this) */
-      RAND_seed((unsigned char *)&t, sizeof(time_t));
-      /* Initialize system's random number generator */
-      RAND_bytes((unsigned char *)&seed, sizeof(long));
-#ifndef WINDOWS
-      srand48(seed);
-      while (RAND_status () == 0)
-	{
-	  /* Repeatedly seed the PRNG using the system's random number
-	     generator until it has been seeded with enough data.  */
-	  l = lrand48();
-	  RAND_seed((unsigned char *)&l, sizeof(long));
-	}
-#else /* WINDOWS */
-      RAND_screen();
-      if (RAND_status() == 0)
-        /* Here we should probably disable the whole ssl protocol ? HEH */
-        DEBUGP (("SSL random data generator not seeded correctly, %i",RAND_status()));
-#endif /* WINDOWS */
-      if (rand_file != NULL)
-	{
-	  /* Write a rand_file */
-	  RAND_write_file(rand_file);
-	}
+      logprintf (LOG_NOTQUIET, "Could not seed OpenSSL PRNG; disabling SSL.\n");
+      scheme_disable (SCHEME_HTTPS);
     }
 #endif /* SSLEAY_VERSION_NUMBER >= 0x00905100 */
-  return;
 }
 
-
 /* Creates a SSL Context and sets some defaults for it */
 uerr_t
 init_ssl (SSL_CTX **ctx)
