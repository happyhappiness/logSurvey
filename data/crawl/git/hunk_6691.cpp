 	/* On-disk flags are just 16 bits */
 	ce->ce_flags = ntohs(ondisk->flags);
 
-	/* For future extension: we do not understand this entry yet */
-	if (ce->ce_flags & CE_EXTENDED)
-		die("Unknown index entry format");
 	hashcpy(ce->sha1, ondisk->sha1);
 
 	len = ce->ce_flags & CE_NAMEMASK;
+
+	if (ce->ce_flags & CE_EXTENDED) {
+		struct ondisk_cache_entry_extended *ondisk2;
+		int extended_flags;
+		ondisk2 = (struct ondisk_cache_entry_extended *)ondisk;
+		extended_flags = ntohs(ondisk2->flags2) << 16;
+		/* We do not yet understand any bit out of CE_EXTENDED_FLAGS */
+		if (extended_flags & ~CE_EXTENDED_FLAGS)
+			die("Unknown index entry format %08x", extended_flags);
+		ce->ce_flags |= extended_flags;
+		name = ondisk2->name;
+	}
+	else
+		name = ondisk->name;
+
 	if (len == CE_NAMEMASK)
-		len = strlen(ondisk->name);
+		len = strlen(name);
 	/*
 	 * NEEDSWORK: If the original index is crafted, this copy could
 	 * go unchecked.
 	 */
-	memcpy(ce->name, ondisk->name, len + 1);
+	memcpy(ce->name, name, len + 1);
 }
 
 static inline size_t estimate_cache_size(size_t ondisk_size, unsigned int entries)
