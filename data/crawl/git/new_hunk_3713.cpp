				/* fallthru */
			case VERBATIM:
				break;
			case WARN_STRIP:
				warning ("Stripping signature from tag %s",
					 sha1_to_hex(tag->object.sha1));
				/* fallthru */
			case STRIP:
				message_size = signature + 1 - message;
				break;
