/ *   s e m a n t i c s   - -   * /  
  
 # i n c l u d e   " f l i n c l . h "  
 # i n c l u d e   " s h o r t s t a c k . h "  
 # i n c l u d e   " s e m a n t i c s . h "  
 # i n c l u d e   " s t d i o . h "   / /   f o r   c o m p i l e r . h  
 # i n c l u d e   " c o m p i l e r . h "  
 # i n c l u d e   " a s s e r t . h "  
  
 # d e f i n e   m u s t ( e m i t )   i f   ( ! ( e m i t ) )   r e t u r n   f a l s e ;  
  
 t y p e d e f   s t r u c t   {  
 	 c h a r   * n a m e ;  
 	 s h o r t   p a r a m s ;  
 	 s h o r t   o p ;  
 }   B u i l t i n _ d e s c ;  
  
 / /   b u i l t _ i n s   a r e   " g l o b a l   f u n c t i o n s "   t h a t   c a n n o t   b e  
 / /   o v e r r i d d e n   o r   o v e r l o a d e d  
 B u i l t i n _ d e s c   b u i l t _ i n s [ ]   =   {  
 	 {   " a r r a y " ,   1 ,   O P C O D E _ N E W A R R A Y   } ,  
         {   " d i c t " ,   1 ,   O P C O D E _ N E W D I C T   } ,  
         {   " f l a t t e n " ,   1 ,   O P C O D E _ F L A T T E N   } ,  
         {   " r e p r " ,   1 ,   O P C O D E _ R E P R   } ,  
         {   " s t r " ,   1 ,   O P C O D E _ S T R   } ,  
         {   " t y p e " ,   1 ,   O P C O D E _ T Y P E   } ,  
         {   " l e n " ,   1 ,   O P C O D E _ L E N G T H   } ,  
         {   " c o s " ,   1 ,   O P C O D E _ C O S   } ,  
         {   " s i n " ,   1 ,   O P C O D E _ S I N   } ,  
         {   " t a n " ,   1 ,   O P C O D E _ T A N   } ,  
         {   " e x p " ,   1 ,   O P C O D E _ E X P   } ,  
         {   " s q r t " ,   1 ,   O P C O D E _ S Q R T   } ,  
         {   " r e m " ,   1 ,   O P C O D E _ R E M   } ,  
         {   " m i n " ,   2 ,   O P C O D E _ M I N   } ,  
         {   " m a x " ,   2 ,   O P C O D E _ M A X   } ,  
         {   " r a n d o m " ,   0 ,   O P C O D E _ R A N D O M   } ,  
         {   " a b s " ,   1 ,   O P C O D E _ A B S   } ,  
         {   " i n t " ,   1 ,   O P C O D E _ T R U N C A T E   } ,  
         {   " r o u n d " ,   1 ,   O P C O D E _ R O U N D   } ,  
         {   " f l o a t " ,   1 ,   O P C O D E _ F L O A T   } ,  
         {   " c h r " ,   1 ,   O P C O D E _ C H R   } ,  
         {   " o r d " ,   1 ,   O P C O D E _ O R D   } ,  
         {   " h e x " ,   1 ,   O P C O D E _ H E X   } ,  
         {   " i d " ,   1 ,   O P C O D E _ I D   } ,  
         {   " i n t e r n " ,   1 ,   O P C O D E _ I N T E R N   } ,  
         {   " i s i n s t a n c e " ,   2 ,   O P C O D E _ I N S T   } ,  
         {   " i s s u b c l a s s " ,   2 ,   O P C O D E _ S U B C L   } ,  
         {   " o c t " ,   1 ,   O P C O D E _ O C T   } ,  
         {   " s t r c a t " ,   2 ,   O P C O D E _ S T R C A T   } ,  
         {   " s u b s e q " ,   3 ,   O P C O D E _ S U B S E Q   } ,  
         {   " i s u p p e r " ,   1 ,   O P C O D E _ I S U P P E R   } ,  
         {   " i s l o w e r " ,   1 ,   O P C O D E _ I S L O W E R   } ,  
         {   " i s a l p h a " ,   1 ,   O P C O D E _ I S A L P H A   } ,  
         {   " i s d i g i t " ,   1 ,   O P C O D E _ I S D I G I T   } ,  
         {   " i s a l n u m " ,   1 ,   O P C O D E _ I S A L N U M   } ,  
         {   " t o u p p e r " ,   1 ,   O P C O D E _ T O U P P E R   } ,  
         {   " t o l o w e r " ,   1 ,   O P C O D E _ T O L O W E R   } ,  
         {   " f i n d " ,   4 ,   O P C O D E _ F I N D   } ,  
 	 {   " e x i t " ,   0 ,   O P C O D E _ E X I T   } ,  
 	 {   " f r a m e _ p r e v i o u s " ,   1 ,   O P C O D E _ F R M P R E V   } ,  
 	 {   " f r a m e _ v a r i a b l e s " ,   1 ,   O P C O D E _ F R M V A R S   } ,  
 	 {   " f r a m e _ p c " ,   1 ,   O P C O D E _ F R M P C   } ,  
 	 {   " f r a m e _ m e t h o d " ,   1 ,   O P C O D E _ F R M M E T H   } ,  
 	 {   " f r a m e _ c l a s s " ,   1 ,   O P C O D E _ F R M C L A S S   } ,  
 	 {   " r u n t i m e _ e x c e p t i o n _ n e s t i n g " ,   0 ,   O P C O D E _ N E S T   } ,  
 	 {   " f r a m e _ g e t " ,   0 ,   O P C O D E _ F R M G E T   } ,  
 	 {   N U L L ,   0 ,   0   }  
 } ;  
  
 / /   b u i l t i n _ m e t h o d s   a r e   i m p l e m e n t e d   b y   o p e r _ c o d e s ,  
 / /   b u t   i f   t h e   f i r s t   o p e r a n d ' s   t y p e   i s   o b j e c t ,  
 / /   a   m e t h o d   l o o k u p   i s   p e r f o r m e d .   B u i l t i n _ m e t h o d s  
 / /   a l l o w   u s   t o   i m p l e m e n t   b u i l t i n   m e t h o d s   o n   b u i l t i n  
 / /   t y p e s ,   a n d   r u n   m o r e   e f f i c i e n t l y   t h a n   a   f u l l  
 / /   m e t h o d   c a l l   w h i c h   a l l o c a t e s   a   f r a m e .  
 B u i l t i n _ d e s c   b u i l t i n _ m e t h o d s [ ]   =   {  
         {   " r e a d l i n e " ,   0 ,   O P C O D E _ R E A D L I N E   } ,  
         {   " w r i t e " ,   1 ,   O P C O D E _ W R I T E   } ,  
         {   " r e a d " ,   1 ,   O P C O D E _ R E A D   } ,  
 	 {   " u n r e a d " ,   1 ,   O P C O D E _ U N R E A D   } ,  
         {   " r e a d v a l u e " ,   0 ,   O P C O D E _ R E A D V A L   } ,  
         {   " c l o s e " ,   0 ,   O P C O D E _ C L O S E   } ,  
         {   " t o k e n " ,   0 ,   O P C O D E _ T O K E N   } ,  
 	 {   " a p p e n d " ,   1 ,   O P C O D E _ A P P E N D   } ,  
 	 {   " u n a p p e n d " ,   0 ,   O P C O D E _ U N A P P E N D   } ,  
         {   " l a s t " ,   0 ,   O P C O D E _ L A S T   } ,  
         {   " k e y s " ,   0 ,   O P C O D E _ K E Y S   } ,  
         {   " v a l u e s " ,   0 ,   O P C O D E _ V A L U E S   } ,  
         {   " c l e a r " ,   0 ,   O P C O D E _ C L E A R   } ,  
         {   " i n d e x " ,   1 ,   O P C O D E _ I N D E X   } ,  
         {   " r e v e r s e " ,   0 ,   O P C O D E _ R E V E R S E   } ,  
         {   " s o r t " ,   0 ,   O P C O D E _ S O R T   } ,  
         {   " r e m o v e " ,   1 ,   O P C O D E _ R E M O V E   } ,  
         {   " c o p y " ,   0 ,   O P C O D E _ C O P Y   } ,  
         {   " h a s _ k e y " ,   1 ,   O P C O D E _ H A S K E Y   } ,  
         {   " g e t " ,   2 ,   O P C O D E _ G E T   } ,  
 	 {   " v a l u e " ,   0 ,   O P C O D E _ V A L U E   } ,  
         / /   {   " g e t 2 " ,   2 ,   O P C O D E _ G E T 2   } ,  
         {   N U L L ,   0 ,   0   }  
 } ;  
  
  
  
 / /   b u i l t i n   - -   s e a r c h e s   f o r   i d   i n   b u i l t - i n   l i s t  
 / /  
 / /   i f   f o u n d ,   r e t u r n   o p - c o d e   r e q u i r e d   t o   e x e c u t e   t h e   b u i l t - i n  
 / /   a n d   s e t   a c t u a l s   t o   t h e   n u m b e r   o f   p a r a m e t e r s   r e q u i r e d   b y  
 / /   t h e   b u i l t - i n   f u n c t i o n  
 / /   o t h e r w i s e ,   r e t u r n   0   a n d   s e t   a c t u a l s   t o   - 1  
 / /  
 s h o r t   S e m : : b u i l t i n ( c h a r   * i d ,   s h o r t   * a c t u a l s )  
 {  
         i n t   i   =   0 ;  
 	 w h i l e   ( b u i l t _ i n s [ i ] . n a m e )   {  
 	 	 i f   ( s t r e q l ( b u i l t _ i n s [ i ] . n a m e ,   i d ) )   {  
 	 	 	 * a c t u a l s   =   b u i l t _ i n s [ i ] . p a r a m s ;  
 	 	 	 r e t u r n   i n s t r _ c o m p o s e ( i n s t r _ o p ,   b u i l t _ i n s [ i ] . o p ) ;  
 	 	 }  
 	 	 i + + ;  
 	 }  
 	 * a c t u a l s   =   - 1 ;  
 	 r e t u r n   0 ;  
 }  
  
  
 s h o r t   S e m : : b u i l t i n _ m e t h o d ( c h a r   * i d ,   s h o r t   * a c t u a l s )  
 {  
         i n t   i   =   0 ;  
         w h i l e   ( b u i l t i n _ m e t h o d s [ i ] . n a m e )   {  
                 i f   ( s t r e q l ( b u i l t i n _ m e t h o d s [ i ] . n a m e ,   i d ) )   {  
                         * a c t u a l s   =   b u i l t i n _ m e t h o d s [ i ] . p a r a m s ;  
                         r e t u r n   i n s t r _ c o m p o s e ( i n s t r _ o p ,   b u i l t i n _ m e t h o d s [ i ] . o p ) ;  
                 }  
                 i + + ;  
         }  
         * a c t u a l s   =   - 1 ;  
         r e t u r n   0 ;  
 }  
  
  
 b o o l   S e m : : i n i t ( M a c h   *   m ,   C o m p _ p t r   c )  
 {  
 	 m a c h   =   m ;  
 	 c o m p   =   c ;  
 	 i n s t r u c t i o n s   =   N U L L ;  
 	 i f _ s t a c k   =   S h o r t _ s t a c k : : m a k e ( 3 ,   m a c h ) ;  
 	 l o o p e r _ s t a c k   =   S h o r t _ s t a c k : : m a k e ( 2 ,   m a c h ) ;  
 	 a s s i g n _ s t a c k   =   S h o r t _ s t a c k : : m a k e ( 2 ,   m a c h ) ;  
 	 i n d e n t _ s t a c k   =   S h o r t _ s t a c k : : m a k e ( 8 ,   m a c h ) ;  
 	 a r r a y _ s t a c k   =   S h o r t _ s t a c k : : m a k e ( 2 ,   m a c h ) ;  
 	 c a l l _ s t a c k   =   S h o r t _ s t a c k : : m a k e ( 2 ,   m a c h ) ;  
         r e t u r n   i f _ s t a c k   & &   l o o p e r _ s t a c k   & &   a s s i g n _ s t a c k   & &    
                 i n d e n t _ s t a c k   & &   a r r a y _ s t a c k   & &   c a l l _ s t a c k ;  
         / /   B U G :   n e e d   e r r o r   r e p o r t   h e r e   i f   r e t u r n i n g   f a l s e  
 }  
  
  
 S e m : : S e m ( )  
 {  
 }  
  
  
 b o o l   S e m : : r e s e t ( )  
 {  
         i f   ( i n s t r u c t i o n s )   {  
                 / / F L S y s : : f r e e ( i n s t r u c t i o n s ,   m a x _ i n s t r ) ;  
         }  
 	 c l a s s _ s t a r t e d   =   f a l s e ;  
 	 m e t h o d _ s t a r t e d   =   f a l s e ;  
 	 l o c a l _ o f f s e t   =   0 ;  
 	 m e m b e r _ o f f s e t   =   0 ;  
         n e x t _ i n s t r   =   0 ;  
         m a x _ i n s t r   =   0 ;  
 	 m e t h o d   =   N U L L ;  
 	 f c l a s s   =   N U L L ;  
 	 m e t h o d _ n a m e   =   N U L L ;  
         c l a s s _ n a m e   =   N U L L ;  
         v a r _ n a m e   =   N U L L ;  
 	 a r r a y _ i n d e x   =   0 ;  
 	 o p c o d e   =   0 ;  
         a c t u a l s   =   0 ;  
 	 / /   i n i t i a l l y   h a s   r o o m   f o r   1 6   s y m b o l s  
 	 s y m b o l s   =   A r r a y : : m a k e ( 0 ,   1 6 ,   m a c h ) ;  
         r e t u r n   s y m b o l s   ! =   N U L L ;  
 }  
  
  
 b o o l   S e m : : e m i t ( s h o r t   i n s t r u c t i o n )  
 {  
         i f   ( n e x t _ i n s t r   > =   m a x _ i n s t r )   {  
                 i f   ( ! g r o w ( ) )   r e t u r n   f a l s e ;  
         }  
         i f   ( n e x t _ i n s t r   <   m a x _ i n s t r )   {  
                 i n s t r u c t i o n s - > s e t _ i n s t r ( n e x t _ i n s t r + + ,   i n s t r u c t i o n ,    
                                                                 m a c h - > t r a c e _ f l a g ) ;  
         }  
         r e t u r n   t r u e ;  
 }  
  
  
 b o o l   S e m : : e m i t _ a t ( l o n g   l o c a t i o n ,   l o n g   i n s t r u c t i o n )  
 {  
         a s s e r t ( l o c a t i o n   <   n e x t _ i n s t r ) ;  
 	 i f   ( i n s t r u c t i o n   >   0 x 7 F F F   | |   i n s t r u c t i o n   <   - 0 x 1 0 0 0 0 )   {  
 	 	 c o m p - > r e p o r t _ e r r o r ( " v i r t u a l   m a c h i n e   l i m i t a t i o n :   b r a n c h   o u t   o f   b o u n d s " ) ;  
 	 	 r e t u r n   f a l s e ;  
 	 }  
         i n s t r u c t i o n s - > s e t _ i n s t r ( l o c a t i o n ,   ( s h o r t )   i n s t r u c t i o n ,    
                                                         m a c h - > t r a c e _ f l a g ) ;  
 	 r e t u r n   t r u e ;  
 }  
  
  
 b o o l   S e m : : f o r _ v a r ( c h a r   * i d )  
 {  
 	 l o n g   i n d e x ;     / /   v a r i a b l e   i n d e x   i n   f r a m e  
 	 / /   i s   t h i s   a   l o c a l ?   l o o k   i n   m e t h o d   s y m b o l   t a b l e  
 	 S y m b o l   *   s   =   S y m b o l : : m a k e ( i d ,   m a c h ) ;  
         i f   ( ! m e t h o d - > g e t _ l o c a l t a b l e ( ) - > l o o k u p ( s ,   & i n d e x ) )   {  
 	 	 c o m p - > r e p o r t _ e r r o r ( " u n d e c l a r e d   l o o p   v a r i a b l e " ) ;  
 	 	 r e t u r n   f a l s e ;  
 	 }  
 	 / /   n o w   i n d e x   i s   t h e   l o o p   v a r i a b l e   o f f s e t  
 	 l o o p e r _ s t a c k - > p u s h ( ( s h o r t )   i n d e x ,   m a c h ) ;  
 	 r e t u r n   t r u e ;  
 }  
  
  
 b o o l   S e m : : f o r _ i n i t ( )  
 {  
 	 s h o r t   i n d e x   =   l o o p e r _ s t a c k - > p o p ( m a c h ) ;  
 	 / /   s t o r e   t h e   i n i t i a l   v a l u e  
 	 m u s t ( e m i t ( i n s t r _ c o m p o s e ( i n s t r _ s t o r e _ l o c a l ,   ( s h o r t )   i n d e x ) ) ) ;  
 	 l o o p e r _ s t a c k - > p u s h ( i n d e x ,   m a c h ) ;     / /   s a v e   f o r   l a t e r  
 	 r e t u r n   t r u e ;  
 }  
  
  
 b o o l   S e m : : f o r _ t o ( )  
 {  
 	 r e t u r n   t r u e ;  
 }  
  
  
 b o o l   S e m : : f o r _ b y ( b o o l   b y _ f l a g )  
 {  
 	 i f   ( ! b y _ f l a g )   {   / /   n o   B Y   e x p r e s s i o n  
 	 	 e m i t ( i n s t r _ c o m p o s e ( i n s t r _ l o a d _ i n t ,   1 ) ) ;  
 	 }  
 	 / /   g e n e r a t e   i n s t r u c t i o n   t o   p u s h   t h e   l o o p c o u n t e r  
 	 s h o r t   i n d e x   =   l o o p e r _ s t a c k - > p o p ( m a c h ) ;  
 	 l o o p e r _ s t a c k - > p u s h ( i n d e x ,   m a c h ) ;  
 	 e m i t ( i n s t r _ c o m p o s e ( i n s t r _ l o a d _ l o c a l ,   ( s h o r t )   i n d e x ) ) ;  
 	 e m i t ( O P C O D E _ J U M P ) ;  
 	 l o o p e r _ s t a c k - > p u s h ( n e x t _ i n s t r ,   m a c h ) ;  
 	 e m i t ( 0 ) ;  
 	 / /   m a c h i n e   s t a c k   i s   t o _ v a l u e ,   b y _ v a l u e ,   l o o p c o u n t   ( t o p )  
 	 r e t u r n   t r u e ;  
 }  
  
  
 / /   f o r _ e n d _ r a n g e   - -   c a l l e d   a f t e r   f o r - = - t o - b y - :  
 / /  
 b o o l   S e m : : f o r _ e n d _ r a n g e ( )  
 {  
 	 l o n g   l o o p t o p   =   l o o p e r _ s t a c k - > p o p ( m a c h ) ;  
 	 l o n g   l o o p v a r   =   l o o p e r _ s t a c k - > p o p ( m a c h ) ;  
 	 r e t u r n   e m i t ( O P C O D E _ L O O P I N C )   & &  
 	               e m i t ( ( s h o r t )   l o o p v a r )   & &  
 	 	       / /   j u m p   i n s t r u c t i o n   i s   p c   + =   * p c ,  
 	 	       / /         n e x t _ i n s t r   =   l o o p t o p   +   * l o o p t o p ,  
 	 	       / /         * l o o p t o p   =   n e x t _ i n s t r   -   l o o p t o p  
 	 	       e m i t _ a t ( l o o p t o p ,   n e x t _ i n s t r   -   l o o p t o p )   & &  
 	 	       e m i t ( O P C O D E _ L O O P T S T )   & &  
 	 	       / /   j u m p   i n s t r u c t i o n   i s   p c   + =   * p c  
 	 	       / /         l o o p t o p   +   1   =   n e x t _ i n s t r   +   * n e x t _ i n s t r  
 	 	       / /         * n e x t _ i n s t r   =   l o o p t o p   +   1   -   n e x t _ i n s t r  
 	 	       e m i t ( l o o p t o p   +   1   -   n e x t _ i n s t r )   & &  
 	               / /   b r e a k   i n s t r u c t i o n s   s h o u l d   b r a n c h   t o   h e r e  
 	 	       e m i t ( O P C O D E _ P O P 2 ) ;  
 }  
  
  
 b o o l   S e m : : f o r _ a r r a y ( )  
 {  
 	 s h o r t   i n d e x   =   l o o p e r _ s t a c k - > p o p ( m a c h ) ;  
 	 m u s t ( e m i t ( i n s t r _ c o m p o s e ( i n s t r _ l o a d _ i n t ,   0 ) ) ) ;  
 	 m u s t ( e m i t ( O P C O D E _ J U M P ) ) ;  
 	 l o o p e r _ s t a c k - > p u s h ( n e x t _ i n s t r ,   m a c h ) ;  
 	 r e t u r n   e m i t ( 0 )   & &  
 	 	       / /   s t o r e   t h e   i n i t i a l   v a l u e  
 	 	       e m i t ( i n s t r _ c o m p o s e ( i n s t r _ s t o r e _ l o c a l ,   i n d e x ) ) ;  
 }  
  
  
 b o o l   S e m : : f o r _ e n d _ e l e m e n t s ( )  
 {  
 	 / /   s t a c k   h a s   l o o p t o p - 1  
 	 / /   m a c h i n e   s t a c k   h a s   a r r a y   i n d e x ,   t h e n   a r r a y  
 	 l o n g   l o o p t o p   =   l o o p e r _ s t a c k - > p o p ( m a c h ) ;  
 	 r e t u r n   e m i t _ a t ( l o o p t o p ,   n e x t _ i n s t r   -   l o o p t o p )   & &  
 	 	       e m i t ( O P C O D E _ L O O P N X T )   & &  
 	 	       e m i t ( l o o p t o p   -   n e x t _ i n s t r ) ;  
 }  
  
  
 b o o l   S e m : : r e t u r n _ n u l l ( )  
 {  
         e m i t ( O P C O D E _ R E T N U L L ) ;  
         r e t u r n   t r u e ;  
 }  
  
  
 / /   u n e m i t   - -   u n d o   t h e   p r e v i o u s   e m i t ,   a n d   r e t u r n   o p c o d e  
 / /  
 s h o r t   S e m : : u n e m i t ( )  
 {  
         i f   ( n e x t _ i n s t r   < =   0 )   r e t u r n   O P C O D E _ N O O P ;  
         n e x t _ i n s t r - - ;  
         r e t u r n   i n s t r u c t i o n s - > g e t _ i n s t r ( n e x t _ i n s t r ) ;  
 }  
  
          
 b o o l   S e m : : g r o w ( )  
 {  
         s h o r t   n e w l e n   =   1 2 8 ;  
         i f   ( n e w l e n   < =   m a x _ i n s t r )   n e w l e n   =   m a x _ i n s t r   *   2 ;  
         a s s e r t ( m a x _ i n s t r   <   n e w l e n ) ;  
         C o d e _ p t r   n e w i n s t r   =   C o d e : : m a k e ( n e w l e n ,   m a c h ) ;  
         i f   ( ! n e w i n s t r )   r e t u r n   f a l s e ;  
 	 i f   ( n e x t _ i n s t r   >   0 )   {  
                 f o r   ( l o n g   i   =   0 ;   i   <   n e x t _ i n s t r ;   i + + )   {  
                         n e w i n s t r - > s e t _ i n s t r ( i ,   i n s t r u c t i o n s - > g e t _ i n s t r ( i ) ,   f a l s e ) ;  
 	 	 }  
 	 }  
         i n s t r u c t i o n s   =   n e w i n s t r ;  
         m a x _ i n s t r   =   n e w l e n ;  
         r e t u r n   t r u e ;  
 }  
  
  
 / /   c a l l   p r e p a r e s   t o   i n v o k e   a   f u n c t i o n .  
 / /   T h e   c u r r e n t   o p c o d e , a c t u a l s   p a i r   i s   p u s h e d  
 / /   T h e   n e w   o p c o d e   i s   l o o k e d   u p   a n d   s a v e d   u n t i l  
 / /   a f t e r   p a r a m e t e r s   a r e   r e a d y  
 / /  
 b o o l   S e m : : c a l l ( c h a r   * i d )  
 {  
 	 c a l l _ s t a c k - > p u s h ( o p c o d e ,   m a c h ) ;  
 	 c a l l _ s t a c k - > p u s h ( a c t u a l s ,   m a c h ) ;  
 	 o p c o d e   =   b u i l t i n ( i d ,   & a c t u a l s ) ;  
 	 i f   ( o p c o d e   = =   0 )   {  
 	         l o n g   i n d e x   =   i n s e r t _ s y m b o l ( i d ) ;  
 	         a s s e r t ( i n d e x   > =   0   & &   i n d e x   <   2 0 4 8 ) ;  
 	         e m i t ( i n s t r _ c o m p o s e ( i n s t r _ l o c a l _ f r a m e ,   ( s h o r t )   i n d e x ) ) ;  
 	 }  
 	 r e t u r n   t r u e ;  
 }  
  
  
 b o o l   S e m : : m e t h o d _ c a l l ( c h a r   * i d )  
 {  
 	 c a l l _ s t a c k - > p u s h ( o p c o d e ,   m a c h ) ;  
 	 c a l l _ s t a c k - > p u s h ( a c t u a l s ,   m a c h ) ;  
         o p c o d e   =   b u i l t i n _ m e t h o d ( i d ,   & a c t u a l s ) ;  
         i f   ( o p c o d e   = =   0 )   {  
 	         l o n g   i n d e x   =   i n s e r t _ s y m b o l ( i d ) ;  
 	         a s s e r t ( i n d e x   > =   0   & &   i n d e x   <   2 0 4 8 ) ;  
 	         o p c o d e   =   i n s t r _ c o m p o s e ( i n s t r _ f r a m e ,   ( s h o r t )   i n d e x ) ;  
         }  
         r e t u r n   t r u e ;  
 }  
  
  
 b o o l   S e m : : c l a s s _ s t a r t ( c h a r   * c l a s s _ n a m e ,   c h a r   * s u p e r _ n a m e )  
 {  
 	 f c l a s s   =   F C l a s s : : m a k e ( m a c h ) ;  
 	 i f   ( ! f c l a s s )   r e t u r n   f a l s e ;  
 	 S y m b o l   *   s   =   S y m b o l : : m a k e ( c l a s s _ n a m e ,   m a c h ) ;  
 	 m a c h - > p u s h ( s ) ;  
 	 F C l a s s   *   p r o b e   =   m a c h - > c l a s s _ l o o k u p ( s ) ;  
 	 i f   ( p r o b e )   {  
 	 	 c o m p - > r e p o r t _ e r r o r ( " c l a s s   i s   a l r e a d y   d e f i n e d " ) ;  
 	 	 m a c h - > p o p ( ) ;  
 	 	 f c l a s s   =   N U L L ;  
 	 	 r e t u r n   f a l s e ;  
 	 }  
 	 m a c h - > c l a s s _ a d d ( s ,   f c l a s s ) ;  
 	 m a c h - > p o p ( ) ;  
 	 i f   ( s u p e r _ n a m e [ 0 ] )   {  
 	 	 s   =   S y m b o l : : m a k e ( s u p e r _ n a m e ,   m a c h ) ;  
 	 	 F C l a s s   *   s u p e r   =   m a c h - > c l a s s _ l o o k u p ( s ) ;  
 	 	 i f   ( ! s u p e r )   {  
 	 	 	 c o m p - > r e p o r t _ e r r o r ( " s u p e r   c l a s s   i s   u n d e f i n e d " ) ;  
 	 	 	 f c l a s s   =   N U L L ;  
 	 	 	 r e t u r n   f a l s e ;  
 	 	 }  
 	 	 f c l a s s - > i n i t _ s u p e r ( s u p e r ) ;  
 	 	 m e m b e r _ o f f s e t   =   s u p e r - > g e t _ i n s t _ s l o t s ( ) ;  
 	 }   e l s e   {  
 	 	 m e m b e r _ o f f s e t   =   1 ;   / /   a l l   o b j e c t s   h a v e   c l a s s   p o i n t e r  
 	 }  
 	 c l a s s _ s t a r t e d   =   t r u e ;  
 	 r e t u r n   t r u e ;  
 }  
  
  
 b o o l   S e m : : m e t h o d _ s t a r t ( )  
 {  
         m e t h o d _ s t a r t e d   =   t r u e ;  
         l o c a l _ o f f s e t   =   0 ;  
         r e t u r n   t r u e ;  
 }  
  
  
 b o o l   S e m : : m e t h o d _ e n d ( )  
 {  
 	 e m i t ( i n s t r _ c o m p o s e ( i n s t r _ o p ,   O P C O D E _ R E T N U L L ) ) ;  
 	 / /   c o p y   t h e   c o d e   v e c t o r   t o   t h e   m e t h o d  
         C o d e _ p t r   n e w i n s t r   =   C o d e : : m a k e ( n e x t _ i n s t r ,   m a c h ) ;  
         i f   ( ! n e w i n s t r )   r e t u r n   f a l s e ;  
         f o r   ( l o n g   i   =   0 ;   i   <   n e x t _ i n s t r ;   i + + )   {  
                 n e w i n s t r - > s e t _ i n s t r ( i ,   i n s t r u c t i o n s - > g e t _ i n s t r ( i ) ,   f a l s e ) ;  
 	 }  
         i n t   l e n   =   1 ;  
         i f   ( m a c h - > t r a c e _ f l a g )   {  
                 f o r   ( i   =   0 ;   i   <   n e x t _ i n s t r ;   i   + =   l e n )   {  
                         c h a r   t e x t [ 6 4 ] ;  
                         t r a c e ( n e w i n s t r - > d i s a s s e m b l e ( i ,   n e w i n s t r - > g e t _ i n s t r ( i ) ,    
                                                                                 n e w i n s t r - > g e t _ i n s t r ( i   +   1 ) ,   t e x t ,    
                                                                                 & l e n ,   m e t h o d ) ) ;  
                 }  
         }  
 	 m e t h o d - > s e t _ c o d e ( n e w i n s t r ,   m a c h ) ;  
 	 m e t h o d   =   N U L L ;  
 	 m e t h o d _ s t a r t e d   =   f a l s e ;  
 	 n e x t _ i n s t r   =   0 ;  
 	 r e t u r n   t r u e ;  
 }  
  
  
 b o o l   S e m : : m e t h o d _ n a m e _ i s ( c h a r   * n a m e )  
 {  
 	 m e t h o d _ n a m e   =   S y m b o l : : m a k e ( n a m e ,   m a c h ) ;  
         m e t h o d   =   M e t h o d : : m a k e ( m e t h o d _ n a m e ,   m a c h ) ;  
         i f   ( c l a s s _ s t a r t e d )   {   / /   i n s e r t   m e t h o d   i n   t h e   c l a s s  
 	 	 f c l a s s - > e n t e r _ m e t h o d ( m e t h o d _ n a m e ,   m e t h o d ,   m a c h ) ;  
 	 	 m e t h o d - > s e t _ f c l a s s ( f c l a s s ,   m a c h ) ;  
 	 }   e l s e   {   / /   a t t a c h   m e t h o d   t o   s y m b o l  
                 m e t h o d _ n a m e - > s e t _ f u n c t i o n ( m e t h o d ,   m a c h ) ;  
                 m e t h o d - > s e t _ f c l a s s ( N U L L ,   m a c h ) ;  
         }  
         / /   a d d   s y m b o l s   t o   m e t h o d :  
       	 m e t h o d - > i n i t _ s y m b o l s ( s y m b o l s ,   m a c h ) ;  
 	 i f   ( m a c h - > t r a c e _ f l a g )  
                 t r a c e ( " m e t h o d _ n a m e _ i s :   s y m b o l   n a m e   i s   % s \ n " ,    
 	 	             m e t h o d _ n a m e - > g e t _ n a m e ( ) - > g e t _ s t r i n g ( ) ) ;  
         r e t u r n   t r u e ;  
 }  
  
  
 b o o l   S e m : : b e g i n _ f o r m a l s ( )  
 {  
         f o r m a l _ t y p e   =   F O R M A L _ R E Q U I R E D ;  
         r e t u r n   t r u e ;  
 }  
  
  
 b o o l   S e m : : s e t _ f o r m a l _ t y p e ( s h o r t   f t )  
 {  
         i f   ( f t   <   f o r m a l _ t y p e )   {  
         	 c o m p - > r e p o r t _ e r r o r ( " f o r m a l   t y p e   o u t   o f   o r d e r " ) ;  
                 r e t u r n   f a l s e ;  
         }  
         f o r m a l _ t y p e   =   f t ;  
         r e t u r n   t r u e ;  
 }  
  
  
 b o o l   S e m : : f o r m a l _ i s ( c h a r   * n a m e )  
 {  
 	 / /   c o n v e r t   t h e   n a m e   t o   a   s y m b o l   i n   t h i s   c l a s s  
 	 v a r _ n a m e   =   S y m b o l : : m a k e ( n a m e ,   m a c h ) ;  
         / /   p o s i t i o n   t h e   s t a c k   a b o v e   t h e   p a r a m e t e r :  
 	 m e t h o d - > s e t _ s t a c k _ o f f s e t ( 1   +   m e t h o d - > g e t _ s t a c k _ o f f s e t ( ) ) ;  
         s w i t c h   ( f o r m a l _ t y p e )   {  
             c a s e   F O R M A L _ O P T I O N A L :  
                 m e t h o d - > s e t _ o p t i o n a l s ( 1   +   m e t h o d - > g e t _ o p t i o n a l s ( ) ) ;  
                 / /   n o   b r e a k ,   f a l l   t h r o u g h   t o   i n c r e m e n t   p a r a m e t e r s   t o o !  
             c a s e   F O R M A L _ R E Q U I R E D :  
                 m e t h o d - > s e t _ p a r a m e t e r s ( 1   +   m e t h o d - > g e t _ p a r a m e t e r s ( ) ) ;  
                 b r e a k ;  
             c a s e   F O R M A L _ K E Y W O R D :  
                 m e t h o d - > s e t _ k e y w o r d s ( 1   +   m e t h o d - > g e t _ k e y w o r d s ( ) ) ;  
                 b r e a k ;  
             c a s e   F O R M A L _ R E S T :  
                 m e t h o d - > s e t _ r e s t _ f l a g ( t r u e ) ;  
                 b r e a k ;  
             c a s e   F O R M A L _ D I C T I O N A R Y :  
                 m e t h o d - > s e t _ d i c t _ f l a g ( t r u e ) ;  
                 b r e a k ;  
         }  
                  
         r e t u r n   m e t h o d - > g e t _ l o c a l t a b l e ( ) - > i n s e r t _ v a r ( v a r _ n a m e ,   l o c a l _ o f f s e t + + ,   m a c h ) ;  
 }  
  
  
 b o o l   S e m : : d e f a u l t _ v a l u e ( F V a l   v )  
 {  
         / /   f i r s t   s e e   i f   t h e r e   i s   a n   o p t i o n a l s   a r r a y :  
         A r r a y   *   d e f a u l t s   =   m e t h o d - > g e t _ d e f a u l t ( ) ;  
         i f   ( ! d e f a u l t s )   {  
                 d e f a u l t s   =   A r r a y : : m a k e ( 1 ,   1 ,   m a c h ) ;  
                 m e t h o d - > s e t _ d e f a u l t ( d e f a u l t s ) ;  
         }  
         / /   t h i s   n e w   v a l u e   i s   f o r   l o c a l _ o f f s e t - 1 ,   b u t   t h e   d e f a u l t s   s t a r t  
         / /   a t   p a r a m e t e r s   -   o p t i o n a l s  
         l o n g   i n d e x   =   l o c a l _ o f f s e t   -   1   -    
                 ( m e t h o d - > g e t _ p a r a m e t e r s ( )   -   m e t h o d - > g e t _ o p t i o n a l s ( ) ) ;  
         / /   m a k e   s u r e   a r r a y   i s   l o n g   e n o u g h :  
         w h i l e   ( d e f a u l t s - > g e t _ a r r a y _ l e n ( )   < =   i n d e x )   {  
                 d e f a u l t s - > a p p e n d ( N U L L ,   m a c h ) ;  
         }  
         d e f a u l t s - > s e t _ f a s t r e f ( i n d e x ,   v ,   m a c h ) ;  
         r e t u r n   t r u e ;  
 }  
  
  
 b o o l   S e m : : e n d _ o f _ f o r m a l s ( )  
 {  
         / /   s i g n a t u r e   i s   n u m b e r   o f   f o r m a l s  
         / /   s t a c k _ o f f s e t   i s   n u m b e r   o f   f o r m a l s   +   l o c a l s  
 	 / /   f r a m e _ s l o t s   i s   s t a c k _ o f f s e t   +   m a x i m u m   s t a c k   s i z e  
 	 m e t h o d - > s e t _ f r a m e _ s l o t s ( m e t h o d - > g e t _ s t a c k _ o f f s e t ( )   +    
 	 	 	 	 	 	 	 E X P R _ S T A C K _ M A X ) ;  
         r e t u r n   t r u e ;  
 }  
  
  
 b o o l   S e m : : i d ( c h a r   * i d )  
 {  
 	 S y m b o l   *   s   =   S y m b o l : : m a k e ( i d ,   m a c h ) ;  
 	 l o n g   i n d e x ;   / /   v a r i a b l e   i n d e x   i n   f r a m e  
 	 M e t h o d   *   m p ;  
 	 m a c h - > p u s h ( s ) ;  
 	 / /   i s   t h i s   a   l o c a l ?   l o o k   i n   m e t h o d   s y m b o l   t a b l e  
         i f   ( m e t h o d - > g e t _ l o c a l t a b l e ( ) - > l o o k u p ( s ,   & i n d e x ) )   {  
 	 	 m u s t ( e m i t ( i n s t r _ c o m p o s e ( i n s t r _ l o a d _ l o c a l ,   ( s h o r t )   i n d e x ) ) ) ;  
 	 }   e l s e   i f   ( f c l a s s   & &  
                               f c l a s s - > g e t _ s y m b o l t a b l e ( ) - > l o o k u p ( s ,   & m p ,   & i n d e x )   & & 