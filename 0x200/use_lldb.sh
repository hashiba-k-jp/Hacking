# How to debug
# USE lldb INSTEAD OF gdb (MacOS)
# https://lldb.llvm.org/use/map.html

gcc firstprog.c
lldb ./a.out

# lldb will start
# and "(lldb)" will appear instead of "%"(zsh)

# ---------- These commands can not be done automatically
# when this file is run as shellscript!! ----------

# (gdb) break main
breakpoint set --name main
# (gdb) run
run
# (gdb) info registers
register read

# (dgb) disassemble main
disassemble --name main
# (gdb) i r eip  := (gdb) info register eip
# ip stands for "instruction pointer".
register read rip
# (gdb) examine/x $eip
# check the value of $eip, and get output in hexadecimal(16).
x/x $rip
# (gdb) x/2x $eip
# get groups of data in a row; this example is 2.
x/2x $rip
# (gdb) x/i $eip
# show hex value and its assembla
x/i $rip

# (dgb) nexti
# NEXTInstruction
nexti


# And you need "exit" for kill task the lldb