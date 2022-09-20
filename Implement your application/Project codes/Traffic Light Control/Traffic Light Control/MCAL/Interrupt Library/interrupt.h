/*
 * interrupt.h
 *
 * Created: 9/12/2022 12:14:58 PM
 *  Author: dinoa
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_




// External Interrupt Vectors
// External Interrupt Requests 0
#define EXT_INT_0 __vector_1
// External Interrupt Requests 1
#define EXT_INT_1 __vector_2
// External Interrupt Requests 2
#define EXT_INT_2 __vector_3

// set global interrupts
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

//clear global interrupts
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

//ISR definition
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

#endif /* INTERRUPT_H_ */