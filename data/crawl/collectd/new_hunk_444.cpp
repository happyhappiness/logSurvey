		{
			fprintf (stderr, "irq plugin: Irq value is not a "
					"number: `%s'\n", value);
			ERROR ("irq plugin: Irq value is not a "
					"number: `%s'", value);
			return (1);
		}
