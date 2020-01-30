cc = g++

st : st.o unp.o
	$(cc) -o st st.o unp.o

st.o : st.cpp unp.h
	$(cc) -c st.cpp

unp.o : unp.cpp unp.h
	$(cc) -c unp.cpp

clean :
	rm st st.o unp.o
