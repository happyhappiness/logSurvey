				packet_write(1, "shallow %s",
						sha1_to_hex(object->sha1));
				register_shallow(object->sha1);
			}
			result = result->next;
		}