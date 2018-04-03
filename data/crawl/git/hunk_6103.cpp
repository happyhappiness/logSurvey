 		return add_man_viewer_cmd(name, subkey - name, value);
 	}
 
-	warning("'%s': unsupported man viewer sub key.", subkey);
 	return 0;
 }
 