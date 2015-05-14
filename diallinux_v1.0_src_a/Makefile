OBJS =  MD5.o CString.o CXKUsername.o dail.o
CC = g++
CFLAGS = -Wall -g   

dialnetkeeper:$(OBJS)
	$(CC) $(OBJS) -o dialnetkeeper 

.PHONY:clean 
clean:
	-rm dialnetkeeper *.o
