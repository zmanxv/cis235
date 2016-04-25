all: demo-connection demo-create-data demo-read-data demo-update-data demo-delete-data

demo-connection: connection.o 
	g++ -o connection connection.o -L/usr/lib -lmysqlcppconn

demo-connection.o: connection.cpp
	g++ -c -I/usr/include/cppconn connection.cpp

demo-create-data: create_data.o 
	g++ -o create_data create_data.o -L/usr/lib -lmysqlcppconn

demo-create-data.o: create_data.cpp
	g++ -c -I/usr/include/cppconn create_data.cpp

demo-read-data: read_data.o 
	g++ -o read_data read_data.o -L/usr/lib -lmysqlcppconn

demo-read-data.o: read_data.cpp
	g++ -c -I/usr/include/cppconn read_data.cpp

demo-update-data: update_data.o 
	g++ -o update_data update_data.o -L/usr/lib -lmysqlcppconn

demo-update-data.o: update_data.cpp
	g++ -c -I/usr/include/cppconn update_data.cpp

demo-delete-data: delete_data.o 
	g++ -o delete_data delete_data.o -L/usr/lib -lmysqlcppconn

demo-delete-data.o: delete_data.cpp
	g++ -c -I/usr/include/cppconn delete_data.cpp

clean:
	rm -f *.o connection create_data read_data update_data delete_data
