	if (vl.values == NULL)
	{
		sfree (value_ptr);
		return (-1);
	}
	DEBUG ("value_ptr = 0x%p; vl.values = 0x%p;", (void *) value_ptr, (void *) vl.values);
