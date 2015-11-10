#bulid a Makefile for auto_channel_allocation.c
auto_channel_allocation: auto_channel_allocation.o
	$(CC) $(LDFLAGS) auto_channel_allocation.o -o auto_channel_allocation
auto_channel_allocation.o: auto_channel_allocation.c
	$(CC) $(CFLAGS) -c auto_channel_allocation.c
clean:
	rm *.o auto_channel_allocation
