	   (unsigned long) ssl));
  return 1;

 err:
  print_errors ();
  if (ssl)
    SSL_free (ssl);
  return 0;
}
