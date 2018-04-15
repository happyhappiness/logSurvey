		if (i != ds->ds_num)
		{
			sfree (value_ptr);
			/* FIXME: Send some response */
			return (-1);
		}
	} /* done parsing the value-list */
