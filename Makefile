CXX = g++
CXXFLAGS =  -std=c++11
CXXFLAGS +=   -Wall
CXXFLAGS +=   -pedantic-errors

OBJS =  Street.o Space.o Satan.o Random.o Player.o MusicStore.o Menu.o Map.o LiqourStore.o Item.o iStreet.o iSatan.o Interactive.o iMS.o iLS.o iGig.o iAA.o Helper.o Gig.o Game.o Dead.o AA.o gttg_main.o
SRCS =  Street.cpp Space.cpp Satan.cpp Random.cpp Player.cpp MusicStore.cpp Menu.cpp Map.cpp LiqourStore.cpp Item.cpp iStreet.cpp iSatan.cpp Interactive.cpp iMS.cpp iLS.cpp iGig.cpp iAA.cpp Helper.cpp Gig.cpp Game.cpp Dead.cpp AA.cpp gttg_main.cpp
HEADERS = Street.hpp Space.hpp Satan.hpp Random.hpp Player.hpp MusicStore.hpp Menu.hpp Map.hpp LiqourStore.hpp Item.hpp iStreet.hpp iSatan.hpp Interactive.hpp iMS.hpp iLS.hpp iGig.hpp iAA.hpp Helper.hpp Gig.hpp Game.hpp Dead.hpp AA.hpp

vector: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o gttg

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o gttg
