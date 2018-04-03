  desc->dsc$b_class = DSC$K_CLASS_S;

  if (*fname == 0)
    printf ("Warning: Empty redirection\n");
  return ibuf;
}

