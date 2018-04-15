  return count;
} /* count_chars */

static int array_grow (void **array, int *array_len, size_t elem_size)
{
  void *tmp;

  assert ((array != NULL) && (array_len != NULL));

  tmp = realloc (*array, (*array_len + 1) * elem_size);
  if (tmp == NULL) {
    fprintf (stderr, "ERROR: Failed to allocate memory.\n");
    return (-1);
  }

  *array = tmp;
  ++(*array_len);
  return (0);
} /* array_grow */

static int parse_identifier (lcc_connection_t *c,
    const char *value, lcc_identifier_t *ident)
{
