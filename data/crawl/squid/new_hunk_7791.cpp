    }
    close(0);

    if (!strcmp(operation, "info") ||
	!strcmp(operation, "Cache Information")) {
	op = INFO;
    } else if (!strcmp(operation, "squid.conf") ||
	!strcmp(operation, "Cache Configuration File")) {
	op = CACHED;
    } else if (!strcmp(operation, "server_list") ||
	!strcmp(operation, "Cache Server List")) {
	op = SERVER;
#ifdef MENU_SHOW_LOG
    } else if (!strcmp(operation, "log") ||
	!strcmp(operation, "Cache Log")) {
	op = LOG;
#endif
    } else if (!strcmp(operation, "parameter") ||
	!strcmp(operation, "Cache Parameters")) {
	op = PARAM;
    } else if (!strcmp(operation, "stats/general") ||
	!strcmp(operation, "General Statistics")) {
	op = STATS_G;
    } else if (!strcmp(operation, "stats/vm_objects") ||
	!strcmp(operation, "VM_Objects")) {
	op = STATS_VM;
    } else if (!strcmp(operation, "stats/objects") ||
	!strcmp(operation, "Objects")) {
	op = STATS_O;
    } else if (!strcmp(operation, "stats/utilization") ||
	!strcmp(operation, "Utilization")) {
	op = STATS_U;
    } else if (!strcmp(operation, "shutdown")) {
	op = SHUTDOWN;
    } else if (!strcmp(operation, "refresh")) {
	op = REFRESH;
#ifdef REMOVE_OBJECT
    } else if (!strcmp(operation, "remove")) {
	op = REMOVE;
#endif
    } else {
	printf("Unknown operation: %s\n", operation);
	exit(0);
    }

    switch (op) {
    case INFO:
    case CACHED:
    case SERVER:
    case LOG:
    case PARAM:
    case STATS_G:
    case STATS_O:
    case STATS_VM:
    case STATS_U:
	sprintf(msg, "GET cache_object://%s/%s HTTP/1.0\r\n\r\n",
	    hostname, op_cmds[op]);
	break;
    case SHUTDOWN:
	sprintf(msg, "GET cache_object://%s/%s@%s HTTP/1.0\r\n\r\n",
	    hostname, op_cmds[op], password);
	break;
    case REFRESH:
	sprintf(msg, "GET %s HTTP/1.0\r\nPragma: no-cache\r\nAccept: */*\r\n\r\n", url);
	break;
#ifdef REMOVE_OBJECT
    case REMOVE:
	printf("Remove not yet supported\n");
	exit(0);
	/* NOTREACHED */
#endif
    default:
    case MAXOP:
	printf("Unknown operation: %s\n", operation);
	exit(0);
	/* NOTREACHED */
    }

    time_val = time(NULL);
    time_string = ctime(&time_val);
