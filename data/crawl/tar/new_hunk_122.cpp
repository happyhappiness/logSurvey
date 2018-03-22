
  if (same_order_option)
    {
      const char *name;

      while ((name = name_next (1)) != NULL)
	{
	  regex_usage_warning (name);
	  ERROR ((0, 0, _("%s: Not found in archive"),
		  quotearg_colon (name)));
	}
    }
}

