			case OBJ_BLOB:
				handle_object(tag->object.sha1);
				continue;
			}
			break;
		default:
