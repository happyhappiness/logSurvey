				else if (strcasecmp (optarg, "percentage") == 0)
					consolitation_g = CON_PERCENTAGE;
				else
					usage (argv[0]);
				break;
			case 'd':
			{
