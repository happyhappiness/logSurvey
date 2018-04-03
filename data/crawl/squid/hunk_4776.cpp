 }
 
 std::ostream &
-Debug::getDebugOut()
-{
+Debug::getDebugOut() {
     assert (CurrentDebug == NULL);
     CurrentDebug = new std::ostringstream();
     return *CurrentDebug;
 }
 
 void
-Debug::finishDebug()
-{
+Debug::finishDebug() {
     _db_print("%s\n", CurrentDebug->str().c_str());
     delete CurrentDebug;
     CurrentDebug = NULL;
