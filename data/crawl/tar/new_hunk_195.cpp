
  if (length > PREFIX_FIELD_SIZE + NAME_FIELD_SIZE + 1)
    {
      ERROR ((0, 0, _("%s: file name is too long (max %d); not dumped"),
	      quotearg_colon (name),
	      PREFIX_FIELD_SIZE + NAME_FIELD_SIZE + 1));
      return NULL;
    }

  i = split_long_name (name, length);
  if (i == 0 || length - i - 1 > NAME_FIELD_SIZE)
    {
      ERROR ((0, 0,
	      _("%s: file name is too long (cannot be split); not dumped"),
	      quotearg_colon (name)));
      return NULL;
    }

