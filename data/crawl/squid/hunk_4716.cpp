 
         assignment_header = (struct wccp2_item_header_t *) &wccp_packet[offset];
 
-        assignment_header->type = htons(WCCP2_REDIRECT_ASSIGNMENT);
+        switch (Config.Wccp2.assignment_method) {
 
-        offset += sizeof(struct wccp2_item_header_t);
+        case WCCP2_ASSIGNMENT_METHOD_HASH:
+            assignment_header->type = htons(WCCP2_REDIRECT_ASSIGNMENT);
+
+            offset += sizeof(struct wccp2_item_header_t);
+            assignment_offset = offset;
+            break;
+
+        case WCCP2_ASSIGNMENT_METHOD_MASK:
+            assignment_header->type = htons(WCCP2_ALT_ASSIGNMENT);
+
+            offset += sizeof(struct wccp2_item_header_t);
+            assignment_offset = offset;
+
+            /* The alternative assignment has an extra header, fill in length later */
+
+            alt_assignment_type_header = (struct wccp2_item_header_t *) &wccp_packet[offset];
+            alt_assignment_type_header->type = htons(WCCP2_MASK_ASSIGNMENT);
+
+            offset += sizeof(struct wccp2_item_header_t);
+            alt_assignment_offset = offset;
+
+            break;
+
+        default:
+            fatalf("Unknown Wccp2 assignment method\n");
+        }
 
         /* Assignment key - fill in master ip later */
 
