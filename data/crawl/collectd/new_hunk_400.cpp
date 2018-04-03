		{
			fprintf (stderr, "rrdtool: `RRARows' must "
					"be greater than 0.\n");
			ERROR ("rrdtool: `RRARows' must "
					"be greater than 0.\n");
			return (1);
		}
		rrarows = tmp;
