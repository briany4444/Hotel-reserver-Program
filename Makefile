resManager: main.o Control.o Date.o Guest.o Hotel.o Reservation.o Recorder.o ResManager.o View.o Room.o RoomArray.o
	g++ -o resManager main.o Control.o Date.o Guest.o Hotel.o Reservation.o Recorder.o ResManager.o View.o Room.o RoomArray.o

main.o: main.cc
	g++ -c main.cc

Control.o: Control.cc Control.h
	g++ -c Control.cc

Date.o:	Date.cc Date.h
	g++ -c Date.cc

Guest.o: Guest.cc Guest.h
	g++ -c Guest.cc

Hotel.o: Hotel.cc Hotel.h
	g++ -c Hotel.cc

Reservation.o: Reservation.cc Reservation.h
	g++ -c Reservation.cc

Recorder.o: Recorder.cc Recorder.h
	g++ -c Recorder.cc

ResManager.o: ResManager.cc ResManager.h
	g++ -c ResManager.cc

View.o: View.cc View.h
	g++ -c View.cc

Room.o: Room.cc Room.h
	g++ -c Room.cc

RoomArray.o: RoomArray.cc RoomArray.h
	g++ -c RoomArray.cc

clean:
	rm -f resManager main.o Control.o Date.o Guest.o Hotel.o Reservation.o Recorder.o ResManager.o View.o Room.o RoomArray.o
