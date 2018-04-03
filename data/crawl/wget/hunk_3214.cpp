     return;
 #endif
 
-  /* Still not enough randomness, presumably because neither random
-     file nor EGD have been available.  Use the stupidest possible
-     method -- seed OpenSSL's PRNG with the system's PRNG.  This is
-     insecure in the cryptographic sense, but people who care about
-     security will use /dev/random or their own source of randomness
-     anyway.  */
+  /* Still not enough randomness, most likely because neither
+     /dev/random nor EGD were available.  Resort to a simple and
+     stupid method -- seed OpenSSL's PRNG with libc PRNG.  This is
+     cryptographically weak, but people who care about strong
+     cryptography should install /dev/random (default on Linux) or
+     specify their own source of randomness anyway.  */
+
+  logprintf (LOG_VERBOSE, _("Warning: using a weak random seed.\n"));
 
   while (RAND_status () == 0 && maxrand-- > 0)
     {
