		o = want_obj.objects[i].item;
		if (!is_our_ref(o))
			die("git upload-pack: not our ref %s",
			    oid_to_hex(&o->oid));
	}
}

