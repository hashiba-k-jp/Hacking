# How to debug
# USE lldb INSTEAD OF gdb (MacOS)

gcc firstprog.c
lldb ./a.out

# lldb will start
# and "(lldb)" will appear instead of "%"(zsh)

# ---------- These commands can not be done automatically!! ----------
# (gdb) break main
breakpoint set --name main
# (gdb) run
run
# (gdb) info registers
register read

# And you need "exit" for kill task the lldb