 
 	dst_cmd->skip_update = 1;
 
-	find_unique_abbrev_r(cmd_oldh, cmd->old_sha1, DEFAULT_ABBREV);
-	find_unique_abbrev_r(cmd_newh, cmd->new_sha1, DEFAULT_ABBREV);
-	find_unique_abbrev_r(dst_oldh, dst_cmd->old_sha1, DEFAULT_ABBREV);
-	find_unique_abbrev_r(dst_newh, dst_cmd->new_sha1, DEFAULT_ABBREV);
 	rp_error("refusing inconsistent update between symref '%s' (%s..%s) and"
 		 " its target '%s' (%s..%s)",
-		 cmd->ref_name, cmd_oldh, cmd_newh,
-		 dst_cmd->ref_name, dst_oldh, dst_newh);
+		 cmd->ref_name,
+		 find_unique_abbrev(cmd->old_sha1, DEFAULT_ABBREV),
+		 find_unique_abbrev(cmd->new_sha1, DEFAULT_ABBREV),
+		 dst_cmd->ref_name,
+		 find_unique_abbrev(dst_cmd->old_sha1, DEFAULT_ABBREV),
+		 find_unique_abbrev(dst_cmd->new_sha1, DEFAULT_ABBREV));
 
 	cmd->error_string = dst_cmd->error_string =
 		"inconsistent aliased update";