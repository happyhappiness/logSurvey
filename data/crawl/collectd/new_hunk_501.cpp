		if (temp == NULL)
		{
			fprintf (stderr, "irq plugin: Cannot allocate more memory.\n");
			ERROR ("irq plugin: Cannot allocate more memory.");
			return (1);
		}
		irq_list = temp;
