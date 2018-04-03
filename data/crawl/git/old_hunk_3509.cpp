			if (cutoff > commit->date)
				cutoff = commit->date;
		}
		add_object_array(object, *argv, &revs);
	}

