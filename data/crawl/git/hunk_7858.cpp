 	}
 }
 
+static int git_index_pack_config(const char *k, const char *v)
+{
+	if (!strcmp(k, "pack.indexversion")) {
+		pack_idx_default_version = git_config_int(k, v);
+		if (pack_idx_default_version > 2)
+			die("bad pack.indexversion=%d", pack_idx_default_version);
+		return 0;
+	}
+	return git_default_config(k, v);
+}
+
 int main(int argc, char **argv)
 {
 	int i, fix_thin_pack = 0;
