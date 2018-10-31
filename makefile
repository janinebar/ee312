final: utpod_driver.o UtPod.o song.o
	g++ -o utpod utpod_driver.o UtPod.o song.o
driver: utpod_driver.cpp UtPod.h song.h
	g++ -c utpod_driver.cpp
UtPod.o: UtPod.cpp UtPod.h song.h
	g++ -c UtPod.cpp
song.o: song.cpp song.h
	g++ -c song.cpp
