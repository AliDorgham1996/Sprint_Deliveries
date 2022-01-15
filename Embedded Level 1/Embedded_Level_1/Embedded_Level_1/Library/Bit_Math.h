#ifndef BIT_MATH_H
#define BIT_MATH_H


#include <stdint.h>     


#define MAX_A_B(A ,B)								(((A) > (B)) ? (A) : (B))
#define Swap_X_Y_Type(x,y,Type_t)					do{ Type_t temp=(*x); (*x)=(*y); (*y)=temp; }while(0)


//Deal with only one Bit
#define SetBit(REG,BIT)								((REG) |=  (1UL<<(BIT)))
#define ClearBit(REG,BIT)							((REG) &= ~(1UL<<(BIT)))
#define ToggleBit(REG,BIT)							((REG) ^=  (1UL<<(BIT)))
#define GetBit(REG,BIT)								(((REG)>>(BIT))&(1UL))

//Deal with mask of Bits
#define SetMaskBits(REG,MB)							((REG) |=  (MB))
#define ClearMaskBits(REG,MB)						((REG) &= ~(MB))
#define ToggleMaskBits(REG,MB)						((REG) ^=  (MB))
#define GetMaskBits(REG,MB)						    ((REG) & (MB))


#define SetReg_8_Bits(u8_REG)						((u8_REG)  =  (uint8_t)(0xFF))
#define ClearReg_8_Bits(u8_REG)						((u8_REG)  =  (uint8_t)(0x00))
#define ToggleReg_8_Bits(u8_REG)					((u8_REG) ^=  (uint8_t)(0xFF))
#define SwapNibblesOf_8Bits(u8_REG)					((uint8_t )							 \
													(((( uint8_t) u8_REG  & 0x0F  ) << 4)\
													|((( uint8_t)u8_REG  & 0xF0  ) >> 4))\
													)


#define SetReg_16_Bits(u16_REG)						((u16_REG)  =  (uint16_t)(0xFFFF))
#define ClearReg_16_Bits(u16_REG)					((u16_REG)  =  (uint16_t)(0x0000))
#define ToggleReg_16_Bits(u16_REG)					((u16_REG) ^=  (uint16_t)(0xFFFF))
#define SwapByteOf_16Bits(u16_REG)					((uint16_t)							 \
													((((uint16_t) u16_REG & 0x00FF) << 8)\
													|(((uint16_t)u16_REG & 0xFF00) >> 8))\
													)


#define SetReg_32_Bits(u32_REG)						((u32_REG)  =  (uint32_t)(0xFFFFFFFF))
#define ClearReg_32_Bits(u32_REG)					((u32_REG)  =  (uint32_t)(0x00000000))
#define ToggleReg_32_Bits(u32_REG)					((u32_REG) ^=  (uint32_t)(0xFFFFFFFF))
#define Swap2BytesOf_32Bits(u32_REG)				((uint32_t)                               \
													((((uint32_t)u32_REG & 0xFF000000) >>  24)\
													|(((uint32_t)u32_REG & 0x00FF0000) >>   8)\
													|(((uint32_t)u32_REG & 0x0000FF00) <<   8)\
													|(((uint32_t)u32_REG & 0x000000FF) << 24))\
													)


#endif /* BIT_MATH_H */