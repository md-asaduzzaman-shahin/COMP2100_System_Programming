def reverse_engineer_bomb_phase():
    # Step 8 Reverse: We know the final `rax` must be -428
    target_rax = -428

    # Step 7 Reverse: XOR with ~r8
    # We need to find a value of r8 such that after XOR with target_rax, 
    # we get a valid intermediate value that fits the constraints in Step 5.
    for potential_r8 in range(-1000, 1000):
        r8 = ~potential_r8  # Applying NOT to simulate `not %r8` in assembly
        intermediate_rax = target_rax ^ r8  # Reverse the XOR with r8

        # Step 5 Reverse: Ensure this value fits `rax & 0x11e` constraint
        if (intermediate_rax & 0x11e) == intermediate_rax:
            # Step 4 Reverse: Apply NOT to get the pre-NOT value
            pre_not_rax = ~intermediate_rax  # Undo the NOT operation on rax

            # Step 3 Reverse: Calculate `rsi` based on the original subtraction
            # rax = 445 - rsi should equal pre_not_rax
            input1_rsi = 445 - pre_not_rax  # Solve for `rsi` (input1)

            # Step 6: rcx needs to match the final target_rax for bomb defusal
            input3_rcx = target_rax  # We need rcx = rax for defusal

            # If this setup satisfies all conditions, we have our solution
            print(f"Values to defuse the bomb:")
            print(f"rsi (input1): {input1_rsi}")
            print(f"r8  (input4): {potential_r8}")
            print(f"rcx (input3): {input3_rcx}")
            return input1_rsi, input3_rcx, potential_r8

    print("No solution found in the given range.")
    return None

# Call the reverse engineering function
input1, input3, input4 = reverse_engineer_bomb_phase()

# Assuming rdx (input2) doesn't affect the outcome, we can set it arbitrarily
input2 = 0  # Arbitrary value for input2 as it does not affect rax

# Display the inputs for defusing
print(f"Generated inputs for defusal:\ninput1: {input1}, input2: {input2}, input3: {input3}, input4: {input4}")
