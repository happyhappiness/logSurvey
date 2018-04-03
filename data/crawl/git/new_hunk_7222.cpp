			obj_type = (allow_ofs_delta && entry->delta->idx.offset) ?
				OBJ_OFS_DELTA : OBJ_REF_DELTA;
		} else {
			buf = get_delta(entry);
			size = entry->delta_size;
			obj_type = (allow_ofs_delta && entry->delta->idx.offset) ?
				OBJ_OFS_DELTA : OBJ_REF_DELTA;