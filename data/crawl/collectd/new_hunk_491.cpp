		else if (ds->ds[i].type == DS_TYPE_GAUGE)
			vl.values[i].gauge = atof (value_ptr[i]);
	} /* for (i = 2 .. fields_num) */

	plugin_dispatch_values (type, &vl);

	DEBUG ("value_ptr = 0x%p; vl.values = 0x%p;", (void *) value_ptr, (void *) vl.values);

	sfree (value_ptr);
	sfree (vl.values); 

	fprintf (fh, "0 Success\n");
	fflush (fh);

	return (0);
} /* int us_handle_putval */

