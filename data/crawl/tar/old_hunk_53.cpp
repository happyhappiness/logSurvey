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
