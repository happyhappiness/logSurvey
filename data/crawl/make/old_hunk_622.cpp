#endif  /* HAVE_DMALLOC_H */

char *
savestring (const char *str, unsigned int length)
{
  char *out = xmalloc (length + 1);
  if (length > 0)
    memcpy (out, str, length);
  out[length] = '\0';
  return out;
}


