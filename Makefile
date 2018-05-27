.PHONY:clean
bloomfilter:bloomfilter.c bitmap.c HashFun.c
	gcc -g -o $@ $^
clean:
	rm -f bloomfilter
