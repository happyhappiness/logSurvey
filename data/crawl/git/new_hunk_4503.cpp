			strcat(delref, ref);
			ref = delref;
		} else if (deleterefs)
			die(_("--delete only accepts plain target ref names"));
		add_refspec(ref);
	}
}
