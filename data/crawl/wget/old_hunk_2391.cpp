
 retry:
  if (!al)
    return E_HOST;

  address_list_get_bounds (al, &start, &end);
  for (i = start; i < end; i++)
