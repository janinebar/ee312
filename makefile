final: cheaters_driver.o 
	g++ -o cheaters cheaters_driver.o 
driver: cheaters_driver.cpp
	g++ -c cheaters_driver.cpp