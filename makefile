all:
	gcc -o garage -DGARAGE_SIZE=5 src/garage.c -Iincludes
	
five:
	gcc -o garage -DGARAGE_SIZE=5 src/garage.c -Iincludes
	
ten:
	gcc -o garage -DGARAGE_SIZE=10 src/garage.c -Iincludes