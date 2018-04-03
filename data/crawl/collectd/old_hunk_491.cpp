		else if (ds->ds[i].type == DS_TYPE_GAUGE)
			vl.values[i].gauge = atof (value_ptr[i]);
	} /* for (i = 2 .. fields_num) */
	sfree (value_ptr);

	plugin_dispatch_values (type, &vl);

	sfree (vl.values); 

	return (0);
} /* int us_handle_putval */

