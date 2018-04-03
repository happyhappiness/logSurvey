  struct stat sb;
  return stat(f, &sb) == 0;
}
