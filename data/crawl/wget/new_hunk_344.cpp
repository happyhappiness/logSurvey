      got_name = true;
    }

  if (got_name && file_exists_p (hstat.local_file) && opt.noclobber && !opt.output_document)
    {
      /* If opt.noclobber is turned on and file already exists, do not
         retrieve the file. But if the output_document was given, then this
         test was already done and the file didn't exist. Hence the !opt.output_document */
      get_file_flags (hstat.local_file, dt);
      ret = RETROK;
      goto exit;
    }
