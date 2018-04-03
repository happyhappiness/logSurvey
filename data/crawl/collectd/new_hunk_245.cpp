		}
		irq_list = temp;

		irq_list[irq_list_num] = strdup (value);
		if (irq_list[irq_list_num] == NULL)
		{
			ERROR ("irq plugin: strdup(3) failed.");
			return (1);
		}

		irq_list_num++;
	}
	else if (strcasecmp (key, "IgnoreSelected") == 0)
