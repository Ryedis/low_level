section .data
    prompt_size db "Enter array size: ", 0
    error_size db "Error: invalid array size.", 10, 0
    prompt_elements db "Enter array elements:", 0
    error_element db "Error: invalid array element.", 10, 0
    result_msg db "Number of unique elements: %d", 10, 0
    format_int db "%d", 0
    format_short db "%hd", 0
    format_char db "%c", 0

section .bss
    arr resw 100
    arr_size resd 1
    unique_count resd 1
    i resd 1
    j resd 1
    is_unique resb 1
    input resb 20

section .text
    extern printf, scanf, getchar
    global main

main:
    ; Enter array size
    push prompt_size
    call printf
    add esp, 4
    
    push arr_size
    push format_int
    call scanf
    add esp, 8

    cmp dword [arr_size], 0
    jle error_size_input
    cmp dword [arr_size], 100
    jg error_size_input

    ; Enter array elements
    push prompt_elements
    call printf
    add esp, 4

    mov eax, 0
    mov [i], eax

input_loop:
    mov eax, [i]
    cmp eax, [arr_size]
    jge end_input

    mov ebx, arr
    mov edx, eax
    shl edx, 1
    add ebx, edx
    push ebx
    push format_short
    call scanf
    add esp, 8

    ; Check correct input
    cmp eax, 1
    jne error_element_input

    inc dword [i]
    jmp input_loop

error_size_input:
    push error_size
    call printf
    add esp, 4
    jmp end_program

error_element_input:
    push error_element
    call printf
    add esp, 4
    jmp end_program

end_input:
    ; Counting unique elements
    mov eax, 0
    mov [i], eax
    mov [unique_count], eax

count_unique_loop:
    mov eax, [i]
    cmp eax, [arr_size]
    jge end_count

    mov byte [is_unique], 1
    mov ebx, 0
    mov [j], ebx

compare_loop:
    mov eax, [j]
    cmp eax, [i]
    jge end_compare

    ; Comparing the elements arr[i] and arr[j]
    movzx eax, word [arr + eax * 2]
    mov ebx, [i]
    movzx ebx, word [arr + ebx * 2]
    cmp eax, ebx
    jne not_equal

    mov byte [is_unique], 0
    jmp end_compare

not_equal:
    inc dword [j]
    jmp compare_loop

end_compare:
    cmp byte [is_unique], 1
    jne not_unique

    inc dword [unique_count]

not_unique:
    inc dword [i]
    jmp count_unique_loop

end_count:
    mov eax, [unique_count]
    push eax
    push result_msg
    call printf
    add esp, 8

end_program:
    ret
