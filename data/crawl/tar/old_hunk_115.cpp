  return true;
}

static struct tar_sparse_optab const pax_optab = {
  NULL,  /* No init function */
  NULL,  /* No done function */
  pax_sparse_member_p,
  pax_dump_header,
  NULL,  /* No decode_header function */
  NULL,  /* No fixup_header function */
  NULL,  /* No scan_block function */
  sparse_dump_region,
  sparse_extract_region,
