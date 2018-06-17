all: c p w
c:main.c consumer.c
	$(CC) main.c consumer.c -o c -lpthread


p:mainpro.c producer.c
	$(CC) mainpro.c producer.c -o p -lpthread

w:withmain.c withdraw.c
	$(CC) withmain.c withdraw.c -o w -lpthread

clean:
	rm -f c w p
