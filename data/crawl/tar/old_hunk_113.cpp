}

static void
sparse_numbytes_decoder (struct tar_stat_info *st, char const *arg,
			 size_t size __attribute__((unused)))
{
  uintmax_t u;
  if (decode_num (&u, arg, SIZE_MAX, "GNU.sparse.numbytes"))
    {
      if (st->sparse_map_avail < st->sparse_map_size)
	st->sparse_map[st->sparse_map_avail++].numbytes = u;
      else
	ERROR ((0, 0, _("Malformed extended header: excess %s=%s"),
		"GNU.sparse.numbytes", arg));
    }
}

static void
sparse_map_decoder (struct tar_stat_info *st, char const *arg,
		    size_t size __attribute__((unused)))
{
  int offset = 1;
  static char *keyword = "GNU.sparse.map";

  st->sparse_map_avail = 0;
  while (1)
