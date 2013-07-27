Link:
=======
 http://www.kohala.com/start/unpv22e/unpv22e.html

=======



Inter_Process_Communication_Richard_Stevens
===========================================
During compilatio I got the following error:

Error:
========
gcc -c  "/home/linux/Code/c/unix_network_programming/main.c" -g  -o ./Debug/main.o "-I." "-I." 
In file included from /usr/lib/gcc/i686-linux-gnu/4.6/include/stdint.h:3:0,
                 from /usr/include/netinet/in.h:24,
                 from /usr/include/rpc/types.h:91,
                 from /usr/include/rpc/rpc.h:38,
                 from /home/linux/Code/c/unix_network_programming/unpipc.h:115,
                 from /home/linux/Code/c/unix_network_programming/main.c:2:
/usr/include/stdint.h:49:24: error: duplicate ‘unsigned’
/usr/include/stdint.h:49:24: error: two or more data types in declaration specifiers
/usr/include/stdint.h:50:28: error: duplicate ‘unsigned’
/usr/include/stdint.h:50:28: error: duplicate ‘short’
/usr/include/stdint.h:52:23: error: duplicate ‘unsigned’
/usr/include/stdint.h:52:23: error: two or more data types in declaration specifiers

Sol/Workaround
==================
Comment the following lines in /usr/include/stdint.h file

typedef unsigned char     uint8_t; Line 49
typedef unsigned short int    uint16_t; Line 50
typedef unsigned int      uint32_t; Line 52






