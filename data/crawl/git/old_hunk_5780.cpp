	case -ERR_RUN_COMMAND_WAITPID_NOEXIT:
		return error("%s died strangely", cmd_name);
	default:
		error("%s exited with error code %d", cmd_name, -code);
		return -code;
	}
}

