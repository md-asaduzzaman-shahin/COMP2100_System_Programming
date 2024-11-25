def bombphase_3_simulation(input1, input2, input3, input4):
    # Step 1: Initial values (inputs)
    rsi = input1     # First input
    rdx = input2     # Second input
    rcx = input3     # Third input
    r8 = input4      # Fourth input

    # Step 2: Start of bombphase_3 simulation
    # Equivalent to: mov $0x1bd, %eax
    rax = 0x1bd  # 445 in decimal

    # Step 3: Subtract the first input from rax
    # Equivalent to: sub %rsi, %rax
    rax -= rsi  # rax = 445 - input1

    # Step 4: NOT operation on rax
    # Equivalent to: not %rax
    rax = ~rax  # Bitwise NOT operation

    # Step 5: AND operation with 0x11e (286)
    # Equivalent to: and $0x11e, %eax
    rax = rax & 0x11e  # Bitwise AND with 286

    # Step 6: NOT operation on r8 (fourth input)
    # Equivalent to: not %r8
    r8 = ~r8  # Bitwise NOT operation on input4

    # Step 7: XOR rax with r8
    # Equivalent to: xor %r8, %rax
    rax = rax ^ r8  # XOR between rax and r8

    # Step 8: Compare rax with rcx (third input)
    # Equivalent to: cmp %rcx, %rax
    print(rax)
    print(rcx)
    if rax != rcx:
        # Equivalent to: jne detonate_bomb_now
        print("Bomb detonated: rax does not match rcx.")
        return

    # Step 9: Compare rax with -428
    # Equivalent to: cmp $0xfffffffffffffe54, %rax
    if rax == -428:
        # Equivalent to: sete %al (set al to 1 if equal)
        al = 1
    else:
        # Otherwise, al is set to 0
        al = 0

    # Step 10: Output results
    if al == 1:
        print("Bomb defused: Advanced solution succeeded.")
    else:
        print("Bomb detonated: Final comparison failed.")

# Example usage:
input1 = 712  # First input (%rsi)
input2 = 0  # Second input (%rdx)
input3 = -428  # Third input (%rcx)
input4 = 161 # Fourth input (%r8)

bombphase_3_simulation(input1, input2, input3, input4)


