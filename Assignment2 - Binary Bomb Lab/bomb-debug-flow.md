```mermaid
flowchart TD
    subgraph Step1["Step 1: Initial Setup"]
        s1reg["Registers:
        rsp = initial
        rbx = not saved yet"]
        s1stack["Stack:
        [rsp] = empty
        [rsp+8] = empty"]
        s1op["Operations:
        push rbx
        sub $0x10, rsp
        
        Effect: 
        - Saves rbx
        - Allocates 16 bytes on stack"]
    end

    subgraph Step2["Step 2: Load Input"]
        s2reg["Registers:
        rbx = input string addr
        rdi → rbx (input string)"]
        s2stack["Stack:
        [rsp] = empty
        [rsp+8] = empty"]
        s2op["Operations:
        mov %rdi, %rbx
        
        Effect:
        - Saves input string pointer"]
    end

    subgraph Step3["Step 3: Load 'thermometer'"]
        s3reg["Registers:
        rax = 0x656d6f6d72656874
        ('thermome')"]
        s3stack["Stack:
        [rsp] = 'thermome'
        [rsp+8] = 'ter\0'"]
        s3op["Operations:
        movabs $0x656d6f6d72656874, %rax
        mov %rax, (%rsp)
        movl $0x726574, 0x8(%rsp)
        
        Effect:
        - Loads 'thermometer' to stack"]
    end

    subgraph Step4["Step 4: String Compare"]
        s4reg["Registers:
        rsi = rsp (target string)
        rdi = rbx (input string)
        edx = 0xb (length 11)"]
        s4op["Operations:
        mov $0xb, %edx
        mov %rsp, %rsi
        call my_strncmp
        
        Effect:
        - Compares 11 bytes"]
        s4cond["Check:
        test %eax, %eax
        jne bomb"]
    end

    subgraph Step5["Step 5: Length Check"]
        s5reg["Registers:
        rbx = input string
        al = comparison result"]
        s5op["Operations:
        cmpb $0x0, 0xb(%rbx)
        je return_zero
        
        If not zero:
        call my_strlen
        cmp $0x1a, %eax
        
        Effect:
        - Checks byte at index 11
        - If not zero, checks total length"]
    end

    Step1 --> Step2
    Step2 --> Step3
    Step3 --> Step4
    Step4 --> Step5

    classDef regbox fill:#f9f,stroke:#333,stroke-width:2px
    classDef stackbox fill:#bbf,stroke:#333,stroke-width:2px
    classDef opbox fill:#bfb,stroke:#333,stroke-width:2px
    classDef condbox fill:#ffb,stroke:#333,stroke-width:2px
    
    class s1reg,s2reg,s3reg,s4reg,s5reg regbox
    class s1stack,s2stack,s3stack stackbox
    class s1op,s2op,s3op,s4op,s5op opbox
    class s4cond condbox
