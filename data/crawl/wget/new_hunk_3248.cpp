      unsigned char rnd = random_number (256);
      RAND_seed (&rnd, sizeof (rnd));
    }
#endif /* SSLEAY_VERSION_NUMBER >= 0x00905100 */
}

static int
verify_callback (int ok, X509_STORE_CTX *ctx)
{
  char *s, buf[256];
