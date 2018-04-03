		printf("broken link from %7s %s\n",
			   printable_type(parent), describe_object(parent));
		printf("broken link from %7s %s\n",
			   (type == OBJ_ANY ? "unknown" : type_name(type)), "unknown");
		errors_found |= ERROR_REACHABLE;
		return 1;
	}
