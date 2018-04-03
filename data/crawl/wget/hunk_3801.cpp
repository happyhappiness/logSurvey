     }
 }
 
+static int find_fragment PARAMS ((const char *, int, const char **,
+				  const char **));
+
+static void
+replace_attr (const char **pp, int raw_size, FILE *fp, const char *new_str)
+{
+  const char *p = *pp;
+  int quote_flag = 0;
+  int size = raw_size;
+  char quote_char = '\"';
+  const char *frag_beg, *frag_end;
+
+  /* Structure of our string is:
+       "...old-contents..."
+       <---  l->size   --->  (with quotes)
+     OR:
+       ...old-contents...
+       <---  l->size  -->    (no quotes)   */
+
+  if (*p == '\"' || *p == '\'')
+    {
+      quote_char = *p;
+      quote_flag = 1;
+      ++p;
+      size -= 2;		/* disregard opening and closing quote */
+    }
+  putc (quote_char, fp);
+  fputs (new_str, fp);
+
+  /* Look for fragment identifier, if any. */
+  if (find_fragment (p, size, &frag_beg, &frag_end))
+    fwrite (frag_beg, 1, frag_end - frag_beg, fp);
+  p += size;
+  if (quote_flag)
+    ++p;
+  putc (quote_char, fp);
+  *pp = p;
+}
+
+/* Find the first occurrence of '#' in [BEG, BEG+SIZE) that is not
+   preceded by '&'.  If the character is not found, return zero.  If
+   the character is found, return 1 and set BP and EP to point to the
+   beginning and end of the region.
+
+   This is used for finding the fragment indentifiers in URLs.  */
+
+static int
+find_fragment (const char *beg, int size, const char **bp, const char **ep)
+{
+  const char *end = beg + size;
+  int saw_amp = 0;
+  for (; beg < end; beg++)
+    {
+      switch (*beg)
+	{
+	case '&':
+	  saw_amp = 1;
+	  break;
+	case '#':
+	  if (!saw_amp)
+	    {
+	      *bp = beg;
+	      *ep = end;
+	      return 1;
+	    }
+	  /* fallthrough */
+	default:
+	  saw_amp = 0;
+	}
+    }
+  return 0;
+}
+
 typedef struct _downloaded_file_list {
   char*                          file;
   downloaded_file_t              download_type;
