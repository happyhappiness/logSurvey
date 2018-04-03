 					die ("Invalid regular expression: %s",
 							o->word_regex);
 			}
+			for (i = 0; i < ARRAY_SIZE(diff_words_styles); i++) {
+				if (o->word_diff == diff_words_styles[i].type) {
+					ecbdata.diff_words->style =
+						&diff_words_styles[i];
+					break;
+				}
+			}
+			if (DIFF_OPT_TST(o, COLOR_DIFF)) {
+				struct diff_words_style *st = ecbdata.diff_words->style;
+				st->old.color = diff_get_color_opt(o, DIFF_FILE_OLD);
+				st->new.color = diff_get_color_opt(o, DIFF_FILE_NEW);
+				st->ctx.color = diff_get_color_opt(o, DIFF_PLAIN);
+			}
 		}
 		xdi_diff_outf(&mf1, &mf2, fn_out_consume, &ecbdata,
 			      &xpp, &xecfg, &ecb);
-		if (DIFF_OPT_TST(o, COLOR_DIFF_WORDS))
+		if (o->word_diff)
 			free_diff_words_data(&ecbdata);
 		if (textconv_one)
 			free(mf1.ptr);
