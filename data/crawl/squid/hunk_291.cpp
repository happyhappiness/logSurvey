 };
 
 /// TLS Handshake Protocol frame from RFC 5246 Section 7.4.
-struct Handshake: public FieldGroup
+struct Handshake
 {
     explicit Handshake(BinaryTokenizer &tk);
 
+    BinaryTokenizerContext context; ///< parsing context for debugging
+
     uint32_t msg_type: 8; ///< HandshakeType
     uint32_t length: 24;
     SBuf body; ///< Handshake Protocol message, exactly length bytes
 };
 
 /// TLS Alert protocol frame from RFC 5246 Section 7.2.
-struct Alert: public FieldGroup
+struct Alert
 {
     explicit Alert(BinaryTokenizer &tk);
+
+
+    bool fatal() const { return level == 2; }
+
+    BinaryTokenizerContext context; ///< parsing context for debugging
+
     uint8_t level; ///< warning or fatal
     uint8_t description; ///< close_notify, unexpected_message, etc.
 };
 
-struct Extension: public FieldGroup
+/// TLS Hello Extension from RFC 5246 Section 7.4.1.4.
+struct Extension
 {
     explicit Extension(BinaryTokenizer &tk);
+
+    BinaryTokenizerContext context; ///< parsing context for debugging
+
     uint16_t type;
-    uint16_t length;
+    uint16_t length; // XXX just use SBuf!
     SBuf body;
 };
 
