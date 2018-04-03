       unsigned char rnd = random_number (256);
       RAND_seed (&rnd, sizeof (rnd));
     }
-
-  if (RAND_status () == 0)
-    {
-      logprintf (LOG_NOTQUIET,
-		 _("Could not seed OpenSSL PRNG; disabling SSL.\n"));
-      scheme_disable (SCHEME_HTTPS);
-    }
 #endif /* SSLEAY_VERSION_NUMBER >= 0x00905100 */
 }
 
-int
+static int
 verify_callback (int ok, X509_STORE_CTX *ctx)
 {
   char *s, buf[256];
