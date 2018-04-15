		{
			/* parse_option failed, buffer has been modified.
			 * => we need to abort */
			print_to_socket (fh, "-1 Misformatted option.\n");
			sfree (vl.values);
			return (-1);
		}
		else if (status == 0)
		{
