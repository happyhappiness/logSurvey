  if (opt.output_document)
    {
      if (HYPHENP (opt.output_document))
        output_stream = stdout;
      else
        {
          struct_fstat st;
