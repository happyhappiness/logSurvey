		}
		irq_list = temp;

		/* Clear errno, because we need it to see if an error occured. */
		errno = 0;

		irq = strtol(value, &endptr, 10);
		if ((endptr == value) || (errno != 0))
		{
			fprintf (stderr, "irq plugin: Irq value is not a "
					"number: `%s'\n", value);
			ERROR ("irq plugin: Irq value is not a "
					"number: `%s'", value);
			return (1);
		}
		irq_list[irq_list_num] = irq;
		irq_list_num++;
	}
	else if (strcasecmp (key, "IgnoreSelected") == 0)
