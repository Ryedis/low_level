section .data
    prompt_size db "Введите размер массива: ", 0
    prompt_elements db "Введите элементы массива:", 0
    result_msg db "Количество уникальных элементов: ", 0
    arr resw 100

section .bss
    unique_count resd 1
    i resd 1
    j resd 1
    is_unique resb 1

section .text
    extern printf, scanf
    global main

main:
    ; Выводим сообщение для ввода размера массива
    push prompt_size
    call printf
    add esp, 4

    ; Вводим размер массива
    push arr_size
    push format_int
    call scanf
    add esp, 8

    ; Выводим сообщение для ввода элементов массива
    push prompt_elements
    call printf
    add esp, 4

    ; Вводим элементы массива
    mov eax, 0
    mov [i], eax

input_loop:
    mov eax, [i]
    cmp eax, [arr_size]
    jge end_input

    push arr + eax * 2
    push format_short
    call scanf
    add esp, 8

    inc dword [i]
    jmp input_loop

end_input:
    ; Считаем уникальные элементы
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

    ; Сравниваем элементы arr[i] и arr[j]
    movzx eax, word [arr + eax * 2]
    movzx ebx, word [arr + [i] * 2]
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
    ; Выводим результат
    push dword [unique_count]
    push result_msg
    call printf
    add esp, 8

    ; Завершаем программу
    ret