     case V7_FORMAT:
       if (strlen (st->file_name) > NAME_FIELD_SIZE-1)
 	{
-	  WARN ((0, 0, _("%s: file name is too long (max %d); not dumped"),
-		 quotearg_colon (st->file_name),
-		 NAME_FIELD_SIZE - 1));
+	  ERROR ((0, 0, _("%s: file name is too long (max %d); not dumped"),
+		  quotearg_colon (st->file_name),
+		  NAME_FIELD_SIZE - 1));
 	  return NULL;
 	}
       break;
