		if (i != ds->ds_num)
		{
			sfree (value_ptr);
			fprintf (fh, "-1 Number of values incorrect: Got %i, "
					"expected %i.", i, ds->ds_num);
			return (-1);
		}
	} /* done parsing the value-list */
