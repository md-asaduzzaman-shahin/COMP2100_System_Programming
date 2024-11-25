# bombphase_5_breakpoints.gdb

# Breakpoint 1: At the start of bombphase_5 function
break bombphase_5

# Breakpoint 2: At <+10> - Check if %al is zero to decide if it should jump to the end
break *0x4016a3

# Breakpoint 3: At <+47> - Check if %sil (8-bit part of %esi) is greater than 0x33
break *0x4016c8

# Breakpoint 4: At <+67> - detonate_bomb_now call if comparison at <+63> fails
break *0x4016dc

# Breakpoint 5: At <+93> - Jump if %al is non-zero, looping back in bombphase_5
break *0x4016f6

# Breakpoint 6: At <+98> - Check if byte in (%rdi) equals 0x0
break *0x4016fb

# Breakpoint 7: At <+100> - detonate_bomb_now call if previous check fails
break *0x4016fd

# Breakpoint 8: At <+125> - Compare %ecx with 0x689
break *0x401716

# Breakpoint 9: At <+130> - Calculate the difference between %rdx and %r9
break *0x40171b

# Breakpoint 10: At <+134> - Check if the difference in %rdx equals 0x9
break *0x40171f

# Breakpoint 11: At <+140> - End of bombphase_5 function
break *0x401725
