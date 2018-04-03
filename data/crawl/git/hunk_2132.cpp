 
 int main(int ac, char **av)
 {
-	unsigned char hash1[20], hash2[20], shifted[20];
+	struct object_id hash1, hash2, shifted;
 	struct tree *one, *two;
 
-	if (get_sha1(av[1], hash1))
+	if (get_oid(av[1], &hash1))
 		die("cannot parse %s as an object name", av[1]);
-	if (get_sha1(av[2], hash2))
+	if (get_oid(av[2], &hash2))
 		die("cannot parse %s as an object name", av[2]);
-	one = parse_tree_indirect(hash1);
+	one = parse_tree_indirect(hash1.hash);
 	if (!one)
 		die("not a tree-ish %s", av[1]);
-	two = parse_tree_indirect(hash2);
+	two = parse_tree_indirect(hash2.hash);
 	if (!two)
 		die("not a tree-ish %s", av[2]);
 
-	shift_tree(one->object.oid.hash, two->object.oid.hash, shifted, -1);
-	printf("shifted: %s\n", sha1_to_hex(shifted));
+	shift_tree(one->object.oid.hash, two->object.oid.hash, shifted.hash, -1);
+	printf("shifted: %s\n", oid_to_hex(&shifted));
 
 	exit(0);
 }