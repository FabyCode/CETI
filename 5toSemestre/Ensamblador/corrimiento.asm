INICIO: MOV P1, #01H
; Selección de las secuencias
A1: MOV R6, P3
CJNE R6, #1H, A2
LCALL SECUENCIA1
A2: CJNE R6, #3H, A3
LCALL SECUENCIA2
A3: CJNE R6, #7H, A4
LCALL SECUENCIA3
A4: CJNE R6, #0FH, A1
LCALL SECUENCIA4
; Secuencia 1 (muestra los bits acumulando de 2 en 2)
SECUENCIA1: MOV P1, #01H
MOV A, P1
MOV R7, #08H
ESTO: RL A
MOV P1, A
MOV R0, #08H
LCALL Retardo
DJNZ R7, ESTO
JMP INICIO
; Secuencia 2 (muestra los bits cada 2 en 2)
SECUENCIA2: MOV P1, #01H
MOV P1, #01H
MOV P1, #02H
LCALL Retardo
MOV P1, #04H
MOV P1, #08H
LCALL Retardo
MOV P1, #10H
MOV P1, #20H
LCALL Retardo
MOV P1, #40H
MOV P1, #80H
LCALL Retardo
JMP INICIO
; Secuencia 3 (Muestra los números impares)
SECUENCIA3: MOV P1, #01H
LCALL Retardo
MOV P1, #00H
LCALL Retardo
MOV P1, #01H
LCALL Retardo
MOV P1, #04H
LCALL Retardo
MOV P1, #10H
LCALL Retardo
MOV P1, #20H
LCALL Retardo
MOV P1, #40H
JMP INICIO
; Secuencia 4
SECUENCIA4: MOV P1, #01H
LCALL Retardo
MOV P1, #00H
LCALL Retardo
MOV P1, #09H
LCALL Retardo
MOV P1, #00H
LCALL Retardo
MOV P1, #01H
LCALL Retardo
MOV P1, #00H
LCALL Retardo
MOV P1, #81H
LCALL Retardo
MOV P1, #00H
LCALL Retardo
MOV P1, #01H
LCALL Retardo
MOV P1, #00H
LCALL Retardo
MOV P1, #90H
LCALL Retardo
MOV P1, #00H
LCALL Retardo
MOV P1, #99H
LCALL Retardo
MOV P1, #00H
JMP INICIO
; Subrutina o función de retardo
Retardo: MOV R0, #08H
PACA: MOV R1, #0FAH
ACA: MOV R2, #0FAH
AQUI: DJNZ R2, AQUI
DJNZ R1, ACA
DJNZ R0, PACA
RET
END