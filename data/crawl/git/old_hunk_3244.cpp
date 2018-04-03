	if (batch.enabled)
		return batch_objects(&batch);

	return cat_one_file(opt, exp_type, obj_name);
}