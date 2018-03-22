				 _("contents not dumped"));
	  directory->children = NO_CHILDREN;
	  break;

	case exclusion_tag_under:
	  exclusion_tag_warning (name_buffer, tag_file_name,
				 _("contents not dumped"));
	  directory->tagfile = tag_file_name;
	  break;

	case exclusion_tag_none:
	  break;
	}
