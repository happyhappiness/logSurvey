    if (!WASFOUND (cursor) && cursor->name[0])
      {
	regex_usage_warning (cursor->name);
	ERROR ((0, 0,
		(cursor->found_count == 0) ?
		     _("%s: Not found in archive") :
		     _("%s: Required occurrence not found in archive"),
