{
  oconfig_item_t *ci_copy;

  ci_copy = calloc (1, sizeof (*ci_copy));
  if (ci_copy == NULL)
  {
    fprintf (stderr, "calloc failed.\n");
    return (NULL);
  }
  ci_copy->values = NULL;
  ci_copy->parent = NULL;
  ci_copy->children = NULL;
