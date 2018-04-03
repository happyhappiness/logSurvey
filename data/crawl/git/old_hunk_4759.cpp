					errno = EEXIST;
					/* fallthru */
				case -1:
					die_errno("cannot mkdir %s", argv[0]);
					break;
				default:
					break;
				}
				shared_repository = saved;
				if (mkdir(argv[0], 0777) < 0)
					die_errno("cannot mkdir %s", argv[0]);
				mkdir_tried = 1;
				goto retry;
			}
			die_errno("cannot chdir to %s", argv[0]);
		}
	} else if (0 < argc) {
		usage(init_db_usage[0]);
