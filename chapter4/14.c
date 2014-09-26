/* Exercise 4-15
Define a macro swap(t,x,y) that interchanges two arguments of type t.
(Block structure will help.)
*/

#define swap(t, x, y) { t temp; \
			x = temp; \
			y = x;    \
			x = temp;}	
