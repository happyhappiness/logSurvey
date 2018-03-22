 	  COPY_BUF (blk,nbuf,p);
 	  if (!decode_num (&u, nbuf, TYPE_MAXIMUM (size_t)))
 	    {
-	      ERROR ((0, 0, _("%s: malformed sparse archive member"), 
+	      ERROR ((0, 0, _("%s: malformed sparse archive member"),
 		      file->stat_info->orig_file_name));
 	      return false;
 	    }
