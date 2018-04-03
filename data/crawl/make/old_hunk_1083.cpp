
  fputs ("\n# ", stdout);
  if (files == 0)
    fputs ("No", stdout);
  else
    printf ("%u", files);
  fputs (" files, ", stdout);
  if (impossible == 0)
    fputs ("no", stdout);
  else
    printf ("%u", impossible);
  printf (" impossibilities in %u directories.\n", dirs);
}

/* Hooks for globbing.  */
