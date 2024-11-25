# bombphase_4_breakpoints.gdb

# Breakpoint 1: At the start of bombphase_4 function
break bombphase_4

# Breakpoint 2: At <+95> - cmp $0x7b3fd988,%rdx - Check comparison of %rdx with 0x7b3fd988
break *0x40178b

# Breakpoint 3: At <+104> - detonate_bomb_now call if comparison fails
break *0x401794

# Breakpoint 4: At <+124> - Check if byte in 0x24(%rsp) equals 0x3b
break *0x4017a8

# Breakpoint 5: At <+126> - detonate_bomb_now call if previous check fails
break *0x4017aa

# Breakpoint 6: At <+146> - Check if word at 0x28(%rsp) is zero
break *0x4017be

# Breakpoint 7: At <+148> - detonate_bomb_now call if previous check fails
break *0x4017c0

# Breakpoint 8: At <+170> - Check if word in 0x26(%rsp) equals 0x2133
break *0x4017d6

# Breakpoint 9: At <+172> - detonate_bomb_now call if previous check fails
break *0x4017d8

# Breakpoint 10: At <+201> - Compare final calculation with 0x4141e54c
break *0x4017f5

# Breakpoint 11: At <+207> - Final comparison result stored in %dl
break *0x4017fb
