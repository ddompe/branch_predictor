.PHONY: clean all run

S?=16
BP?=0
GH?=5
PH?=3

hello:
	echo HELLO WORLD

all: branch

run: branch
	gunzip -c branch-trace-gcc.trace.gz | ./branch -s ${S} -bp ${BP} -gh ${GH} -ph ${PH}

branch: src/main.o src/bimodal.o
	gcc -o $@ $^

clean:
	rm -Rf src/*.o branch
