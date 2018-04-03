     virtual void delayRead(DeferredRead const &) {fatal("Not implemented");}
 };
 
-#endif
+#endif /* USE_DELAY_POOLS */
 #endif /* DELAYIDCOMPOSITE_H */
