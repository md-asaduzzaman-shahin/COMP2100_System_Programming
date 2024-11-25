def simulate_strcat(stack, dest_offset, src_string):
    # Find the null terminator in the destination
    dest_index = dest_offset
    while dest_index < len(stack) and stack[dest_index] != 0:
        dest_index += 1
    # Copy source string into destination
    for c in src_string:
        if dest_index >= len(stack):
            break  # Prevent overflow in simulation
        stack[dest_index] = ord(c)
        dest_index += 1
    # Add null terminator at the end
    if dest_index < len(stack):
        stack[dest_index] = 0

# Initialize the stack with enough space
stack = bytearray(0x50)  # Stack size (adjusted for simulation)

# Initialize 'met\0' at offset 0 (corresponding to 0x10(%rsp))
stack[0:4] = b'met\0'

# Initialize byte at offset 0x14 (0x24(%rsp) - 0x10(%rsp)) to 0x0d
stack[0x14] = 0x0d

# Craft the input string
input_string = 'A' * 17 + ';'  # 17 'A's followed by ';'

# Simulate strcat operation
simulate_strcat(stack, dest_offset=0, src_string=input_string)

# Check the value at 0x14 (0x24(%rsp))
byte_at_0x14 = stack[0x14]
print(f"Byte at 0x14 (should be 0x3b): {hex(byte_at_0x14)}")

# Verify if the byte at 0x14 is indeed 0x3b (';')
if byte_at_0x14 == 0x3b:
    print("Success: The byte at 0x24(%rsp) is ';' (0x3b).")
else:
    print("Failure: The byte at 0x24(%rsp) is not ';'.")

# Output the full concatenated string for verification
concatenated_string = stack[:].split(b'\x00', 1)[0].decode('ascii', errors='ignore')
print(f"Concatenated string: {concatenated_string}")
