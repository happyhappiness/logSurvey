			strcat(delref, ref);
			ref = delref;
		} else if (deleterefs)
			die("--delete only accepts plain target ref names");
		add_refspec(ref);
	}
}
