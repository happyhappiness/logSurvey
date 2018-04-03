void
unload_file (const char *name)
{
  fatal (NILF, "INTERNAL: Cannot unload when load is not supported!");
}

#endif  /* MAKE_LOAD */
