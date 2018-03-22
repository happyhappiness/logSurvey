  struct xattrs_mask_map excl;
} xattrs_setup;

static void mask_map_realloc (struct xattrs_mask_map *map)
{
  if (map->size == 0)
