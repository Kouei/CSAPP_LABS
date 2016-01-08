#line 141 "./bits.c"
 int bitAnd(int x, int y) {
  return ~(~x | ~y);
#line 1 "<command-line>"
#include "/usr/include/stdc-predef.h"
#line 143 "./bits.c"
 }
#line 154
int getByte(int x, int n) {
 return (x >>( n << 3)) & 0xFF;
}
#line 165
int logicalShift(int x, int n) {
 return ~(((1 << 31) >> n) << 1) &( x >> n);
}
#line 175
int bitCount(int x) {
 int n;
 int mask1;int mask2;int mask3;int mask4;int mask5;
 n = 0x55 +( 0x55 << 8); mask1 =( n << 16) + n;
 n = 0x33 +( 0x33 << 8); mask2 =( n << 16) + n;
 n = 0x0F +( 0x0F << 8); mask3 =( n << 16) + n;
 mask4 = 0xFF +( 0xFF << 16);
 mask5 = 0xFF +( 0xFF << 8);

 x =( x & mask1) +(( x >> 1) & mask1);
 x =( x & mask2) +(( x >> 2) & mask2);
 x =( x & mask3) +(( x >> 4) & mask3);
 x =( x & mask4) +(( x >> 8) & mask4);
 x =( x & mask5) +(( x >> 16) & mask5);

 return x;
}
#line 199
int bang(int x) {
 x =( x >> 16) | x;
 x =( x >> 8) | x;
 x =( x >> 4) | x;
 x =( x >> 2) | x;
 x =( x >> 1) | x;
 return ~x & 1;
}
#line 213
int tmin(void) {
 return 1 << 31;
}
#line 226
int fitsBits(int x, int n) {
 int higher_mask=((  ~0) << n) >> 1;
 int higher_bits=  higher_mask & x;
 int no_zero=  !(higher_bits ^ higher_mask);
 return (n >> 5) | no_zero | !(higher_mask & x);
}
#line 241
int divpwr2(int x, int n) {
 int bias=(  x >> 31) & ~((~0) << n);
 return (x + bias) >> n;
}
#line 252
int negate(int x) {
 return ~x + 1;
}
#line 262
int isPositive(int x) {
 return !!x & !((x >> 31) & 1);
}
#line 272
int isLessOrEqual(int x, int y) {
 int sign1=(  x >> 31) & 1;
 int sign2=(  y >> 31) & 1;
 int num_diff=  x + ~y + 1;
 int num_diff_sign=(  num_diff >> 31) & 1;
 return (!num_diff) |( sign1 & !sign2) |(( !(sign1 ^ sign2)) & num_diff_sign);
}
#line 286
int ilog2(int x) {

 int n;
 int mask1;int mask2;int mask3;int mask4;int mask5;

 x = x |( x >> 1);
 x = x |( x >> 2);
 x = x |( x >> 4);
 x = x |( x >> 8);
 x = x |( x >> 16);

 n = 0x55 +( 0x55 << 8); mask1 =( n << 16) + n;
 n = 0x33 +( 0x33 << 8); mask2 =( n << 16) + n;
 n = 0x0F +( 0x0F << 8); mask3 =( n << 16) + n;
 mask4 = 0xFF +( 0xFF << 16);
 mask5 = 0xFF +( 0xFF << 8);

 x =( x & mask1) +(( x >> 1) & mask1);
 x =( x & mask2) +(( x >> 2) & mask2);
 x =( x & mask3) +(( x >> 4) & mask3);
 x =( x & mask4) +(( x >> 8) & mask4);
 x =( x & mask5) +(( x >> 16) & mask5);

 return x + ~1 + 1;
}
#line 322
unsigned float_neg(unsigned uf) {
 int mask=  0x80000000;
 int mask1=  0x7F800000;
 if ((uf<< 9) &&( uf & mask1) == mask1) return uf;
 return mask ^ uf;
}
#line 337
unsigned float_i2f(int x) {
 int mask=  0x80000000;
 int mask2=  0x007FFFFF;
 int s=  mask & x;
 int e;
 int f;
 int count=  32;
 int rear;

 if (!x) return 0;
 if (x== mask) return 0xCF000000;
 if (s) x= ~x + 1;
 while (!(x& mask)) 
 {
  x <<= 1;
  --count;
 }
 e =( count - 1 + 127) << 23;
 x <<= 1;
 rear = x & 0x1FF;
 f =(( x >> 9) & mask2);
 if (rear> 0x100) f += 1;
 else if (rear== 0x100 &&( f & 1)) f += 1;
 return s + e + f;
}
#line 373
unsigned float_twice(unsigned uf) {
 int mask=  0x80000000;
 int mask1=  0x7F800000;
 int mask2=  0x007FFFFF;
 int s=  uf & mask;
 int e=  uf & mask1;
 int f=  uf & mask2;

 if (!e&& !f) return uf;
 if (!e) return s+( f << 1);
 else if (e== mask1) return uf;
 else return uf + 0x00800000;
}
