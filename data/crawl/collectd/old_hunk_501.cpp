		if (temp == NULL)
		{
			fprintf (stderr, "irq plugin: Cannot allocate more memory.\n");
			syslog (LOG_ERR, "irq plugin: Cannot allocate more memory.");
			return (1);
		}
		irq_list = temp;
