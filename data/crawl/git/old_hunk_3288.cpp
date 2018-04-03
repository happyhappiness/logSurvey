			}
			if (obj->type == OBJ_COMMIT) {
				struct commit *commit = (struct commit *) obj;
				commit->buffer = NULL;
			}
			obj->flags |= FLAG_CHECKED;
		}
