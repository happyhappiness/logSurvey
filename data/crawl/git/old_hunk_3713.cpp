				/* fallthru */
			case VERBATIM:
				break;
			case STRIP:
				message_size = signature + 1 - message;
				break;
