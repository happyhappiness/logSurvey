     String getListMember(http_hdr_type id, const char *member, const char separator) const;
     int has(http_hdr_type id) const;
     void putInt(http_hdr_type id, int number);
+    void putInt64(http_hdr_type id, int64_t number);
     void putTime(http_hdr_type id, time_t htime);
     void insertTime(http_hdr_type id, time_t htime);
     void putStr(http_hdr_type id, const char *str);
