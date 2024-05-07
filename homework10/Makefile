libhomework10.so: homework10.c homework10.h
	gcc -o libhomework10.so -shared -fPIE -I /usr/java/jdk1.8.0_131/include -I /usr/java/jdk1.8.0_131/include/linux -I . homework10.c

homework10.h: homework10.class
	javah homework10

homework10.class: homework10.java
	javac homework10.java

run:
	java -Djava.library.path=. homework10
