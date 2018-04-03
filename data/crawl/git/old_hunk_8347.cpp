		while (c & 128) {
			base_offset += 1;
			if (!base_offset || MSB(base_offset, 7))
				bad_object(obj->offset, "offset value overflow for delta base object");
			p = fill(1);
			c = *p;
			use(1);
			base_offset = (base_offset << 7) + (c & 127);
		}
		delta_base->offset = obj->offset - base_offset;
		if (delta_base->offset >= obj->offset)
			bad_object(obj->offset, "delta base offset is out of bound");
		break;
	case OBJ_COMMIT:
	case OBJ_TREE:
	case OBJ_BLOB:
	case OBJ_TAG:
		break;
	default:
		bad_object(obj->offset, "unknown object type %d", obj->type);
	}
	obj->hdr_size = consumed_bytes - obj->offset;

	data = unpack_entry_data(obj->offset, obj->size);
	obj->crc32 = input_crc32;
	return data;
}

static void *get_data_from_pack(struct object_entry *obj)
{
	unsigned long from = obj[0].offset + obj[0].hdr_size;
	unsigned long len = obj[1].offset - from;
	unsigned long rdy = 0;
	unsigned char *src, *data;
	z_stream stream;
