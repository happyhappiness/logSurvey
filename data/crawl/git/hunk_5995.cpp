 	if (start_active_slot(slot)) {
 		run_active_slot(slot);
 		if (results.curl_result != CURLE_OK) {
-			free(url);
-			fclose(indexfile);
-			slot->local = NULL;
-			return error("Unable to get pack index %s\n%s", url,
-				     curl_errorstr);
+			ret = error("Unable to get pack index %s\n%s", url,
+				    curl_errorstr);
+			goto cleanup_index;
 		}
 	} else {
-		free(url);
-		fclose(indexfile);
-		slot->local = NULL;
-		return error("Unable to start request");
+		ret = error("Unable to start request");
+		goto cleanup_index;
 	}
 
-	free(url);
+	ret = move_temp_to_file(tmpfile, filename);
+
+cleanup_index:
 	fclose(indexfile);
 	slot->local = NULL;
-
-	return move_temp_to_file(tmpfile, filename);
+cleanup_pack:
+	free(url);
+	free(hex);
+	return ret;
 }
 
 static int setup_index(struct walker *walker, struct alt_base *repo, unsigned char *sha1)