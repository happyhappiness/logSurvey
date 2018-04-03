 // TODO: destruction should be sufficient as the destructor should cleanup,
 // including canceling close handlers
 void
-HttpStateData::abortTransaction(const char *reason)
+HttpStateData::abortAll(const char *reason)
 {
     debugs(11,5, HERE << "aborting transaction for " << reason <<
            "; " << serverConnection << ", this " << this);
