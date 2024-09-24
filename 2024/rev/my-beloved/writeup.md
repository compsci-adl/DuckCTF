### Solution

Take given binary and use disassembler such as Ghidra, IDA, or Binary Ninja
Either follow calls from user input to find comparison routine, or cross reference to where the strings on success or failure are accessed.
In comparison routine, xor function will be called with the given key against a constant. Player can recreate xor routine with key, and call
against the constant value to reveal the flag (the password).
