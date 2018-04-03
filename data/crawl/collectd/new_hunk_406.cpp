				else if (strcasecmp (optarg, "percentage") == 0)
					consolitation_g = CON_PERCENTAGE;
				else
				{
					fprintf (stderr, "Unknown consolidation function `%s'.\n",
							optarg);
					usage (argv[0]);
				}
				break;
			case 'd':
			{
