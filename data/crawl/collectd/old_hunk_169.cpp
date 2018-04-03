{
  oconfig_item_t *ci_copy;

  ci_copy = malloc (sizeof (*ci_copy));
  if (ci_copy == NULL)
  {
    fprintf (stderr, "malloc failed.\n");
    return (NULL);
  }
  memset (ci_copy, 0, sizeof (*ci_copy));
  ci_copy->values = NULL;
  ci_copy->parent = NULL;
  ci_copy->children = NULL;
