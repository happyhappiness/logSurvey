 			XML_SetElementHandler(parser, xml_start_tag,
 					      xml_end_tag);
 			XML_SetCharacterDataHandler(parser, xml_cdata);
-			result = XML_Parse(parser, in_buffer.buffer,
-					   in_buffer.posn, 1);
+			result = XML_Parse(parser, in_buffer.buf,
+					   in_buffer.len, 1);
 			free(ctx.name);
 			if (result != XML_STATUS_OK) {
 				fprintf(stderr, "XML error: %s\n",
