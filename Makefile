.PHONY: clean all run

S?=2
BP?=2
GH?=2
PH?=2

all: branch

run: branch
	gunzip -c branch-trace-gcc.trace.gz | ./branch -s ${S} -bp ${BP} -gh ${GH} -ph ${PH}

branch: src/main.o
	gcc -o $@ $^

clean:
	rm -Rf src/*.o branch