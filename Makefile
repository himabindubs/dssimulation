list.o: list.c
	cc -c list.c
try: miniproject.c
	cc -c miniproject.c 
stackint.o: stackint.c
	cc -c stackint.c
stackchar.o: stackchar.c
	cc -c stackchar.c
queueint.o: queueint.c
	cc -c queueint.c
queuechar.o: queuechar.c
	cc -c queuechar.c
listint.o: listint.c
	cc -c listint.c
listchar.o: listchar.c
	cc -c listchar.c
all: try	
miniproject.o: list.c miniproject.c stackint.c stackchar.c queueint.c queuechar.c listint.c listchar.c 
	cc -c list.c miniproject.c stackint.c stackchar.c queueint.c queuechar.c listint.c listchar.c 	
											
