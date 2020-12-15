main.out : main.cpp librarian.cpp user.cpp book.cpp
	g++ main.cpp librarian.cpp user.cpp book.cpp -o main.out -std=c++14

clean:
	rm main.out
