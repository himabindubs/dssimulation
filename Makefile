project: drawlist.o menu.o stack.o drawstack.o queue.o drawqueue.o listmenu.o  
	cc menu.o stack.o drawstack.o queue.o drawqueue.o listmenu.o drawlist.o -o project -lncurses 

menu.o: menu.c
	cc -c menu.c -lncurses
stack.o: stack.c
	cc -c stack.c drawstack.c -lncurses
queue.o: queue.c
	cc -c queue.c drawqueue.c -lncurses
drawstack.o: drawstack.c
	cc -c drawstack.c -menu.c -lncurses
drawqueue.o: drawqueue.c
	cc -c drawqueue.c menu.c -lncurses		
drawlist.o: drawlist.c
	cc -c drawlist.c listmenu.c -lncurses
listmenu.o: listmenu.c
	cc -c listmenu.c drawlist.c menu.c -lncurses
												
