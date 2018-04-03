     /* ok, user saw [0,Ctx_Reported_Level] descriptions */
     /* first inform about entries popped since user saw them */
     if (Ctx_Valid_Level < Ctx_Reported_Level) {
-	if (Ctx_Reported_Level != Ctx_Valid_Level+1)
-	    _db_print("ctx: exit levels from %2d down to %2d\n", 
-		Ctx_Reported_Level, Ctx_Valid_Level+1);
+	if (Ctx_Reported_Level != Ctx_Valid_Level + 1)
+	    _db_print("ctx: exit levels from %2d down to %2d\n",
+		Ctx_Reported_Level, Ctx_Valid_Level + 1);
 	else
 	    _db_print("ctx: exit level %2d\n", Ctx_Reported_Level);
 	Ctx_Reported_Level = Ctx_Valid_Level;
