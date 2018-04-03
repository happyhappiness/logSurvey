	}
}

static void send_shallow(struct commit_list *result)
{
	while (result) {
		struct object *object = &result->item->object;
		if (!(object->flags & (CLIENT_SHALLOW|NOT_SHALLOW))) {
			packet_write(1, "shallow %s",
				     oid_to_hex(&object->oid));
			register_shallow(object->oid.hash);
			shallow_nr++;
		}
		result = result->next;
	}
}

static void deepen(int depth, const struct object_array *shallows)
{
	struct commit_list *result = NULL, *backup = NULL;
