all: myshell rakam div mul

myshell: myshell.c
	gcc myshell.c -o myshell

rakam: rakam.c
	gcc rakam.c -o rakam

div: div.c
	gcc div.c -o div

mul: mul.c
	gcc mul.c -o mul

