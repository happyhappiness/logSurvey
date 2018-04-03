    }

  if (contrange == -1)
    hs->restval = 0;
  else if (contrange != hs->restval ||
	   (H_PARTIAL (statcode) && contrange == -1))
    {
