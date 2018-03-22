  return true;
}

static bool
pax_dump_header_1 (struct tar_sparse_file *file)
{
  off_t block_ordinal = current_block_ordinal ();
  union block *blk;
  char *p, *q;
  size_t i;
  char nbuf[UINTMAX_STRSIZE_BOUND];
  off_t size = 0;
  struct sp_array *map = file->stat_info->sparse_map;
  char *save_file_name = file->stat_info->file_name;

#define COPY_STRING(b,dst,src) do                \
 {                                               \
   char *endp = b->buffer + BLOCKSIZE;           \
   char *srcp = src;                             \
   while (*srcp)                                 \
     {                                           \
       if (dst == endp)                          \
	 {                                       \
	   set_next_block_after (b);             \
	   b = find_next_block ();               \
           dst = b->buffer;                      \
	   endp = b->buffer + BLOCKSIZE;         \
	 }                                       \
       *dst++ = *srcp++;                         \
     }                                           \
   } while (0)                       

  /* Compute stored file size */
  p = umaxtostr (file->stat_info->sparse_map_avail, nbuf);
  size += strlen (p) + 1;
  for (i = 0; i < file->stat_info->sparse_map_avail; i++)
    {
      p = umaxtostr (map[i].offset, nbuf);
      size += strlen (p) + 1;
      p = umaxtostr (map[i].numbytes, nbuf);
      size += strlen (p) + 1;
    }
  size = (size + BLOCKSIZE - 1) / BLOCKSIZE;
  file->stat_info->archive_file_size += size * BLOCKSIZE;
  
  /* Store sparse file identification */
  xheader_store ("GNU.sparse.major", file->stat_info, NULL);
  xheader_store ("GNU.sparse.minor", file->stat_info, NULL);
  xheader_store ("GNU.sparse.name", file->stat_info, NULL);
  xheader_store ("GNU.sparse.realsize", file->stat_info, NULL);
  
  file->stat_info->file_name = xheader_format_name (file->stat_info,
					    "%d/GNUSparseFile.%p/%f", 0);

  blk = start_header (file->stat_info);
  /* Store the effective (shrunken) file size */
  OFF_TO_CHARS (file->stat_info->archive_file_size, blk->header.size);
  finish_header (file->stat_info, blk, block_ordinal);
  free (file->stat_info->file_name);
  file->stat_info->file_name = save_file_name;

  blk = find_next_block ();
  q = blk->buffer;
  p = umaxtostr (file->stat_info->sparse_map_avail, nbuf);
  COPY_STRING (blk, q, p);
  COPY_STRING (blk, q, "\n");
  for (i = 0; i < file->stat_info->sparse_map_avail; i++)
    {
      p = umaxtostr (map[i].offset, nbuf);
      COPY_STRING (blk, q, p);
      COPY_STRING (blk, q, "\n");
      p = umaxtostr (map[i].numbytes, nbuf);
      COPY_STRING (blk, q, p);
      COPY_STRING (blk, q, "\n");
    }
  memset (q, 0, BLOCKSIZE - (q - blk->buffer));
  set_next_block_after (blk);
  return true;
}

static bool
pax_dump_header (struct tar_sparse_file *file)
{
  file->stat_info->sparse_major = tar_sparse_major;
  file->stat_info->sparse_minor = tar_sparse_minor;
  
  if (file->stat_info->sparse_major == 0)
    pax_dump_header_0 (file);
  else
    pax_dump_header_1 (file);
}

static bool
decode_num (uintmax_t *num, char const *arg, uintmax_t maxval)
{
  uintmax_t u;
  char *arg_lim;

  if (!ISDIGIT (*arg))
    return false;
  
  u = strtoumax (arg, &arg_lim, 10);

  if (! (u <= maxval && errno != ERANGE) || *arg_lim)
    return false;
  
  *num = u;
  return true;
}

static bool
pax_decode_header (struct tar_sparse_file *file)
{
  if (file->stat_info->sparse_major > 0)
    {
      uintmax_t u;
      char nbuf[UINTMAX_STRSIZE_BOUND];
      union block *blk;
      char *p;
      size_t i;

#define COPY_BUF(b,buf,src) do                                     \
 {                                                                 \
   char *endp = b->buffer + BLOCKSIZE;                             \
   char *dst = buf;                                                \
   do                                                              \
     {                                                             \
       if (dst == buf + UINTMAX_STRSIZE_BOUND -1)                  \
         {                                                         \
           ERROR ((0, 0, _("%s: numeric overflow in sparse archive member"),   \
	          file->stat_info->orig_file_name));               \
           return false;                                           \
         }                                                         \
        if (src == endp)                                           \
	 {                                                         \
	   set_next_block_after (b);                               \
	   b = find_next_block ();                                 \
           src = b->buffer;                                        \
	   endp = b->buffer + BLOCKSIZE;                           \
	 }                                                         \
       *dst = *src++;                                              \
     }                                                             \
   while (*dst++ != '\n');                                         \
   dst[-1] = 0;                                                    \
 } while (0)                       

      set_next_block_after (current_header);
      blk = find_next_block ();
      p = blk->buffer;
      COPY_BUF (blk,nbuf,p);
      if (!decode_num (&u, nbuf, TYPE_MAXIMUM (size_t)))
	{
	  ERROR ((0, 0, _("%s: malformed sparse archive member"), 
		  file->stat_info->orig_file_name));
	  return false;
	}
      file->stat_info->sparse_map_size = u;
      file->stat_info->sparse_map = xcalloc (file->stat_info->sparse_map_size,
					     sizeof (*file->stat_info->sparse_map));
      file->stat_info->sparse_map_avail = 0;
      for (i = 0; i < file->stat_info->sparse_map_size; i++)
	{
	  struct sp_array sp;
	  
	  COPY_BUF (blk,nbuf,p);
	  if (!decode_num (&u, nbuf, TYPE_MAXIMUM (off_t)))
	    {
	      ERROR ((0, 0, _("%s: malformed sparse archive member"), 
		      file->stat_info->orig_file_name));
	      return false;
	    }
	  sp.offset = u;
	  COPY_BUF (blk,nbuf,p);
	  if (!decode_num (&u, nbuf, TYPE_MAXIMUM (size_t)))
	    {
	      ERROR ((0, 0, _("%s: malformed sparse archive member"), 
		      file->stat_info->orig_file_name));
	      return false;
	    }
	  sp.numbytes = u;
	  sparse_add_map (file->stat_info, &sp);
	}
      set_next_block_after (blk);
    }
  
  return true;
}

static struct tar_sparse_optab const pax_optab = {
  NULL,  /* No init function */
  NULL,  /* No done function */
  pax_sparse_member_p,
  pax_dump_header,
  NULL,
  pax_decode_header,  
  NULL,  /* No scan_block function */
  sparse_dump_region,
  sparse_extract_region,
