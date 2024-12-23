d d d d  
 b b b a b  
 / *   c a l l . c p p   - -   i m p l e m e n t s   m e t h o d   c a l l s   a n d   r e t u r n s ,   j u m p s ,   e t c .   * /  
  
  
 # i n c l u d e   " m e m o r y . h "  
 # i n c l u d e   " f l i n c l . h "  
 # i n c l u d e   " a s s e r t . h "  
  
  
 v o i d   M a c h : : o p e r _ f r a m e ( S y m b o l   *   s y m )  
 {  
 	 i f   ( t r a c e _ f l a g )   {  
                 t r a c e ( " i n s t r _ f r a m e : \ n " ) ;  
 	         f r a m e - > t r a c e ( ) ;  
         }  
 	 M e t h o d   *   m e t h o d   =   f r a m e - > g e t _ m e t h o d ( ) ;  
         F C l a s s   *   f c l a s s   =   m e t h o d - > g e t _ f c l a s s ( ) ;  
         S y m b o l   *   s e l e c t o r   =   s y m ;  
 	 l o n g   v a r _ i n d e x ;  
         / /     n o w   l o o k   u p   t h e   m e t h o d :  
         O b j e c t   *   o b j   =   r e a d _ t o s ( ) . o b j e c t ;  
         i f   ( ! o b j )   {   / /   s e l f   = =   N U L L ,   m a k i n g   a   c a l l   f r o m   a   g l o b a l   f u n c t i o n  
                 m e t h o d   =   s e l e c t o r - > g e t _ f u n c t i o n ( ) ;  
         }   e l s e   {  
                 o b j - > t y p e _ c h e c k ( t h i s ) ;  
                 i f   ( e r r o r _ f l a g )   r e t u r n ;  
                 i f   ( ! o b j - > g e t _ f c l a s s ( ) - > g e t _ s y m b o l t a b l e ( ) - > l o o k u p (  
 	 	 	 	                 s e l e c t o r ,   & m e t h o d ,   & v a r _ i n d e x )   | |  
 	 	 	 ! m e t h o d )   {  
 	 	 	 m e t h o d   =   s e l e c t o r - > g e t _ f u n c t i o n ( ) ;  
                         i f   ( m e t h o d )   o b j   =   N U L L ;  
                 }  
         }  
 	 i f   ( ! m e t h o d )   {  
 	 	 u n d e f i n e d _ m e t h o d ( s e l e c t o r ) ;  
 	 	 r e t u r n ;  
 	 }  
         d o _ f r a m e ( o b j ,   m e t h o d ) ;  
 }  
  
  
 / /   d o _ f r a m e   - -   c r e a t e s   a   n e w   f r a m e  
 / /  
 / /   O n   e n t r y :  
 / /                       t o p   o f   s t a c k   i s   t o   b e   r e p l a c e d   b y   f r a m e  
 / /                       z e r o   ( a r g   i n d e x )   i s   p u s h e d  
 v o i d   M a c h : : d o _ f r a m e ( O b j e c t   *   o b j ,   M e t h o d   *   m e t h o d )  
 {  
         l o n g   f r a m e _ s l o t s ;  
         l o n g   n _ p a r m s ;  
         / /   m e t h o d   m a y   b e   b u i l t i n   o r   o r d i n a r y  
         i f   ( m e t h o d - > h a s _ t a g ( T A G _ M E T H O D ) )   {  
                 f r a m e _ s l o t s   =   m e t h o d - > g e t _ f r a m e _ s l o t s ( ) ;  
 	         n _ p a r m s   =   m e t h o d - > g e t _ p a r a m e t e r s ( )   +  
                                     m e t h o d - > g e t _ k e y w o r d s ( )   +   m e t h o d - > g e t _ r e s t _ f l a g ( )   +  
                                     m e t h o d - > g e t _ d i c t _ f l a g ( ) ;  
         }   e l s e   {  
                 B u i l t i n   *   b u i l t i n   =   ( B u i l t i n   * )   m e t h o d ;  
                 a s s e r t ( m e t h o d - > h a s _ t a g ( T A G _ B U I L T I N ) ) ;  
                 n _ p a r m s   =   b u i l t i n - > g e t _ p a r a m e t e r s ( ) ;  
                 f r a m e _ s l o t s   =   ( n _ p a r m s   ! =   0 x F F F F   ?   n _ p a r m s   :   1 ) ;  
         }  
         F r a m e   *   f r a m e   =   F r a m e : : m a k e ( F R A M E _ L O C A L _ B A S E   +   f r a m e _ s l o t s ,   t h i s ) ;  
  
         / /   s t o r e   o b j e c t ,   m e t h o d ,   a n d   c u r r e n t   f r a m e   i n   n e w   f r a m e :  
         f r a m e - > i n i t _ s e l f ( o b j ,   t h i s ) ;    
         f r a m e - > i n i t _ m e t h o d ( m e t h o d ,   t h i s ) ;    
         f r a m e - > i n i t _ p r e v i o u s ( f r a m e ,   t h i s ) ;  
         / /   r e p l a c e   t o s   w i t h   f r a m e ,   o v e r w r i t i n g   o b j e c t :  
         ( * ( t o s   -   1 ) ) . f r a m e   =   f r a m e ;  
 	 i f   ( n _ p a r m s   = =   0 x F F F F )   {   / /   t h i s   m e c h a n i s m   i s   f o r   b u i l t i n s   o n l y  
 	 	 f r a m e - > s e t _ l o c a l ( 0 ,   A r r a y : : m a k e ( 0 ,   3 ,   t h i s ) ,   t h i s ) ;  
 	 }  
 	 / /   t h i s   i s   t h e   a r g u m e n t   i n d e x :  
         p u s h ( F L o n g : : m a k e ( 0 ,   t h i s ) ) ;  
         i f   ( m e t h o d - > h a s _ t a g ( T A G _ M E T H O D ) )   {  
                 A r r a y   *   d e f a u l t s   =   m e t h o d - > g e t _ d e f a u l t ( ) ;  
                 l o n g   p a r a m e t e r s   =   m e t h o d - > g e t _ p a r a m e t e r s ( ) ;  
                 i f   ( d e f a u l t s )   {  
                         / /   c o p y   d e f a u l t   v a l u e s   i n t o   f r a m e :  
                         l o n g   b a s e   =   p a r a m e t e r s   -   m e t h o d - > g e t _ o p t i o n a l s ( ) ;  
                         p u s h ( d e f a u l t s ) ;  
                         o p e r _ p r i n t ( ) ;  
                         f o r   ( i n t   i   =   0 ;   i   <   d e f a u l t s - > g e t _ a r r a y _ l e n ( ) ;   i + + )   {  
                                 f r a m e - > s e t _ l o c a l ( b a s e   +   i ,   d e f a u l t s - > f a s t r e f ( i ) . n o d e ,   t h i s ) ;  
                         }  
                 }  
                 p a r a m e t e r s   + =   m e t h o d - > g e t _ k e y w o r d s ( ) ;  
                 i f   ( m e t h o d - > g e t _ r e s t _ f l a g ( ) )   {  
                         / /   c r e a t e   r e s t   a r r a y ?  
 	 	         f r a m e - > s e t _ l o c a l ( p a r a m e t e r s ,   A r r a y : : m a k e ( 0 ,   3 ,   t h i s ) ,   t h i s ) ;  
                 }  
                 i f   ( m e t h o d - > g e t _ d i c t _ f l a g ( ) )   {  
                         / /   c r e a t e   t h e   d i c t i o n a r y  
                         f r a m e - > s e t _ l o c a l ( p a r a m e t e r s   +   m e t h o d - > g e t _ r e s t _ f l a g ( ) ,  
                                                           D i c t : : m a k e ( t h i s ) ,   t h i s ) ;  
                 }  
         }  
 }  
  
  
 / *  
 v o i d   M a c h : : o p e r _ f r a m e ( )  
 {  
         i n t   i n d e x   =   * p c + + ;     / /   f e t c h   t h e   m e t h o d   i n d e x  
         O b j e c t   *   o b j   =   r e a d _ t o s ( ) . o b j e c t - > t y p e _ c h e c k ( t h i s ) ;  
         M e t h o d   *   m e t h o d   =   o b j - > g e t _ f c l a s s ( ) - > g e t _ m e t h o d s ( ) - > m e t h o d ( i n d e x ) ;  
         d o _ f r a m e ( o b j ,   m e t h o d ) ;  
 }  
 * /  
  
 / *  
 v o i d   M a c h : : o p e r _ g f r a m e ( )  
 {  
         p u s h ( g l o b a l s ) ;  
         o p e r _ f r a m e ( ) ;  
 }  
 * /  
  
 v o i d   M a c h : : o p e r _ p a r a m ( )  
 {  
         / *   o n   e n t r y ,   s t a c k   ( t o p   d o w n )   c o n t a i n s :  
           *     p a r a m e t e r ,   i n d e x ,   f r a m e  
           * /  
         F V a l   p a r a m   =   r e a d _ t o s ( ) . n o d e ;  
         i n t   i n d e x   =   ( i n t )   ( r e a d _ n e x t _ t o s ( ) . f l o n g - > i n t 6 4 _ d a t a ) ;  
         F r a m e   *   f r a m e   =   r e a d _ n e x t _ n e x t _ t o s ( ) . f r a m e ;  
         M e t h o d   *   m e t h o d   =   f r a m e - > g e t _ m e t h o d ( ) ;  
 	 l o n g   p a r a m e t e r s   =   m e t h o d - > g e t _ p a r a m e t e r s ( ) ;  
         i f   ( i n d e x   <   p a r a m e t e r s )   {  
                 / *   t h e   f i r s t   l o c a l   i s   t h e   f i r s t   a r g ,   e t c .   * /  
                 f r a m e - > s e t _ l o c a l ( i n d e x ,   p a r a m ,   t h i s ) ;  
 	 	 p o p ( ) ;   / /   p o p   t h e   p a r a m e t e r  
                 r e p l a c e ( F L o n g : : m a k e ( i n d e x   +   1 ,   t h i s ) ) ;  
         }   e l s e   i f   ( p a r a m e t e r s   = =   0 x F F F F )   {   / /   s p e c i a l   c a s e   f o r   b u i l t - i n  
 	 	 / /   a p p e n d   p a r a m   t o   a r r a y   i n   f r a m e   l o c a l   0  
 	 	 f r a m e - > l o c a l ( 0 ) . a r r a y - > a p p e n d ( p a r a m ,   t h i s ) ;  
 	         p o p ( ) ;   / /   p o p   t h e   p a r a m e t e r  
                 r e p l a c e ( F L o n g : : m a k e ( i n d e x   +   1 ,   t h i s ) ) ;  
 	 }   e l s e   i f   ( m e t h o d - > h a s _ t a g ( T A G _ B U I L T I N ) )   {  
                 t o o _ m a n y _ p a r a m e t e r s ( ) ;  
         }   e l s e   i f   ( m e t h o d - > g e t _ r e s t _ f l a g ( ) )   {  
                 f r a m e - > l o c a l ( p a r a m e t e r s   +   m e t h o d - > g e t _ k e y w o r d s ( ) ) . a r r a y - >  
                         a p p e n d ( p a r a m ,   t h i s ) ;  
                 p o p ( ) ;   / /   p o p   t h e   p a r a m e t e r  
 	 }   e l s e   t o o _ m a n y _ p a r a m e t e r s ( ) ;  
 }  
  
  
 v o i d   M a c h : : o p e r _ k e y p a r a m ( )  
 {  
         / *   o n   e n t r y ,   s t a c k   ( t o p   d o w n )   c o n t a i n s :  
           *   p a r a m e t e r ,   i n d e x ,   f r a m e ;   k e y w o r d   i s   n e x t   o p c o d e  
           * /  
         F V a l   p a r a m   =   r e a d _ t o s ( ) . n o d e ;  
         F r a m e   *   f r a m e   =   r e a d _ n e x t _ n e x t _ t o s ( ) . f r a m e ;  
         M e t h o d   *   m e t h o d   =   f r a m e - > g e t _ m e t h o d ( ) ;  
         S y m b o l   *   k e y   =   m e t h o d - > s y m b o l ( * p c + + ) ;  
         i f   ( t r a c e _ f l a g )   t r a c e ( " k e y p a r a m   i s   % s \ n " ,   k e y - > g e t _ n a m e ( ) - > g e t _ s t r i n g ( ) ) ;  
         i f   ( m e t h o d - > h a s _ t a g ( T A G _ B U I L T I N ) )   {  
                 i n v a l i d _ k e y w o r d _ p a r a m e t e r ( ) ;  
                 r e t u r n ;  
         }        
         / /   k e y w o r d   s h o u l d   b e   i n   l o c a l s   d i c t i o n a r y   a n d   s h o u l d   b e   b e t w e e n  
         / /   p a r a m e t e r s   a n d   p a r a m e t e r s   +   k e y w o r d s  
 	 l o n g   p a r a m e t e r s   =   m e t h o d - > g e t _ p a r a m e t e r s ( ) ;  
         l o n g   k e y w o r d s   =   m e t h o d - > g e t _ k e y w o r d s ( ) ;  
         l o n g   i n d e x ;  
         i f   ( ! m e t h o d - > g e t _ l o c a l t a b l e ( ) - > l o o k u p ( k e y ,   & i n d e x ) )   {  
                 i f   ( m e t h o d - > g e t _ d i c t _ f l a g ( ) )   {  
                         D i c t _ p t r   d i c t   =   f r a m e - > l o c a l ( p a r a m e t e r s   +   k e y w o r d s   +  
                                                                                   m e t h o d - > g e t _ r e s t _ f l a g ( ) ) . d i c t ;  
                         d i c t - > i n s e r t ( k e y ,   p a r a m ,   t h i s ) ;  
                         p o p ( ) ;  
                         r e p l a c e ( F L o n g : : m a k e ( i n d e x   +   1 ,   t h i s ) ) ;  
                         r e t u r n ;  
                 }  
         }   e l s e   i f   ( i n d e x   > =   p a r a m e t e r s   & &   i n d e x   <   p a r a m e t e r s   +   k e y w o r d s )   {  
                 f r a m e - > s e t _ l o c a l ( i n d e x ,   p a r a m ,   t h i s ) ;  
                 p o p ( ) ;  
                 r e t u r n ;  
         }  
         i n v a l i d _ k e y w o r d _ p a r a m e t e r ( ) ;  
 }  
  
  
 v o i d   M a c h : : o p e r _ c a l l ( )  
 {  
         F r a m e   *   n e x t f r a m e   =   r e a d _ n e x t _ t o s ( ) . f r a m e ;  
 	 / /   c h e c k   p a r a m e t e r   c o u n t  
 	 M e t h o d   *   m e t h o d   =   n e x t f r a m e - > g e t _ m e t h o d ( ) ;  
         / /   g e t _ s i g n a t u r e   w o r k s   f o r   b o t h   m e t h o d s   a n d   b u i l t i n s  
 	 l o n g   p a r a m e t e r s   =   m e t h o d - > g e t _ p a r a m e t e r s ( ) ;  
         l o n g   o p t i o n a l s   =   m e t h o d - > g e t _ o p t i o n a l s ( ) ;  
 	 i f   ( ( p a r a m e t e r s   ! =   0 x F F F F )   & &    
                 ( p a r a m e t e r s   -   o p t i o n a l s   >   ( i n t )   ( r e a d _ t o s ( ) . f l o n g - > i n t 6 4 _ d a t a ) ) )   {  
 	 	 p a r a m e t e r _ c o u n t _ m i s m a t c h ( ) ;  
 	 	 r e t u r n ;  
 	 }  
         p o p e r _ n ( 2 ) ;   / /   g e t   r i d   o f   t h e   a r g   c o u n t e r   a n d   n e x t f r a m e  
 	 / /   n o w   c o p y   t h e   s t a c k   i n t o   t h e   f r a m e  
 	 / /   t h e   d e s t i n a t i o n   i s   s t o r e d   i n   t h e   m e t h o d :  
 	 l o n g   o f f s e t   =   F R A M E _ L O C A L _ B A S E   +   m e t h o d - > g e t _ s t a c k _ o f f s e t ( ) ;  
 	 / /   t h e   s i z e   i s   s i m p l y   t o s   -   e x p r _ s t a c k  
 	 / /   t r a c e ( " c a l l   f r a m e - > s e t _ t o s ( % d ) \ n " ,   t o s   -   e x p r _ s t a c k ) ;  
 	 f r a m e - > s e t _ t o s ( t o s   -   e x p r _ s t a c k ) ;  
 	 F U n i o n   * p   =   e x p r _ s t a c k ;  
 	 w h i l e   ( p   <   t o s )   {  
 	 	 i f   ( t r a c e _ f l a g )   t r a c e ( " c a l l   s a v i n g   % x   a