 	alias_all_urls();
 }
 
-struct refspec *parse_ref_spec(int nr_refspec, const char **refspec)
+static struct refspec *parse_refspec_internal(int nr_refspec, const char **refspec, int fetch)
 {
 	int i;
 	int st;
 	struct refspec *rs = xcalloc(sizeof(*rs), nr_refspec);
+
 	for (i = 0; i < nr_refspec; i++) {
-		const char *sp, *ep, *gp;
-		sp = refspec[i];
-		if (*sp == '+') {
+		size_t llen, rlen;
+		int is_glob;
+		const char *lhs, *rhs;
+
+		llen = rlen = is_glob = 0;
+
+		lhs = refspec[i];
+		if (*lhs == '+') {
 			rs[i].force = 1;
-			sp++;
-		}
-		gp = strstr(sp, "/*");
-		ep = strchr(sp, ':');
-		if (gp && ep && gp > ep)
-			gp = NULL;
-		if (ep) {
-			if (ep[1]) {
-				const char *glob = strstr(ep + 1, "/*");
-				if (glob && glob[2])
-					glob = NULL;
-				if (!glob)
-					gp = NULL;
-				if (gp)
-					rs[i].dst = xstrndup(ep + 1,
-							     glob - ep - 1);
-				else
-					rs[i].dst = xstrdup(ep + 1);
-			}
-		} else {
-			ep = sp + strlen(sp);
+			lhs++;
 		}
-		if (gp && gp + 2 != ep)
-			gp = NULL;
-		if (gp) {
-			rs[i].pattern = 1;
-			ep = gp;
+
+		rhs = strrchr(lhs, ':');
+		if (rhs) {
+			rhs++;
+			rlen = strlen(rhs);
+			is_glob = (2 <= rlen && !strcmp(rhs + rlen - 2, "/*"));
+			rs[i].dst = xstrndup(rhs, rlen - is_glob * 2);
 		}
-		rs[i].src = xstrndup(sp, ep - sp);
 
-		if (*rs[i].src) {
-			st = check_ref_format(rs[i].src);
-			if (st && st != CHECK_REF_FORMAT_ONELEVEL)
-				die("Invalid refspec '%s'", refspec[i]);
+		llen = (rhs ? (rhs - lhs - 1) : strlen(lhs));
+		if (is_glob != (2 <= llen && !memcmp(lhs + llen - 2, "/*", 2)))
+			goto invalid;
+
+		if (is_glob) {
+			llen -= 2;
+			rlen -= 2;
 		}
-		if (rs[i].dst && *rs[i].dst) {
-			st = check_ref_format(rs[i].dst);
-			if (st && st != CHECK_REF_FORMAT_ONELEVEL)
-				die("Invalid refspec '%s'", refspec[i]);
+		rs[i].pattern = is_glob;
+		rs[i].src = xstrndup(lhs, llen);
+
+		if (fetch) {
+			/*
+			 * LHS
+			 * - empty is allowed; it means HEAD.
+			 * - otherwise it must be a valid looking ref.
+			 */
+			if (!*rs[i].src)
+				; /* empty is ok */
+			else {
+				st = check_ref_format(rs[i].src);
+				if (st && st != CHECK_REF_FORMAT_ONELEVEL)
+					goto invalid;
+			}
+			/*
+			 * RHS
+			 * - missing is allowed.
+			 * - empty is ok; it means not to store.
+			 * - otherwise it must be a valid looking ref.
+			 */
+			if (!rs[i].dst) {
+				; /* ok */
+			} else if (!*rs[i].dst) {
+				; /* ok */
+			} else {
+				st = check_ref_format(rs[i].dst);
+				if (st && st != CHECK_REF_FORMAT_ONELEVEL)
+					goto invalid;
+			}
+		} else {
+			/*
+			 * LHS
+			 * - empty is allowed; it means delete.
+			 * - when wildcarded, it must be a valid looking ref.
+			 * - otherwise, it must be an extended SHA-1, but
+			 *   there is no existing way to validate this.
+			 */
+			if (!*rs[i].src)
+				; /* empty is ok */
+			else if (is_glob) {
+				st = check_ref_format(rs[i].src);
+				if (st && st != CHECK_REF_FORMAT_ONELEVEL)
+					goto invalid;
+			}
+			else
+				; /* anything goes, for now */
+			/*
+			 * RHS
+			 * - missing is allowed, but LHS then must be a
+			 *   valid looking ref.
+			 * - empty is not allowed.
+			 * - otherwise it must be a valid looking ref.
+			 */
+			if (!rs[i].dst) {
+				st = check_ref_format(rs[i].src);
+				if (st && st != CHECK_REF_FORMAT_ONELEVEL)
+					goto invalid;
+			} else if (!*rs[i].dst) {
+				goto invalid;
+			} else {
+				st = check_ref_format(rs[i].dst);
+				if (st && st != CHECK_REF_FORMAT_ONELEVEL)
+					goto invalid;
+			}
 		}
 	}
 	return rs;
+
+ invalid:
+	die("Invalid refspec '%s'", refspec[i]);
+}
+
+struct refspec *parse_fetch_refspec(int nr_refspec, const char **refspec)
+{
+	return parse_refspec_internal(nr_refspec, refspec, 1);
+}
+
+struct refspec *parse_push_refspec(int nr_refspec, const char **refspec)
+{
+	return parse_refspec_internal(nr_refspec, refspec, 0);
 }
 
 static int valid_remote_nick(const char *name)
