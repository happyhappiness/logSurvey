		else
			target_host = xstrdup(hostandport);

		transport_check_allowed("git");

		/* These underlying connection commands die() if they
		 * cannot connect.
		 */
