		free(data);
		return hit;
	}
	die(_("unable to grep from object of type %s"), type_name(obj->type));
}

static int grep_objects(struct grep_opt *opt, const struct pathspec *pathspec,
