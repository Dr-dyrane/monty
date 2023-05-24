++++++++++             ; Set the value of the first cell to 10 (the ASCII value of 'S')
[
    >+++++++          ; Increment the next cell to set its value to the ASCII value of 'c'
    >++++++++++       ; Increment the following cell to set its value to the ASCII value of 'h'
    >+++              ; Increment the next cell to set its value to the ASCII value of 'o'
    >+                ; Increment the final cell to set its value to the ASCII value of 'o'
    <<<<-             ; Decrement the pointer to return to the first cell
]
>>.                     ; Print 'S'
>+.                     ; Print 'c'
+++++++.                ; Print 'h'
+++.                    ; Print 'o'
>.                      ; Print the second 'o'
<<+++++++++++++++.      ; Print 'l'
>.                      ; Print the final 'l'
+++.                    ; Print the new line character
