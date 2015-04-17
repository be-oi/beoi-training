CPPFLAGS=-g -Wextra -Wall -O2
default: check
debug: a.out
	gdb a.out -ex "set args ${DEBUG_ARGS}"
run: a.out
	./a.out ${RUN_ARGS}
a.out: main.cpp
	$(CXX) $(CPPFLAGS) main.cpp
db: a.out
	bash $(TOOLPATH)/db.sh
check: a.out
	bash $(TOOLPATH)/check.sh
add:
	bash $(TOOLPATH)/add.sh
clean:
	$(RM) *.o
	$(RM) a.out
