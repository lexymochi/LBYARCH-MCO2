;	LBYARCH S17
;	Arcega, Bea Alexis; Bautista, Cyrus Rylie
;	Machine Project 2, accelerationASM.asm
;
;	A car's performance is usually measured using an acceleration test
;	with a 1km distance. some cars are measured from a cold start (they
;	start at 0km/h), some are tested from a hot start (the car is running
;	at a stable speed and then accelerates).
;	
;	Impement a program that computes from the acceleration of multiple cars
;	stored in a Y by 3 matrix, where Y is the number of cars. All inputs are
;	in single floating point.
;
;	The output acceleration for each will be converted into Integers.
;
; 	Each row will indicate Initial Velocity (in km/h), Final Velocity (in km/h),
;	and Time (in Seconds).

section .data
len dd 2
matrixptr dq 0
resptr dq 0

; debug
;matrix dd 3000.0, 15000.0, 4.0, 4000.0, 24000.0, 5.0
;res times 10000 dd 0.0

TO_MPH dd 0x3e8e38e4 ; constant: 1000/3600 ~ 2.77

section .text
bits 64
default rel
global accelMatrix

accelMatrix:
    ; move inputs to variables
    mov [len], ecx
    ;lea rdx, [matrix] ; debug
    mov [matrixptr], rdx
    ;lea r8, [res] ; debug
    mov [resptr], r8
    
    ; initialize bounds
    mov rcx, 0
    mov edx, [len]
    
    ; main calculation loop
    ; for(int rcx; rcx < len; rcx++)
    loop_main:
        ; accel(rcx)
        push rcx
        call accel
        
        ; increment and get the next index
        inc rcx
        cmp rcx, rdx
        jl loop_main
    
    
    ; debug: verifications
    ;mov r8, [resptr]
    ;PRINT_DEC 4, [r8]
    ;NEWLINE
    ;PRINT_DEC 4, [r8 + 4]
    
    ; get address as return value to C
    mov rax, [resptr]
	mov rcx, 5
	mov rdx, [matrixptr]
	mov r8, [resptr]
	
    ; return!
    ret

; This function runs the main acceleration
; calculations.
accel:
    ; get index from stack
    mov rax, [rsp+8]
    mov rbx, rax
    ; get addresses from variables
    mov r8, [matrixptr]
    mov r9, [resptr]
    
    ; get the associated values for the index
    imul rax, 3
    movss xmm1, [r8 + rax*4]
    inc rax
    movss xmm2, [r8 + rax*4]
    inc rax
    movss xmm3, [r8 + rax*4]
    
    ; run calculations
    mulss xmm1, [TO_MPH] ; convert, km/h > m/h
    mulss xmm2, [TO_MPH] ; convert, km/h > m/h
    
    subss xmm2, xmm1 ; v = v_f - v_i
    divss xmm2, xmm3 ; a = v/i
    
    ; save to the associated spot in matrix
    ; movss [res + rbx*4], xmm2
    
    ; convert to integer and save
    cvtss2si eax, xmm2
    mov [r9 + rbx*4], eax
    
    ; and return!
    ret 8